#include<bits/stdc++.h>
using namespace std;
 

class Solution{
    
    public:
        string multiplyStrings(string s1, string s2) {
            int m = s1.size();
            int n = s2.size();
            int neg1 = s1[0] == '-' ? true:false;
            int neg2 = s2[0] == '-' ? true:false;
            string ans(m+n,'0');
    
            for(int i = m-1; i>=neg1; i--)
                for(int j = n-1; j>=neg2; j--)
                {
                    int sum = (s1[i]-'0')*(s2[j]-'0') + (ans[i+j+1]-'0');
                    ans[i+j+1] = sum % 10 + '0';
                    ans[i+j] += sum / 10 ;
                }
            
            int i;
            for(i = 0; i<m+n; i++) if(ans[i]!='0') break;
            if(i == m+n) return "0";
            if(neg1 ^ neg2) return "-"+ans.substr(i); 
            return ans.substr(i);
        }

};

 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
