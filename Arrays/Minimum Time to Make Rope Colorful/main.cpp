class Solution {
public:
    
    int minCost(string colors, vector<int>& neededTime) {
        
        int ans = 0;
        int n = colors.size();
        int j = 0;
        for(int i = 1; i < n; i++){
            if(colors[i] == colors[i-1]){
                ans += min(neededTime[i],neededTime[i-1]);
                neededTime[i] = max(neededTime[i], neededTime[i - 1]); 
            }
        }
        
       return ans;

    }
};