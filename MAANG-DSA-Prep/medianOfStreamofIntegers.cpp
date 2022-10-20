#include <bits/stdc++.h>
using namespace std;
// TC:O(nLogn)
// SC:O(n)

void continuosMedian(int arr[], int n)
{
    float median;
    // stores the left half of the list but in a max heap to get the greatest value from it
    priority_queue<int> maxheap;
    // stores the right half of the list but in a min heap to get the smallest value from it
    priority_queue<int, vector<int>, greater<int>> minheap;
    for (int i = 0; i < n; i++)
    {
        // Step 1:input elements in the maxHeap
        int current = arr[i];
        if (maxheap.empty() || maxheap.top() > current)
            maxheap.push(current);
        else
            minheap.push(current);

        // Step 2:maintain the difference <=1
        if (minheap.size() > maxheap.size() + 1)
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
        else
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }

        // Step 3:decide for the way to find median based on following conditions
        if (n % 2 == 1) // i.e elements are odd
        {
            if (minheap.size() > maxheap.size())
                median = minheap.top();
            else
                median = maxheap.top();
        }
        else
        {
            median = (maxheap.top() + minheap.top()) / 2;
        }
        cout << median << " ";
    }
}
int main()
{
    int arr[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Current Median at every stage:";
    continuosMedian(arr, n);
    return 0;
}