#include <stdio.h>
#include <stdint.h>


void processBuffer(void* buffer, size_t numElements, size_t elementSize, void (*processFunc)(void*)) {
    // looping through the buffer and applying the function
    for (size_t i = 0; i < numElements; ++i) {
        processFunc((size_t*)(buffer+i*elementSize));
    }
}



// tester code
void processU64(void* element) {
    printf("%lu\n", *(uint64_t*)element);
}

int main() {

    uint64_t arr[11] = {0, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
    processBuffer((void*)arr, 11, sizeof(uint64_t), &processU64);

    return 0;
}