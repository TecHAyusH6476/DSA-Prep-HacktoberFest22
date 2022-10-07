#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string>& s) {
        int n=s.size();
        string ans="";
        string compare="";
        int sze=INT_MAX;
        for(int i=0;i<n;i++){
            if(s[i].size()<sze){
                sze=s[i].size();
                compare=s[i];
            }
        }
       for(int i=0;i<compare.size();i++){
           bool match=true;
           for(int j=0;j<n;j++){
               if(compare[i]!=s[j][i]){
                   match=false;
                   break;
               }
           }
           if(match==false)
           break;
           else{
           ans.push_back(compare[i]);
    
           }
       }
       
        return ans;
    }
    int main(){
    	int n;
    	cout<<"Enter the size of array: ";
    	cin>>n;
    	vector<string> v;
    	cout<<"Enter the elements of the array ";
    	string x;
    	for(int i=0;i<n;i++){
    		cin>>x;
    		v.push_back(x);
		}
		string ans=longestCommonPrefix(v);
		cout<<ans;
	}