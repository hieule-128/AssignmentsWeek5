#include<iostream>
using namespace std;
int main() {
	int n, temp, dem = 1;
	int* arr;
	int** b;
	cout<< "so phan tu trong mang muon khoi tao la: ";
	cin >> n;
	arr = new int[n];
	b = new int* [2];
	for (int i = 0; i < 2; i++) {
		b[i] = new int[n];
	}
	cout << "nhap phan tu: " << endl;
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]= ";
		cin >> arr[i];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int j = 0; j < n; j++) {
		b[0][j] = arr[j];
		b[1][j] = 1;
	}
	int	dd = 1;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] == arr[j]) {
				dd = dd + 1;
				b[1][i] = dd;
				b[0][j] = 0;
			}
		}
		dd = 1;
	}
	int	max;
	int k = 0;
	max = b[1][0];
	for (int j = 0; j < n; j++) {
		if (max < b[1][j]) max = b[1][j];
	}
	cout << "Gia tri lon nhat=" << arr[n - 1] << "\nGia tri nho nhat=" << arr[0];
	cout << "\n";
	cout << "In mang sap xep" << "\n";
	for (int j = 0; j < n; j++) { cout << arr[j] << "  "; }
	cout << "\n";
	cout << "Tan suat cua cac phan tu" << "\n";
	for (int j = 0; j < n; j++) {
		if (b[0][j] != 0) {
			cout << "So " << b[0][j] << " xuat hien  " << b[1][j] << " lan";
			cout << "\n";
		}
	}
	if (max > 1) {
		cout << "Gia tri xuat hien nhieu nhat la: ";
		for (int j = 0; j < n; j++) {
			if (b[1][j] == max) {
				b[0][j] = arr[j];
				cout << b[0][j] << ", ";
			}
		}
		cout << "xuat hien " << max << " lan.";
		cout << "\n";
	}
	if (max == 1) cout << "cac so chi xuat hien mot lan " << "\n";
	return 0;
}