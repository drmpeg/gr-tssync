/* -*- c++ -*- */

#define TSSYNC_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "tssync_swig_doc.i"

%{
#include "tssync/tssync_bb.h"
%}


%include "tssync/tssync_bb.h"
GR_SWIG_BLOCK_MAGIC2(tssync, tssync_bb);
