typedef struct Image {
  unsigned char *data;
  int n;
  int x;
  int y;
} Image;


extern unsigned char getChannel(Image* image, int x, int y, int ch);

extern void setChannel(Image* image, int x, int y, int ch, unsigned char value);

