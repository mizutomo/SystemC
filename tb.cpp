#include "tb.h"

#define NUM 20

void tb::source()
{
  int data_r, data_g, data_b;
  rgb8_t rgb;

  fscanf(fi, "%d", &data_r);
  fscanf(fi, "%d", &data_g);
  fscanf(fi, "%d", &data_b);

  rgb.write(data_r, data_g, data_b);

  offset_out.write(rgb);
  wait();

  for (int i = 0; i < NUM; i++) {
    fscanf(fi, "%d", &data_r);
    fscanf(fi, "%d", &data_g);
    fscanf(fi, "%d", &data_b);

    rgb.write(data_r, data_g, data_b);

    rgb_out.write(rgb);
    wait();
  }
}

void tb::sink()
{
  yuv8_t yuv;
  fprintf(fo, "  y  u  v\n");

  for (int i = 0; i < NUM; i++) {
    yuv = yuv_in.read();
    fprintf(fo, "%3d %3d %3d\n", (int)yuv.y, (int)yuv.u, (int)yuv.v);
    wait();
  }

  sc_stop();
}
