// Median of 2 sorted arrays of equal size

#include <bits/stdc++.h>
using namespace std;

// TC: O(n1+n2) 	SC: O(n1+n2)
// int median(int a[], int b[], int n) {
// 	int add[n + n];

// 	int i = 0, j = 0, k = 0;
// 	while (i < n && j < n)
// 	{
// 		if (a[i] <= b[j])
// 			add[k++] = a[i++];
// 		else if (b[j] < a[i])
// 			add[k++] = b[j++];
// 	}

// 	while (i < n)
// 		add[k++] = a[i++];

// 	while (j < n)
// 		add[k++] = b[j++];

// 	int med = -1;
// 	if (k % 2 == 0)
// 		med = (add[k / 2 - 1] + add[k / 2]) / 2;
// 	else
// 		med = add[k / 2];

// 	return med;
// }


// TC: O(n1+n2) 	SC: O(1)
// int median(int a[], int b[], int n) {
// 	int m1 = -1, m2 = -1;

// 	int i = 0, j = 0;
// 	for (int c = 0; c <= n; c++)
// 	{
// 		if (i == n) {
// 			m1 = m2;
// 			m2 = b[0];
// 			break;
// 		} else if (j == n) {
// 			m1 = m2;
// 			m2 = a[0];
// 			break;
// 		}

// 		if (a[i] <= b[j]) {
// 			m1 = m2;
// 			m2 = a[i];
// 			i++;
// 		} else if (b[j] < a[i]) {
// 			m1 = m2;
// 			m2 = b[j];
// 			j++;
// 		}
// 	}
// 	return (m1 + m2) / 2;
// }

int median(int arr[], int n) {
	if (n % 2 == 0)
		return (arr[n / 2 - 1] + arr[n / 2]) / 2;
	return arr[n / 2];
}

// TC: O(log(n))	SC: O(1)
int get_median(int a[], int b[], int n) {
	if (n <= 0)
		return -1;
	else if (n == 1)
		return (a[0] + b[0]) / 2;
	else if (n == 2)
		return (max(a[0], b[0]) + min(a[1], b[1])) / 2;

	int m1 = median(a, n);
	int m2 = median(b, n);

	if (m1 == m2)
		return m1;
	else if (m1 < m2) {
		if (n % 2 == 0)
			return get_median(a + n / 2 - 1, b, n - n / 2 + 1);
		return get_median(a + n / 2, b, n - n / 2);
	}
	// if(m1 > m2)
	if (n % 2 == 0)
		return get_median(b + n / 2 - 1, a, n - n / 2 + 1);
	return get_median(b + n / 2, a, n - n / 2);
}

int main()
{
	int n; cin >> n;

	int a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int b[n];
	for (int i = 0; i < n; ++i)
		cin >> b[i];

	int m = get_median(a, b, n);

	cout << m;

	return 0;
}
