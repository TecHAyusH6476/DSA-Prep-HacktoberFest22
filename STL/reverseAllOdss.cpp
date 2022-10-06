// code to reverse an order of all odd no.s from a forward list using stack

#include<bits/stdc++.h>
using namespace std;

void revOddorder (forward_list<int> fl){
    stack<int> s;
    for(auto x : fl){
        if(x % 2 != 0){
            s.push(x);
        }
    }

    // print all odd item in rev order
    while (s.empty() == false)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    
}

int main(){

    forward_list<int> fl = {12,7,45,33,24,32,33,21};

    revOddorder(fl);

}