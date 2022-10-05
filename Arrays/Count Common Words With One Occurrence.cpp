class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> m1;
        unordered_map<string,int> m2;
        int cnt=0;
        
        for(int i=0;i<words1.size();i++){
            m1[words1[i]]++;
        }
        
        for(int i=0;i<words2.size();i++){
            m2[words2[i]]++;
        }
        
        for(int i=0;i<words1.size();i++){
            auto it = m2.find(words1[i]);
            if(it!=m2.end() && m2[words1[i]]==1 && m1[words1[i]]==1)
                cnt++;
        }
        
        return cnt;
        
    }
};