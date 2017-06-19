#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/pi/mux_dev/gr-tssrc/lib
export PATH=/home/pi/mux_dev/gr-tssrc/build/lib:$PATH
export LD_LIBRARY_PATH=/home/pi/mux_dev/gr-tssrc/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=$PYTHONPATH
test-tssrc 
