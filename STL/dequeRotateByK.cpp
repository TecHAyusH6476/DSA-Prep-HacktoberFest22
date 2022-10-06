// Code to rotate Dq by K:

#include<bits/stdc++.h>
using namespace std;

int main(){

    
    cout<<"Enter the size of Dq : "<<endl;
    int n ;
    cin>>n;

    deque<int> dq;

    cout<<"Enter Dques elements : "<<endl;
    int x;
    for(int i = 0; i < n ; i++)
    {
        cin>>x;
        dq.push_back(x);
    }

    cout<<"Enter K Value : "<<endl;
    int k;
    cin>>k;
    

    auto it = dq.begin();


    dq.insert(it ,dq.begin()+n-k, dq.end());

    // dq.insert(it, dq.rbegin(), dq.rbegin() + k);

    for(int i = 1 ; i <= k ; i++){
        dq.pop_back();
    }

    for(auto x : dq){
        cout<<x<<" ";
    }
}