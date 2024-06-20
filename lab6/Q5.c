#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char* skipping(const char* string, size_t n)
{
	char* result;
	int k = 0, i = 0;
	result = (char*)malloc(sizeof(char)*((n+1)/2)+1);
	while(i<n) {
		result[k++] = string[i];
		i += 2;
	}
	result[k] = '\0';
	return result;
}

int main() 
{
	char* s = skipping("0123456789", 10);
	printf("%s\n",s);
	free(s);
	return 0;
}