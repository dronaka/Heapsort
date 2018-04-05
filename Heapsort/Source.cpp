#include <fstream> 

//#include <stdio.h> 
//#include <stdlib.h> 

using namespace std;
ifstream cin("sort.in");
ofstream cout("sort.out");


void downHeap(int *a, long k, long n) {
	//  процедура просеивания следующего элемента 
	//  До процедуры: a[k+1]...a[n]  - пирамида 
	//  После:  a[k]...a[n]  - пирамида 
	int new_elem;
	long child;
	new_elem = a[k];

	while (k <= n / 2) {  		// пока у a[k] есть дети 
		child = 2 * k;
		//  выбираем большего сына 
		if (child < n && a[child] < a[child + 1])
			child++;
		if (new_elem >= a[child]) break;
		// иначе 
		a[k] = a[child]; 	// переносим сына наверх 
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

