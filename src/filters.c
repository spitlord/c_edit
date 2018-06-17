#include <stdlib.h>
#include <stdio.h>
#include <filters.h>
#include <math.h>

void de(pixel* in, pixel* out, int* args) {
  *out = *in * (*args) % 0x100;
  *(out+1) = (*(in+1)) * (*(args+1)) % 0x100;
  *(out+2) = (*(in+2)) * (*(args+2)) % 0x100;
}

void quen( pixel * in, pixel* out, int* args) {
  *out =    ((pixel) (( (*in+1) * (*(in+2))) /1.0  / (*args))) % 0x100;
  *(out+1) = ((pixel)(( (*in)   * (*(in+2))) /1.0  / (*(args+1)))) % 0x100;
*(out+2) = ((pixel)(( (*in)     * (*(in+1))) /1.0  / (*(args+2)))) % 0x100;
   
}

void que( pixel * in, pixel* out, int* args) {
  *out =    (pixel) ((*in) + (sin(*args) * (*(in+1))));
  *(out+1) = (pixel) ((*in+1) +  (sin(*(args+1)) * (*(in+2))));
  *(out+2) = (pixel) ((*in+2) +  (sin(*(args+2))) * (*in));
   
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
	*args = temp % 30;
	temp/=30;

	*(args+1) = temp % 30;
	temp/=30;

	*(args+2) = temp % 30;

	pixelwice(input, output->data, que, args); 

	free(args);

	return output;
}  

