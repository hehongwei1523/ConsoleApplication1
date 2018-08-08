#include<stdio.h>



void INCREMENT(int *A, int k) {
	int i = 0;

	while ((i < k) && (A[i] == 1)) {
		A[i] = 0;
		i += 1;
	}
	if (i < k) {
		A[i] = 1;
	}
}

void Delete(int *A) {
	free(A);
}

int *A;

int main_binaryarray() {
	int k;
	
	printf("二进制数组大小：\n");
	scanf_s("%d", &k);
	if (k > 50)
	{
		printf("error! \n");
		return 0;
	}
	A = malloc(sizeof(int) * k);
	
	for (int i = 0; i < k; i++) {
		A[i] = 0;
	}
	
	for (int j = 0; j < k; j++) {
		INCREMENT(A, k);
	}

	for (int i = k - 1; i >= 0; i--) {
		printf("%d ", A[i]);
	}
	Delete(A);
	printf("\n");
	return 0;
}
