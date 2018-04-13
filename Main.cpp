#include <iostream>

//void shiftPrime(int array[], int ArraySize, int shiftCount);
void shift(int array[], int ArraySize, int shiftCount);
int divisor(int number1, int number2);

int main() {
	const int n = 12;
	int a[n] = { 1,2,3,4,5,6,7,8,9,10,11,12}, k;
	
	std::cin >> k;
	shift(a, n, k);
	for (int i = 0; i < n; i++)std::clog << a[i] << " ";

	system("PAUSE");
	return 0;
}
void shift(int a[], int n, int k) {
	k = k%n;
	if (k == 0)return;
	int t1, t2 = a[0], i = 1, index = (k) % n, temp=index,divisor_ = divisor(n, k);
	if (k == n - 1)k = -divisor_;
	for (int j = 0; j < divisor_; ++j) {
		t2 = a[j];
		index = temp;
		while (index%n!=j || temp == index) {
			t1 = a[(index) % n];
			a[(index) % n] = t2;
			t2 = t1;
			index += k;
			if (index > 100)return;
		}
		a[index % n] = t2;
		temp++;
	}
}
int divisor(int a, int b) {
	while (a != b)
		(a > b) ? a -= b : b -= a;
	return a;
}


/*
void shiftPrime(int a[], int n, int k) {
	int t1, t2 = a[0], i = 1;
	while (k*i%n || i == 1) {
		t1 = a[(k*i) % n];
		a[(k*i) % n] = t2;
		t2 = t1;
		++i;
	}
	a[(k*i) % n] = t2;
}/*
*/