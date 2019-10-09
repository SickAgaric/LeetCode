class Solution {
public:
    bool canWinNim(int n) {
        
        return (n%4!=0);
        
    }
};


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
       
        int sum1 = 0;
        int sum2 = 0;
        auto n = nums.begin();
        
        while(n!=nums.end())
        {
            sum1 += *n;
            ++n;
        }
        
        for(int i = 0;i<=nums.size();i++)
            sum2 += i;
        
        
        return sum2-sum1;
    }
};