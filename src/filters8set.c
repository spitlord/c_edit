#include <filters8set.h>
void posterize(pixel* in, pixel* out, int* args) {
  int temp, temp2;
  temp = (*in) % (*args + 1);
  if (temp < (*args) / 2.0) {
     *out = (*in) - temp;
     
  }
  else { temp2 = (*in) + (*args) - temp;
    *out  = temp2 > 255 ? 255 : temp2;
  }

  temp = (*(in+1)) % (*args + 1);
  if (temp < (*args) / 2.0) {
    *(out+1) = (*(in+1)) - temp;
  }
  else {
    temp2 = (*(in+1)) + (*args) - temp; 
    *(out+1)  = temp2 > 255 ? 255 : temp2;
  }
  temp = (*(in+2)) % (*args + 1);
  if (temp < (*args) / 2) {
    *(out+2) = (*(in+2)) - temp;
  }
  else {
    temp2 =  (*(in+2)) + (*(args+2)) - temp;
    *(out+2) =  temp2 > 255 ? 255 : temp2;
  }
}

void greyscale(pixel* in, pixel* out, int* args) {
  double pr1, pr2, pr3;
  double total = (*args) + (*(args+1)) + (*(args+2));
  if (total == 0 ) return;
  pr1 = (*args) / total;
  pr2 = (*(args+1)) / total;
  pr3 = (*(args+2)) / total;
  int shade = (int) ( pr1 * (*in) +
		      pr2 * (*(in+1))+
		      pr3 * (*(in+2)));
  *(out+2) = shade;
  *(out+1) = shade;
  *out = shade;
}
  
