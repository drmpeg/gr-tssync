/* -*- c++ -*- */

#define TSSRC_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "tssrc_swig_doc.i"

%{
#include "tssrc/tssrc_bb.h"
%}


%include "tssrc/tssrc_bb.h"
GR_SWIG_BLOCK_MAGIC2(tssrc, tssrc_bb);
