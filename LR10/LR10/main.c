#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	FILE* a = fopen("a.txt", "w");
	float sr1 = 0;
	char g1[100];
	int m1[10];
	int m2[10];
	int sum1 = 0; //Переменная для суммы всех элементов массива
	int el;
	for (int i = 0; i < 10; i++) {
		m1[i] = rand() % 100;
		fprintf(a, " %d\n", m1[i]);
	}
	fprintf(a, " \n");
	fclose(a);
	a = fopen("a.txt", "r");
	for (int i = 0; i < 10; i++) {
		fgets(g1, 100, a);
		printf("m[%d]:%s", i, g1);
	}
	fclose(a);
	a = fopen("a.txt", "r");
	int* pM1 = &m2[0];
	for (int i = 0; i < 10; i++) {
		fscanf(a, "%d", &pM1);
		el = pM1;
		sum1 += el;
		pM1++;
	}

	FILE* b = fopen("b.txt", "w");
	sr1 = (float)((float)sum1 / 10);
	fprintf(b, "%fl\n", sr1);
	fclose(b);
	printf("Otvet: %4.1f", sr1);
	getch();
}