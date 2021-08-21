class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int c=0;
        for(int i=2;i<nums.size();i++){
            int left = 0, right = i-1;
            while(left<right) {
                if(nums[left] + nums[right] > nums[i]){
                    c += (right - left);
                    right--;
                }
                else{
                    left++;
                }
            }
            
        }
                   return c;
        
    }
};
