/* 
 * Matt Zachary
 * 6/16/2017
 * Rochester Institute of Technology
 * TS provider, from named pipe, with null insertion
 */

#ifndef INCLUDED_TSSRC_TSSRC_BB_IMPL_H
#define INCLUDED_TSSRC_TSSRC_BB_IMPL_H

#include <tssrc/tssrc_bb.h>
#include <fcntl.h>

#define TRUE 1
#define FALSE 0
#define MPEG_TS_PKT_LENGTH 188
#define MPEG_TS_SYNC_BYTE 0x47

namespace gr {
  namespace tssrc {

    class tssrc_bb_impl : public tssrc_bb
    {
     private:
      int file;
      
     public:
      tssrc_bb_impl(const char* filename);
      ~tssrc_bb_impl();

      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
    };

  } // namespace tssrc
} // namespace gr

#endif
