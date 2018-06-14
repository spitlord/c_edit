
typedef struct Image {
  unsigned char *data;
  int n; // number of channels
  int x; // width
  int y; // height
} Image; 



extern unsigned char getChannel(Image* image, int x, int y, int ch);

extern void setChannel(Image* image, int x, int y, int ch, unsigned char value);


/*
	iterates through each pixels and applies a custom pixel filter
	function will be provided with a pointer to current pixel
	make sure not to touch neighbouring pixels to avoid segfault
	
*/
extern void pixelwice(Image* image, void(*func)(unsigned char*));
