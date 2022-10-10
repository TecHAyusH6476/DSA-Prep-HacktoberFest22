#include<bits/stdc++.h>
using namespace std;

bool helper(char s[],int start,int end)
{
    if (start == end)
    return true;
    

     if(s[start]!=s[end])
    {
        return false; 
    }
   
     return helper(s,start+1,end-1); 
     return true;
    
}

bool palindrome(char s[])
{
    int n=strlen(s);
     if (n == 0)
        return true;
    return helper(s,0,n-1);
}
int main()
{
    char str[] = "racecar";
 
    if (palindrome(str))
    cout << "Yes";
    else
    cout << "No";
 





return 0;
}
