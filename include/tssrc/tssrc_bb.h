/* 
 * Copyright 2017 Matt Zachary
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

#ifndef INCLUDED_TSSRC_TSSRC_BB_H
#define INCLUDED_TSSRC_TSSRC_BB_H

#include <tssrc/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace tssrc {

    class TSSRC_API tssrc_bb : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<tssrc_bb> sptr;

      static sptr make(const char* filename);
    };

  } // namespace tssrc
} // namespace gr

#endif

