#include <stdlib.h>
#include <stdio.h>
#include <filters.h>

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

/* 
   creates arguments, increments them sequentially
   count is number of arguments in the filter
   n is the hash number
   lims is max value each argument can take 
*/
int* variate(int count, int n, int* lims) {
	int* args = malloc(sizeof(int) * count);
	int* temp = args;


	for (int i = 0; i < count; i++) {
		*temp = n % (*lims);
		n /= (*lims);  
		temp++; lims++; // move on
	}

	return args;
}


Image* filter(Image* input, int startValue){
	// allocate the image
	Image* output = (struct Image*) malloc(sizeof(struct Image));
	output->x = input->x;
	output->y = input->y;
	output->n = input->n;

	int datasize = input->n * input->x * input->y;
	output->data = (unsigned char*) malloc(sizeof(unsigned char) * datasize);
	
	int limits[] = {10, 10, 10};
	int* args = variate(3, startValue, limits);

	pixelwice(input, output->data, greyscale, args); 

        free(args);

	return output;
}  

