class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int mx1 = nums[0];
        int mx2 =  nums[0],ans=0;
        for(int i=1;i<n;i++){
            mx2 = max(mx2, nums[i]);
            if(mx1>nums[i]){
                mx1 = mx2; ans =i;
            }
        }
        return ans+1;
    }
};
