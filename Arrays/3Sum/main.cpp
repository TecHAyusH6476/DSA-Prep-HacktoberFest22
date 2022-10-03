class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
   
    sort(nums.begin(),nums.end());
    int n = nums.size();
    vector<vector<int>> ans;
    
        for(int i = 0; i<n-2; i++){
            int j = i+1;
            int k = n-1;
            
            while(j<k){
              int  sum = nums[j] + nums[k];
                
                if(sum == -nums[i]){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<k and nums[j]==nums[j+1])j++;
                    while(j<k and nums[k]==nums[k-1])k--;
                    j++;
                    k--;
                }
                
                else if(sum > -nums[i]){
                    k--;
                }
                else if(sum < -nums[i]){
                    j++;
                }
            }
            while(i<n-2 and nums[i]==nums[i+1])i++;
            
        }
        
        return ans;
        
    }
};   