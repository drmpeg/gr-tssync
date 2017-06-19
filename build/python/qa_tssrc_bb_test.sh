#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/pi/mux_dev/gr-tssrc/python
export PATH=/home/pi/mux_dev/gr-tssrc/build/python:$PATH
export LD_LIBRARY_PATH=/home/pi/mux_dev/gr-tssrc/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=/home/pi/mux_dev/gr-tssrc/build/swig:$PYTHONPATH
/usr/bin/python2 /home/pi/mux_dev/gr-tssrc/python/qa_tssrc_bb.py 
