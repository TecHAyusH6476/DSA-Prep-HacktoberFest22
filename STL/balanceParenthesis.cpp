// Check for balance parantheses in a string

#include<bits/stdc++.h>
using namespace std;

bool matching(char a , char b){
    if(a == '(' && b == ')'){
        return true;
    }
    else if(a == '[' && b == ']'){
        return true;
    }
    else if(a == '{' && b == '}'){
        return true;
    }else{
        return false;
    }
}

bool isBalanced(string str){

    stack<char> s;

    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
            s.push(str[i]);
        }
        else{
            if(s.empty() == true){
                return false;
            }
            else if(matching(s.top(), str[i]) == false){
                return false;
            }
            else{
                s.pop();
            }
        }
    }

    return (s.empty() == true);
}

int main(){
    string str;
    cin>> str;

    if(isBalanced(str) == true){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

}