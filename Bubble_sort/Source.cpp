#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int readFromFile(FILE* inp, int A[]) {
	int k = 0;
	while (fscanf(inp, "%d", &A[k]) != EOF)
		k++;
	return (k);
}

void swap(int* x, int* y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void bubbleSort(int A[], int size) {
	int k, pass, sorted;
	pass = 1;
	do {
		sorted = 1;
		for (k = 0; k < size - pass; k++)
			if (A[k] > A[k + 1])
			{
				swap(&A[k], &A[k + 1]);
				sorted = 0;
			}
		pass++;
	} while (!sorted);
}

int main(void)
{
	FILE* inp;
	inp = fopen("labs.txt", "r");
	if (inp == NULL)
		printf("Error");
	else
	{
		int A[20];
		int size = readFromFile(inp, A);
		bubbleSort(A, size);

		printf("# of pcs in labs\n");
		printf("******************\n");
		for (int i = 0; i < size; i++)
			printf("%6d\n", A[i]);
	}
	return 0;
}