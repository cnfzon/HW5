#include <stdio.h>
#include <stdlib.h>

int recursiveMaximum(const int num[], int space)
{
    int maxOfRest;
    if (space == 1)
        return num[0];

    // ���j����Ѿl�������̤j�ȻP��e�̫�@�Ӥ���
    maxOfRest = recursiveMaximum(num, space - 1);
    return (num[space - 1] > maxOfRest) ? num[space - 1] : maxOfRest;
}

int main() 
{
    int num[1000], space, count, max;

    printf("�п�J�}�C�j�p (�̦h1000): ");
    scanf_s("%d", &space);

    printf("�п�J�}�C���� %d �Ӿ��:\n", space);
    for (count = 0; count < space; count++)
        scanf_s("%d", &num[count]);

    max = recursiveMaximum(num, space);
    printf("�}�C�����̤j�ȬO: %d\n", max);
    return 0;
}
