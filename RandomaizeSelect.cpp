#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int N = 300;
int* A1;
int* A2;
int RandomazerPartition(int* A, int p, int r) {
	int q = rand() % (r - p) + p;
	int j = 0;
	int k = 0;
	for (int i = p; i <= r; i++) {
		if (A[i] < A[q]) {
			A1[j] = A[i];
			j++;
		}
		if(A[i] > A[q]) {
			A2[k] = A[i];
			k++;
		}
	}
	int tn = A[q];
	for (int i = 0; i < 3; i++) {
		cout << endl;
	}
	for (int i = 0; i < j; i++) {
		cout << A1[i] << " ";
	}
	for (int i = 0; i < 3; i++) {
		cout << endl;
	}
	for (int i = 0; i < k; i++) {
		cout << A2[i] << " ";
	}
	int i;
	for (i = p; i <= p+j; i++) {
		A[i] = A1[--j];
	}
	A[i] = tn;
	i++;
	for (; i <= r; i++) {
		A[i] = A2[--k];
	}

	return q;
}
int RandomazerSelect(int* A, int p, int r, int i) {
	if (p == r) {
		return A[p];
	}
	int q = RandomazerPartition(A,p,r);
	int k = q - p + 1;
	if (i == k) {
		return A[q];
	}
	else {
		if (i < k) {
			return RandomazerSelect(A, p, q - 1, i);
		}
		else {
			return RandomazerSelect(A, q + 1, r, i - k);
		}
	}
	return i;
}
int main() {
	A1 = new int[N];
	 A2 = new int[N];
	srand(time(NULL));
	int *A = new int[10];
	for (int i = 0; i < 10; i++) {
		A[i] = rand();
	}
	for (int i = 0; i < 3; i++) {
		cout << endl;
	}
	for (int i = 0; i < 10; i++) {
		cout << A[i] << "  ";
	}
	int num = RandomazerPartition(A, 0, 9);
	for (int i = 0; i < 3; i++) {
		cout << endl;
	}
	cout << num;
	for (int i = 0; i < 3; i++) {
		cout << endl;
	}
	for (int i = 0; i < 10; i++) {
		cout << A[i] << "  ";
	}
	for (int i = 0; i < 3; i++) {
		cout << endl;
	}
	system("PAUSE");
}