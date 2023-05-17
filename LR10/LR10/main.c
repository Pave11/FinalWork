#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	FILE* a = fopen("a.txt", "w");
	float sr = 0;
	char g[100];
	int m[10], m1[10], sum = 0, el;
	for (int i = 0; i < 10; i++) {
		m[i] = rand() % 100;
		fprintf(a, " %d\n", m[i]);
	}
	fprintf(a, " \n");
	fclose(a);
	a = fopen("a.txt", "r");
	for (int i = 0; i < 10; i++) {
		fgets(g, 100, a);
		printf("m[%d]:%s", i, g);
	}
	fclose(a);
	a = fopen("a.txt", "r");
	int* pM1 = &m1[0];
	for (int i = 0; i < 10; i++) {
		fscanf(a, "%d", &pM1);
		el = pM1;
		sum += el;
		pM1++;
	}

	FILE* b = fopen("b.txt", "w");
	sr = (float)((float)sum / 10);
	fprintf(b, "%fl\n", sr);
	fclose(b);
	printf("Otvet: %4.1f", sr);
	getch();
}