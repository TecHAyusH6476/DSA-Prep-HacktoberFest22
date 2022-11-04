#include<iostream>
#include<bits\stdc++.h>
using namespace std;
#include<vector>
void bubblesort(vector<int>&arr)
{
    for(int i=0;i<arr.size();i++)
    {
         bool swaped=false;
        for(int j=0;j<arr.size()-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            { 
               bool swaped=true;
                swap(arr[j+1],arr[j]);
            }
        }
    
         if( swaped==true){
             break;
         }
    }
     for(int ele:arr){
        cout<<ele<<" "; 
    }
}
int main()
{
    vector<int>arr={2,5,9,3,8,6,2};
    bubblesort(arr);
    return 0;
}
