#include <stdio.h>
#include <stdlib.h>

void stringReverse(const char* str) 
{
    if (*str == '\0')
        return;
    stringReverse(str + 1); // ���j�B�z�ѤU���r��
    putchar(*str);          // �۳̫�@�Ӧr���}�l�C�L
}

int main() 
{
    char string[100];

    printf("�п�J�@�Ӧr�� : \n");
    fgets(string, sizeof(string), stdin);

    printf("�r��ϦV�C�L���G : ");
    stringReverse(string);

    return 0;
}
