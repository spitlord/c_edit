#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define QUALITY 40
#include "../lib/stb/stb_image.h"
#include "../lib/stb/stb_image_write.h"
#include <stdio.h>
#include <stdlib.h>
#include <getPixels.h>


void de(unsigned char * in, unsigned char* out, int* args) {
  *out = (*in) * (*args) % 255;
  *(out+1) = *(in+1) * (*(args+1)) % 255;
  *(out+2) = *(in+2) * (*(args+2)) % 255;
}



int main(int argc, char**argv) {

   char* name = malloc(30);

  

  Image image; // struct that holds the pixels
  
  // try opening file
  if ((image.data = stbi_load(argv[1], &image.x, &image.y, &image.n, 0)) == NULL) {
    printf("ERROR OPENING IMAGE FILE");
    return -1;
  }
  int imageSize =  image.x * image.y * image.n;
  unsigned char* outputImage;
  for (int i = 0, max = 100; i < max; i++) {
    outputImage = malloc(imageSize);
  // later to work with other extentionsx
  char* ext;
  ext = NULL;
  ext = strchr(argv[1], '.');
  
  if ( strcmp(ext, "jpg") == 0 )  { }
  else if (strcmp(ext, "png") == 0 )  { }
  else if (strcmp(ext, "j") == 0 )  { }
  else if (strcmp(ext, "jpg") == 0 )  { }
  else if (strcmp(ext, "jpg") == 0 )  { }
  

  printf("x = %d, y = %d \n", image.x, image.y);
  
  int* args = malloc(sizeof(int) * 3);
  int temp = i;
    *args = temp % 10;
    temp/=10;
    
    *(args+1) = temp % 10;
    temp/=10;

    *(args+2) = temp % 10;
   
    pixelwice(&image, outputImage, de, args); 
     
    free(args);
    
    sprintf(name, "%s%d.jpg", argv[2], i); 
    if (!stbi_write_jpg(name, image.x, image.y, 3, outputImage, QUALITY))
    printf("ERROR WRITING FILE\n");
free(outputImage);
  }
  

  stbi_image_free(image.data);
  
  return 0;
}

