// previous greater element

#include<bits/stdc++.h>
using namespace std;

void printPrevGreater(int arr[], int n);

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i =0; i < n ; i++){
        cin>>arr[i];
    }

    

    // //naive solution

    // for(int i = 0 ; i < n ; i++){

    //     int ele = 0;

    //     if(arr[i] == arr[0]){
    //         ele = -1; 
    //     }
    //     else{
    //         for(int j = i-1; j >= 0 ; j--){
    //             if(arr[i]<arr[j]){
    //                 ele = arr[j];
    //                 break;
    //             }
    //             else{
    //                 ele = -1;
    //             }
    //         }
    //     }

    //     cout<<ele<<" ";
    // }


    printPrevGreater(arr, n);
}


// effecient solution
void printPrevGreater(int arr[], int n){
     stack<int> s;

     s.push(arr[0]);

        cout<<"-1 "; // for previous greater of 1st element of an array

     for(int i = 1; i < n ; i++){
        while(s.empty() == false && s.top() <= arr[i]){
            s.pop();
        }

        int op;

        if(s.empty() == true){
            op = -1;
        }else{
            op = s.top();
        }

         cout<<op<<" ";
         s.push(arr[i]);
     }
}