#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define QUALITY 30
#include "../lib/stb/stb_image.h"
#include "../lib/stb/stb_image_write.h"
#include <stdio.h>
#include <stdlib.h>
#include <getPixels.h>


void de(unsigned char * p) {
  *(p+1) = (*p) * (*p) % 255 ;
  *(p+2) =  (*(p+2)) * (*(p+2)) % 255;
}


int main(int argc, char**args) {
  

  Image image; // struct that holds the pixels
  
  // try opening file
  if ((image.data = stbi_load(args[1], &image.x, &image.y, &image.n, 0)) == NULL) {
    printf("ERROR OPENING IMAGE FILE");
    return -1;
  }


  // later to work with other extentions
  char* ext;
  ext = NULL;
  ext = strchr(args[1], '.');
  
  if ( strcmp(ext, "jpg") == 0 )  { }
  else if (strcmp(ext, "png") == 0 )  { }
  else if (strcmp(ext, "j") == 0 )  { }
  else if (strcmp(ext, "jpg") == 0 )  { }
  else if (strcmp(ext, "jpg") == 0 )  { }
  

  printf("x = %d, y = %d \n", image.x, image.y);
  
      
  pixelwice(&image, de); 
     

    if (!stbi_write_jpg(args[2], image.x, image.y, 3, image.data, QUALITY))
    printf("ERROR WRITING FILE\n");
    
 
  stbi_image_free(image.data);
  
  return 0;
}
