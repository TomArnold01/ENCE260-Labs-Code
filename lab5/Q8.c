#include <stdio.h>
#include <stdint.h>


int main(void) 
{
    FILE* fp;
    int count = 0;
    char filename[81];
    char c;
    FILE* aFile;
    int32_t data;
    fscanf(aFile, "%d\n", &data);

    if (fp == NULL) {
        printf("is null\n");
        return 0;
    }
    for (c = getc(fp); c != EOF; c = getc(fp)) {
        count++;
    }
    fclose(fp);
    
    printf("this file has %d\n", count);
}