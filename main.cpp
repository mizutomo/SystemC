#include <systemc.h>
#include "class.h"
#include "tb.h"
#include "rgb2yuv.h"

int sc_main(int argc, char* argv[])
{
  sc_clock clock("clock", 10, SC_NS, 0.5, 0, SC_NS, false);

  sc_fifo<rgb8_t> offset;
  sc_fifo<rgb8_t> rgb;
  sc_fifo<yuv8_t> yuv;

  rgb2yuv i0("rgb2yuv");
  tb t0("tb");

  i0.clock(clock);
  i0.offset_in(offset);
  i0.rgb_in(rgb);
  i0.yuv_out(yuv);

  t0.clock(clock);
  t0.offset_out(offset);
  t0.rgb_out(rgb);
  t0.yuv_in(yuv);

  sc_start();
  return 0;
}
