#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int b[] = { 10, 20, 30, 40 };  // Array declaration
    int* bPtr = b;               // Pointer to the first element of array b
    int i;                       // Loop variable
    int offset;                  // Offset variable for pointer arithmetic

    // Array printed with array subscript notation
    printf("Array b printed with:\narray subscript notation\n");
    for (i = 0; i < 4; i++) {
        printf("b[%d] = %d\n", i, b[i]);
    }

    // Pointer/offset notation where the pointer is the array name
    printf("\nPointer/offset notation where\n");
    printf("the pointer is the array name\n");
    for (offset = 0; offset < 4; offset++) {
        printf("*(b + %d) = %d\n", offset, *(b + offset));
    }

    // Pointer subscript notation
    printf("\nPointer subscript notation\n");
    for (i = 0; i < 4; i++) {
        printf("bPtr[%d] = %d\n", i, bPtr[i]);
    }

    // Pointer/offset notation where the pointer is bPtr
    printf("\nPointer/offset notation where\n");
    printf("the pointer is bPtr\n");
    for (offset = 0; offset < 4; offset++) {
        printf("*(bPtr + %d) = %d\n", offset, *(bPtr + offset));
    }

    return 0;
}
