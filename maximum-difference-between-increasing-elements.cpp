class Solution {
public:
    int maximumDifference(vector<int>& nums) {
//         int m;
//         int n = nums.size();
//         vector<int> res;
        
        
//         for(int i=0;i<n-1;i++){
//             int j = i+1;
//             if(nums[i]<nums[j]){
//                 int req = nums[j]-nums[i];
//                 res.push_back(req);
//             }
//             else
//                 m=-1;
//         }
        
//         if ( res.empty() )
//             m=-1;
//         else
//             m = *max_element(res.begin(),res.end());
        
        int low=INT_MAX;
        int high =-1;
        for(int i=0;i<nums.size();i++){
            low = min(low,nums[i]);
            high = max(high,nums[i]-low);
        }
        
    if(high<1)
        high=-1;
        
        return high;
    }
};