
typedef struct Image {
  unsigned char *data;
  int n; // number of channels
  int x; // width
  int y; // height
} Image;

typedef unsigned char pixel;

extern unsigned char getChannel(Image* image, int x, int y, int ch);

extern void setChannel(Image* image, int x, int y, int ch, unsigned char value);


/*
	iterates through each pixels and applies a custom pixel filter
	function will be provided with a pointer to current pixel
	make sure not to touch neighbouring pixels to avoid segfault
	
*/
extern void pixelwice(Image* image, unsigned char* output, void(*func)(unsigned char*, unsigned char*, int*), int* args);
