class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for(int j = 0;j < nums.size();j++)
        {
            if(nums[j] != val)
            {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int end = nums.size();
        int i = 0;
        while(i < end)
        {
            if(nums[i] == val)
            {
                nums[i] = nums[end-1];
                end--;
            }
            else
            {
                i++;
            }
        }
        return end;
    }
};