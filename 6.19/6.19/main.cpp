#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   

int main() {

	int dice_a = 0, dice_b = 0, count_a = 0, count_b = 0, total[36000], num[13];

	for (count_b = 2; count_b <= 12; count_b++)
		num[count_b] = 0;

	srand((unsigned int)time(NULL));

	for (count_a = 0; count_a < 36000; count_a++) {
		dice_a = (int)(rand() % 6 + 1);
		dice_b = (int)(rand() % 6 + 1);
		total[count_a] = dice_a + dice_b;

		for (count_b = 2; count_b <= 12; count_b++)
			if (total[count_a] == count_b) num[count_b]++;
	}

	for (count_b = 2; count_b <= 12; count_b++)
		printf("%d點出現次數 : %d 次\n", count_b, num[count_b]);

	return 0;
}