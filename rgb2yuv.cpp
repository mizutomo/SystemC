#include "rgb2yuv.h"

void rgb2yuv::thread0()
{
  rgb8_t offset;
  offset = offset_in.read();

  while(true) {
    rgb = rgb_in.read();
    rgb = offset + rgb;
    yuv = calc_rgb2yuv(rgb);
    yuv_out.write(yuv);
  }
}

yuv8_t rgb2yuv::calc_rgb2yuv(rgb8_t& rgb)
{
  yuv8_t yuv;

  yuv.y = (rgb.r*77 + rgb.g*151 + rgb.b*29) / 256;
  yuv.u = (rgb.r*(-43) - rgb.g*85 + rgb.b*128) / 256 + 128;
  yuv.v = (rgb.r*128 - rgb.g*107 - rgb.b*21) / 256 + 128;

  cout << "rgb=" << rgb << " yuv=" << yuv << endl;
  return yuv;
}

