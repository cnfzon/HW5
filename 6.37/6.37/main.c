#include <stdio.h>
#include <stdlib.h>

int recursiveMaximum(const int num[], int space)
{
    int maxOfRest;
    if (space == 1)
        return num[0];

    // 遞迴比較剩餘部分的最大值與當前最後一個元素
    maxOfRest = recursiveMaximum(num, space - 1);
    return (num[space - 1] > maxOfRest) ? num[space - 1] : maxOfRest;
}

int main() 
{
    int num[1000], space, count, max;

    printf("請輸入陣列大小 (最多1000): ");
    scanf_s("%d", &space);

    printf("請輸入陣列中的 %d 個整數:\n", space);
    for (count = 0; count < space; count++)
        scanf_s("%d", &num[count]);

    max = recursiveMaximum(num, space);
    printf("陣列中的最大值是: %d\n", max);
    return 0;
}
