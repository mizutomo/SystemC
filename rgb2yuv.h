#ifndef __RGB2YUV_H__
#define __RGB2YUV_H__

#include <systemc.h>
#include "class.h"

SC_MODULE(rgb2yuv) {
  sc_in<bool> clock;
  sc_fifo_in<rgb8_t> offset_in;
  sc_fifo_in<rgb8_t> rgb_in;
  sc_fifo_out<yuv8_t> yuv_out;

  void thread0();
  yuv8_t calc_rgb2yuv(rgb8_t& rgb);

  rgb8_t rgb;
  yuv8_t yuv;

  SC_CTOR(rgb2yuv) {
    SC_THREAD(thread0);
    sensitive << clock.pos();
  }
};

#endif

