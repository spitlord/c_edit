#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#define QUALITY 40
#define NUMBER_OUTPUT 0x400

#include "../lib/stb/stb_image.h"
#include "../lib/stb/stb_image_write.h"
#include <stdio.h>
#include <stdlib.h>
#include <filters.h>


int main(int argc, char**argv) {
  char* name = malloc(300);

  Image image; // struct that holds the pixels
  
  // try opening file
  if ((image.data = stbi_load(argv[1], &image.x, &image.y, &image.n, 0)) == NULL) {
    printf("ERROR OPENING IMAGE FILE");
    return -1;
  }
  printf("Opened %s:x = %d, y = %d \n", argv[1], image.x, image.y);


  for (int i = 0; i < NUMBER_OUTPUT; i++) {
    printf("\33[2K\r%d",i);
    fflush(stdout);
    char frequency = i % 0x100;
    Image* outputImage = filter(&image, &frequency);


  
    sprintf(name, "%s%05d.jpg", argv[2], i);
    if (!stbi_write_jpg(name, outputImage->x, outputImage->y, outputImage->n, outputImage->data, QUALITY)){
	    printf("ERROR WRITING FILE\n");
	    return -1;
    }

    free(outputImage->data);
    free(outputImage);
  }

  free(name);
  stbi_image_free(image.data);
  
  printf("\33[2K\r%d\n",NUMBER_OUTPUT);
  return 0;
}

