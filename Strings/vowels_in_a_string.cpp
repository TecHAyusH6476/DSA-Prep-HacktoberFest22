class Solution {
public:
    int maxVowels(string s, int k) 
    {
        int count=0 , j=0,ans ;
        for(int i=0;i<k;i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
               count++ ;
        }
        ans=count ;
       for(int i=k ;i<s.size();i++)    
       {
           if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u')
               count-- ;
           
           j++;       
           if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
               count++ ;
           
           ans=max(ans,count);
       }
        return ans ;
    }
};
