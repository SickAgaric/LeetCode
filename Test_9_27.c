
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        
        int result = 0;
        int left = 0;
        int right = 1;
        int buy = 0;
        
        while(right<prices.size())
        {
            if(prices[left]>prices[right])
            {
                left = right;
                right++;
            }
            
            else
            {
                
                buy = prices[left];
                
                
                /*if(prices[right] > prices[right+1])
                {
                    result += prices[left] - prices[right];
                    left = right+1;
                    right++;//
                    
                }*/
                
                
            }
            
        }
        
        return result;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        
        int buy = prices[0];
        int sell = prices[0];
        int money = 0;
        int i = 0;
        
        while(i<prices.size()-1)
        {
            while(i < prices.size() - 1 && prices[i+1] <= prices[i])
                i++;
            
            buy = prices[i];
            
            while(i < prices.size() - 1 && prices[i+1] > prices[i])
                i++;
            
            sell = prices[i];//当到达结尾的时候,buy会等于sell
            
            money += sell - buy;
        }
        
        return money;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int left_num = 0; 
        for(i = 0; i<numbers.size(); i++)
        {
            left_num = numbers[i];
            
            if(numbers.find(numbers.begin(),numbers.end(),target-left_num))
            {
                int pos = numbers.find(target-left_num);
                twoSum[0] = i;
                twoSum[1] = pos;
                return twoSum;
            }
            
        }
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int _begin = 0;
        int _end = numbers.size()-1;
        int ret[2];
        while(_begin<_end)
        {
            if(numbers[_begin]+numbers[_end] == target)
            {
                /*twoSum[0] = _begin;
                twoSum[1] = _end;
                return twoSum;*/
                ret[0] = _begin+1;
                ret[1] = _end+1;
                break;
            }
            
            else if(numbers[_begin]+numbers[_end]>target)
                _end--;
            else
                _begin++;
            
        }
        return vector<int>(ret,ret+2);
    }
};


class Solution {
public:
    string convertToTitle(int n) {
        
        
        int i = 0;
        int remainder = n%26;
        string str;
        while(n)
        {
            i++;
            n/=27;
        }
        
        while(i--)
        {
            str.push_back('A');
        }
        
        if(remainder)
        {
            str.push_back('A'+remainder-1);
        }
        
        return str;
    }
};



class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int _begin = 0;
        int _end = numbers.size()-1;
        int ret[2];
        while(_begin<_end)
        {
            if(numbers[_begin]+numbers[_end] == target)
            {
                /*twoSum[0] = _begin;
                twoSum[1] = _end;
                return twoSum;*/
                ret[0] = _begin+1;
                ret[1] = _end+1;
                break;
            }
            
            else if(numbers[_begin]+numbers[_end]>target)
                _end--;
            else
                _begin++;
            
        }
        return vector<int>(ret,ret+2);
    }
};