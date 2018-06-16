#include <stdlib.h>
#include <stdio.h>

#include <filters.h>

void de(unsigned char * in, unsigned char* out, int* args) {
  *out = (*in) * (*args) % 255;
  *(out+1) = *(in+1) * (*(args+1)) % 255;
  *(out+2) = *(in+2) * (*(args+2)) % 255;
}


Image* filter(Image* input, char* startValue){
	// allocate the image
	Image* output = (struct Image*) malloc(sizeof(struct Image));
	output->x = input->x;
	output->y = input->y;
	output->n = input->n;

	int datasize = input->n * input->x * input->y;
	output->data = (unsigned char*) malloc(sizeof(unsigned char) * datasize);

	int* args = malloc(sizeof(int) * 3);
	int temp = startValue[0];
	*args = temp % 10;
	temp/=10;

	*(args+1) = temp % 10;
	temp/=10;

	*(args+2) = temp % 10;

	pixelwice(input, output->data, de, args); 

	free(args);

	return output;
}

