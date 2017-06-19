/* 
 * Matt Zachary
 * 6/16/2017
 * Rochester Institute of Technology
 * TS provider, from named pipe, with null insertion
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "tssrc_bb_impl.h"
#include <stdio.h>

namespace gr {
  namespace tssrc {

    tssrc_bb::sptr
    tssrc_bb::make(const char *filename)
    {
      return gnuradio::get_initial_sptr
        (new tssrc_bb_impl(filename));
    }

    /*
     * The private constructor
     */
    tssrc_bb_impl::tssrc_bb_impl(const char *filename)
      : gr::block("tssrc_bb",
              gr::io_signature::make(0, 0, sizeof(unsigned char)),
              gr::io_signature::make(1, 1, sizeof(unsigned char)))
    {
      file = open(filename , O_RDONLY | O_NONBLOCK);
      set_output_multiple(MPEG_TS_PKT_LENGTH * 100);
    }

    /*
     * Our virtual destructor.
     */
    tssrc_bb_impl::~tssrc_bb_impl()
    {
    }

    void
    tssrc_bb_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      ninput_items_required[0] = noutput_items;
    }

    int
    tssrc_bb_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      // Null Packet array
      unsigned char null_pkt[188] = {0x47, 0x1f, 0xff, 0x10, \
                                     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
                                     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
                                     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
                                     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
                                     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
                                     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
                                     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
                                     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
                                     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
                                     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
                                     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
                                     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
                                     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
                                     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
                                     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
                                     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
                                     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
                                     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
                                     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
                                     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
                                     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
                                     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
                                     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

      // Used to store data read in from file
      unsigned char inbuffer[188];

      // Out pointer
      unsigned char *out = (unsigned char *) output_items[0];
    
      // Status bit to know if we're sending null or data; other vars
      int sending_null = 1;
      int num_read = 0;
      unsigned int produced = 0;

      for (int i = 0; i < noutput_items; i++)
      {
        // Re-evaluate every 188 bytes
        if (i%188 == 0)
        {
          num_read = read(file, inbuffer, 188);

          // Found data in the file
          if (num_read == 188)
          {
            sending_null = 0;
          }
          // No data, send a null packet
          else
          {
            sending_null = 1;
          }
        }

        // Send the next null packet
        if (sending_null == 1)
        {
          *out = null_pkt[i%188];
        }
        // Send the next data packet
        else
        {
          *out = inbuffer[i%188];
        }

        out++;
        produced++;
      } /* for loop */

      // Tell runtime system how many input items we consumed on
      // each input stream.
      consume_each (noutput_items);

      // Tell runtime system how many output items we produced.
      return produced;
    }

  } /* namespace tssrc */
} /* namespace gr */

