#ifndef __TB_H__
#define __TB_H__

#include <systemc.h>
#include "class.h"

#define INPUT_FILE "input.dat"
#define OUTPUT_FILE "output.dat"

SC_MODULE(tb) {
  sc_in<bool> clock;
  sc_fifo_out<rgb8_t> offset_out;
  sc_fifo_out<rgb8_t> rgb_out;
  sc_fifo_in<yuv8_t> yuv_in;

  FILE* fi;
  FILE* fo;

  void source();
  void sink();

  SC_CTOR(tb) {
    if ((fi = fopen(INPUT_FILE, "r")) == NULL) {
      fprintf(stderr, "Can't open file: %s\n", INPUT_FILE);
      sc_stop();
    }
    if ((fo = fopen(OUTPUT_FILE, "w")) == NULL) {
      fprintf(stderr, "Can't open file: %s\n", OUTPUT_FILE);
      sc_stop();
    }

    SC_THREAD(source);
    sensitive << clock.pos();
    SC_THREAD(sink);
    sensitive << clock.pos();
  }

  ~tb() {
    fclose(fi);
    fclose(fo);
  }
};

#endif
