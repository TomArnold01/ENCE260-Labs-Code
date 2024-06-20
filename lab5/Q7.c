#include <stdio.h>
#include <stdint.h>

size_t readString(char* string, size_t maxStringLength)
{	
	int len = 0;
	while((string[len] = getchar())!=10 && len < maxStringLength) {
		len++;
	}
	string[len] = '\0';
	return len;
}

int main(void) 
{
    size_t len=0;
    char string[11];
    len = readString(string, 10);
    printf("Read String (%s) of length (%zu)\n", string, len);
}