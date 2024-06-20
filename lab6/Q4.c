#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void fillRamp(int16_t* data, size_t n)
{
 
	for(size_t i = 0; i < n; i++) {
		data[i] = i+1;
	}
}
int main(){
	int16_t* data = calloc(4, sizeof(int16_t));
	fillRamp(data, 4);
	for(size_t i = 0; i < 4; i++){
		printf("data[%zu] = %d\n", i, data[i]);
	}
	free(data);
}