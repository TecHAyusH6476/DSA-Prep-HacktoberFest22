#include<iostream>
using namespace std;

void Clockwise(int a[], int m, int k)
{
    k = k % m;
    for(int i = 0; i < m; i++)
    {
       if(i < k)
       {
           cout << a[m + i - k] << " ";
       }
       else
       {
           cout << (a[i - k]) << " ";
       }
    }
    cout << "\n";
}

int main()
{
    int n,k;
    cout << "Enter limit: ";
    cin>>n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << "/nEnter k to shift by: ";
    cin>>k;
    int m = sizeof(a) / sizeof(a[0]);


    Clockwise(a, m, k);
}
