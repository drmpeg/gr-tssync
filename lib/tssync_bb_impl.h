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

#ifndef INCLUDED_TSSYNC_TSSYNC_BB_IMPL_H
#define INCLUDED_TSSYNC_TSSYNC_BB_IMPL_H

#include <tssync/tssync_bb.h>

#define TRUE 1
#define FALSE 0
#define MPEG_TS_PKT_LENGTH 188
#define MPEG_TS_SYNC_BYTE 0x47

namespace gr {
  namespace tssync {

    class tssync_bb_impl : public tssync_bb
    {
     private:
      unsigned int synced;
      unsigned int count;

     public:
      tssync_bb_impl();
      ~tssync_bb_impl();

      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
    };

  } // namespace tssync
} // namespace gr

#endif /* INCLUDED_TSSYNC_TSSYNC_BB_IMPL_H */

