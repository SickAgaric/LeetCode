//效率极低 O(n^2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int max = 0;
        
        for(int i = 0;i<prices.size();i++)
        {
            for(int j = i+1;j<prices.size();j++)
            {
                if(max < (prices[j] - prices[i]))
                    max = prices[j] - prices[i];
                
                
            }
        }
        
        return max;
    }
};

//改进算法，使用左右双指针后O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        
        int result = 0;
        int left = 0;
        int right = 1;
        
        while(right<prices.size())
        {
            if(prices[left]>prices[right])
            {
                left = right;
                right++;
            }
            
            else
            {
                
                if(result<(prices[right] - prices[left]))
                    result = prices[right] - prices[left];
                right++;
            }
            
        }
        
        return result;
    }
};





