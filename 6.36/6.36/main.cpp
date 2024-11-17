#include <stdio.h>
#include <stdlib.h>

void stringReverse(const char* str) 
{
    if (*str == '\0')
        return;
    stringReverse(str + 1); // 遞迴處理剩下的字元
    putchar(*str);          // 自最後一個字元開始列印
}

int main() 
{
    char string[100];

    printf("請輸入一個字串 : \n");
    fgets(string, sizeof(string), stdin);

    printf("字串反向列印結果 : ");
    stringReverse(string);

    return 0;
}
