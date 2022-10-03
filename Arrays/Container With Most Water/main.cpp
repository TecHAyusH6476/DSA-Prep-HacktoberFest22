class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int start = 0;
        int end = height.size()-1;
        int area = 0;
        while(start<end){
        int distance = end-start;
         area = max(distance*min(height[start],height[end]),area);
         if(height[start] < height[end]){
             
             start++;
         }
            else{
               end--;
            }
        }
        
        return area;
    }
};