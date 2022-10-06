// generate numbers with given digits 5 & 6 in increasing order
// 5,6,55,56,65,66,.......

#include<bits/stdc++.h>
using namespace std;

void printFirst(int n){
    queue<string> q;
    q.push("5");
    q.push("6");

    for(int i  =0 ; i < n ; i++){
        string curr = q.front();
        cout<<curr<<" ";
        q.pop();
        q.push(curr + "5");
        q.push(curr + "6");
    }
}

int main(){

    int n;
    cin>>n;

    printFirst(n);

}