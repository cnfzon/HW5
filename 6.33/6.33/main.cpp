#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int array[], int start, int end, int key) {
    if (start > end)                                     // miss
        return -1;

    int mid = (start + end) / 2;                         // 中間

    if (array[mid] == key)
        return mid;
    else if (array[mid] > key)                           // 中間值>key
        return binarySearch(array, start, mid - 1, key); // left
    else                                                 // 中間值<key
        return binarySearch(array, mid + 1, end, key);   // right
    
}

int main() {
    int dice_a = 0, dice_b = 0, count_a = 0, count_b = 0, total[36000], num[13];
    int sorted_totals[36000], i, j, temp, key, result; 

    for (count_b = 2; count_b <= 12; count_b++)
        num[count_b] = 0;

    srand((unsigned int)time(NULL));

    for (count_a = 0; count_a < 36000; count_a++) 
    {
        dice_a = (int)(rand() % 6 + 1);
        dice_b = (int)(rand() % 6 + 1);
        total[count_a] = dice_a + dice_b;

        for (count_b = 2; count_b <= 12; count_b++)
            if (total[count_a] == count_b) num[count_b]++;
    }

    for (i = 0; i < 36000; i++)
        sorted_totals[i] = total[i];

    for (i = 0; i < 35999; i++) 
    {
        for (j = 0; j < 35999 - i; j++) 
        {
            if (sorted_totals[j] > sorted_totals[j + 1]) 
            {
                temp = sorted_totals[j];
                sorted_totals[j] = sorted_totals[j + 1];
                sorted_totals[j + 1] = temp;
            }
        }
    }

    for (count_b = 2; count_b <= 12; count_b++)
        printf("%d點出現次數 : %d 次\n", count_b, num[count_b]);

    printf("\n請輸入要搜尋的點數總和 (2 ~ 12): ");
    scanf_s("%d", &key);

    result = binarySearch(sorted_totals, 0, 35999, key);

    if (result != -1) 
        printf("找到點數 %d，出現在索引 %d。\n", key, result);
    else 
        printf("點數 %d 不存在於模擬的結果中。\n", key);

    return 0;
}