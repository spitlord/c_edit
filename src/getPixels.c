#include <getPixels.h>



extern unsigned char getChannel(Image* image, int x, int y, int ch){
  return *(image->data + (image->y * x + y)*3 + ch);
}



extern void setChannel(Image* image, int x, int y, int ch, unsigned char value) {
  *(image->data + (image->y * x + y)*3 + ch) = value;
}

extern void pixelwice(Image* image, unsigned char* output, void(*func)(unsigned char*, unsigned char*, int*), int* args) {
  int temp;
    for(int i = 0; i < image->x; i++) {
      for(int j = 0; j < image->y; j++) {
	temp = 3 * (i * image->y + j);
	func(image->data + temp,  output + temp, args);
      }
    }
  }
