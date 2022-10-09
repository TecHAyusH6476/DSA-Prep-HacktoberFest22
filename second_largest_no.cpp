#include <bits/stdc++.h>
using namespace std;

int secondlargest(int arr[], int n)

{

    int res = -1, largest = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
     for (int i = 0; i < n; i++)
    {
     if ((arr[i] <  largest) && arr[i] >=res)
        {

                res = arr[i];
        }
        
    } 
    return res;
}

int main()
{
    cout << "enter the size" << endl;
    int f;
    cin >> f;
    int num[100];

    for (int i = 0; i < f; i++)
    {
        cout << "enter the element" << endl;
        cin >> num[i];
    }
    cout << " result " << "  "<<secondlargest(num,f);
    // cout << "result " << endl;

    return 0;
}
