// Generate Binary Numbers
// i/p-> N = 5
// o/p-> 1 10 11 100 101

#include<bits/stdc++.h>
using namespace std;

void generateBinary(int n){
    queue<string> q;
    q.push("1");

    for(int i = 0 ; i < n  ; i++){
        string current = q.front();
        cout<<current<<" ";
        q.pop();

        q.push(current + "0");
        q.push(current + "1");
     }
}

int main(){
    int n;
    cin>>n;

    generateBinary(n);
}