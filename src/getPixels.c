#include <getPixels.h>

extern unsigned char getChannel(Image* image, int x, int y, int ch){
  return *(image->data + (image->y * x + y)*3 + ch);
}

extern void setChannel(Image* image, int x, int y, int ch, unsigned char value) {
  *(image->data + (image->y * x + y)*3 + ch) = value;
}