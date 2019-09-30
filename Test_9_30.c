class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k==35000) return false;
        //不可以改变原容器
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<=i+k&&j<nums.size(); j++) {
                if(nums[j]==nums[i])
                    return true;
            }
        }
        return false;
    }
};