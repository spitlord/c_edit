#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../lib/stb/stb_image.h"
#include "../lib/stb/stb_image_write.h"
#include <stdio.h>
#include <stdlib.h>
#include <getPixels.h>




int main(int argc, char**args) {
  Image image;
  
    
  char* ext;

  

  if ((image.data = stbi_load(args[1], &image.x, &image.y, &image.n, 0)) == NULL) {
    printf("ERROR OPENING IMAGE FILE");
    return -1;
  }
    
  ext = NULL;

  ext = strchr(args[1], '.');
  
  if ( strcmp(ext, "jpg") == 0 )  { }
  else if (strcmp(ext, "png") == 0 )  { }
  else if (strcmp(ext, "j") == 0 )  { }
  else if (strcmp(ext, "jpg") == 0 )  { }
  else if (strcmp(ext, "jpg") == 0 )  { }

  
  printf("x = %d, y = %d \n", image.x, image.y);
    
  /*
  for (int i = 0; i < x*2; i++) {
    for (int j = 0; j < y; j++) {
      for (int k = 0; k < 3; k++) {
	*(data + (i*x + j*3) + k) = (100+ 60*k + i)%255;
	if (i> x/2) {*(data + }
      }
    }
  }
  */

  /*
  
  for (int i = 0; i < x*y*3; i++) {
    if (i%3 == 0) *(data+i) =  *(data+i)*i%255;
    else if(i%3 == 1) *(data+i) = *(data+i-1) * (*(data+i+1)) / 20 % 255;
    else *(data+i) = *(data+i-1)*(*(data+i-2))%255;
  }

  */
     /* for (int i = 0; i < x; i++) { */
     /*  for ( int j = 0; j < y; j++) { */
     /* 	for (int ch  = 0; ch < 3; ch ++) */
     /* 	  *(data + 3*(i*x + j) + ch) = 0; */
     /* 	//	printf("all is good until it's not \n"); */
     /*  } */
 
  
  /* for (int i = 0; i < image.x * image.y * 3; i++) { */
  /*   *(image.data + i) = 0; */
  /* } */
  
 // printf("rgb: %d", setChannel(&image, 4000, 500, 2, 3));
   setChannel(&image, 4000, 500, 2, 3);
  
     
    if (!stbi_write_jpg(args[2], image.x, image.y, 3, image.data, 30))
    printf("ERROR WRITING FILE\n");
    
 
  stbi_image_free(image.data);
  
  return 0;
}
