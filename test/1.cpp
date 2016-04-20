#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int N;
int Flag1 = 0, Flag2 = 0, Count1 = 0, Count2 = 0,F=0;
int arr4[50][101];
void insert_sort(int*array,int *array2, unsigned int n)
{
	int i, j;
	int temp;
	for (i = 1;i<n;i++)
	{
		if (Flag1 == 1) {
			temp = *(array + i);
			for (j = i;j>0 && *(array + j - 1)>temp;j--)
			{
				*(array + j) = *(array + j - 1);
			}
			*(array + j) = temp;
			for (int c = 0;c < N;c++) {
				if (c == (N - 1))
					cout << array[c];
				else
					cout << array[c] << " ";
			}
			break;
		}
		else{
			temp = *(array + i);
			for (j = i;j>0 && *(array + j - 1)>temp;j--)
			{
				*(array + j) = *(array + j - 1);
			}
			*(array + j) = temp;
			for (int a = 0;a < N;a++) {
					if (array[a] == array2[a]) {
						Count1 = 1;
					}
					else {
						Count1 = 0;
						break;
					}
			}
			if (Count1 == 1) {
				cout << "Insertion Sort" << endl;
				Flag1 = 1;
			}
		}
	}
}

void Merge(int* data, int a, int b, int length, int n) {
	int right;
	if (b + length - 1 >= n - 1) right = n - b;
	else right = length;
	int* temp = new int[length + right];
	int i = 0, j = 0;
	while (i <= length - 1 && j <= right - 1) {
		if (data[a + i] <= data[b + j]) {
			temp[i + j] = data[a + i];i++;
		}
		else {
			temp[i + j] = data[b + j];
			j++;
		}
	}
	if (j == right) {//a中还有元素，且全都比b中的大,a[i]还未使用
		memcpy(temp + i + j, data + a + i, (length - i) * sizeof(int));
	}
	else if (i == length) {
		memcpy(temp + i + j, data + b + j, (right - j) * sizeof(int));
	}
	memcpy(data + a, temp, (right + length) * sizeof(int));
	delete[] temp;
}
void  MergeSort(int* data, int n,int *arr2) {
	int step = 1;
	while (step < n) {
		for (int i = 0; i <= n - step - 1; i += 2 * step)
		{
			if (Flag2 == 1&&F==0) {
				Merge(data, i, i + step, step, n);
				F++;
			}

			else if (Flag2 == 1 && F == 1) {
				Merge(data, i, i + step, step, n);
				for (int c = 0;c < N;c++) {
					if (c == (N - 1))
						cout << data[c];
					else
						cout << data[c] << " ";
				}
				exit(1);
			}

			else {
				Merge(data, i, i + step, step, n);

				for (int a = 0;a < N;a++) {
					if (data[a] == arr2[a]) {
						Count2 = 1;
					}
					else {
						Count2 = 0;
						break;
					}
				}
				if (Count2 == 1) {
					cout << "Merge Sort" << endl;
					Flag2 = 1;
				}
			}
		}
		step *= 2;
	}
}
int main()
{
	cin >> N;
	int arr[101];
	for (int i = 0;i < N;i++)
		cin >> arr[i];
	int arr3[101];
	for (int i = 0;i < N;i++)
		arr3[i] = arr[i];
	int arr2[101];
	for (int i = 0;i < N;i++)
		cin >> arr2[i];
	insert_sort(arr,arr2, N);
	int temp[101] = {0};
	MergeSort(arr3 ,N-1 ,arr2);
	return 0;
}