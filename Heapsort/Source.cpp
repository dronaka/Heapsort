#include <fstream> 

//#include <stdio.h> 
//#include <stdlib.h> 

using namespace std;
ifstream cin("sort.in");
ofstream cout("sort.out");


void downHeap(int *a, long k, long n) {
	//  ��������� ����������� ���������� �������� 
	//  �� ���������: a[k+1]...a[n]  - �������� 
	//  �����:  a[k]...a[n]  - �������� 
	int new_elem;
	long child;
	new_elem = a[k];

	while (k <= n / 2) {  		// ���� � a[k] ���� ���� 
		child = 2 * k;
		//  �������� �������� ���� 
		if (child < n && a[child] < a[child + 1])
			child++;
		if (new_elem >= a[child]) break;
		// ����� 
		a[k] = a[child]; 	// ��������� ���� ������ 
		k = child;
	}
	a[k] = new_elem;
}

void buildHeap(int *a, int size) {
	for (int i = size / 2; i >= 0; i--) downHeap(a, i, size - 1);
}

void heapSort(int *a, int n) {
	buildHeap(a, n);
	for (int i = n - 1; i>0; i--) {
		swap(a[0], a[i]);
		downHeap(a, 0, i - 1);
	}
}

int main() {
	int n, t;

	cin >> n;
	int *a = new int[n + 1];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	heapSort(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	return 0;
}

