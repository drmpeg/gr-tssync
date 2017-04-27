/* -*- c++ -*- */
/* 
 * Copyright 2017 Ron Economos.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "tssync_bb_impl.h"
#include <stdio.h>

namespace gr {
  namespace tssync {

    tssync_bb::sptr
    tssync_bb::make()
    {
      return gnuradio::get_initial_sptr
        (new tssync_bb_impl());
    }

    /*
     * The private constructor
     */
    tssync_bb_impl::tssync_bb_impl()
      : gr::block("tssync_bb",
              gr::io_signature::make(1, 1, sizeof(unsigned char)),
              gr::io_signature::make(1, 1, sizeof(unsigned char)))
    {
      synced = FALSE;
      count = 0;
      set_output_multiple(MPEG_TS_PKT_LENGTH * 100);
    }

    /*
     * Our virtual destructor.
     */
    tssync_bb_impl::~tssync_bb_impl()
    {
    }

    void
    tssync_bb_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      ninput_items_required[0] = noutput_items;
    }

    int
    tssync_bb_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const unsigned char *in = (const unsigned char *) input_items[0];
      unsigned char *out = (unsigned char *) output_items[0];
      unsigned int produced = 0;

      for (int i = 0; i < noutput_items; i++) {
        if (synced == FALSE) {
          if (*in == MPEG_TS_SYNC_BYTE) {
            *out++ = *in++;
            produced++;
            synced = TRUE;
            count = 1;
            printf("TS sync found!\n");
          }
          else {
            in++;
          }
        }
        else {
          *out++ = *in++;
          produced++;
          count++;
          if (count == MPEG_TS_PKT_LENGTH) {
            count = 0;
            if (*in != MPEG_TS_SYNC_BYTE) {
              synced = FALSE;
              printf("TS sync lost!\n");
            }
          }
        }
      }

      // Tell runtime system how many input items we consumed on
      // each input stream.
      consume_each (noutput_items);

      // Tell runtime system how many output items we produced.
      return produced;
    }

  } /* namespace tssync */
} /* namespace gr */

