class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        for(auto p=nums.begin();p!=nums.end();++p)
        {
            if(*p==val)
            {
                p=nums.erase(p);
            }
        }
        return nums.size();
    }
};
