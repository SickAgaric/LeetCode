class Solution {
public:
    int trailingZeroes(int n) {
        
        int result = 0;
        
        while(n>=5)
        {
            result += n/5; //此处n/5是为了算出有几个0
            n /= 5;
        }
        
        return result;
    }
};

class Solution {
public:
    int titleToNumber(string s) {
        
        
        int len = s.size()-1;
        int num = 0;
        int result = 0;
        
        for(int i = 0; i < s.size(); i++)
        {
            num = pow (26,len--)*(s[i]-'A'+1);
            
            result += num;
        }
        
        return result;
    }
};


class Solution {
public:
    int titleToNumber(string s) {
        
        
        int len = s.size()-1;
        int num = 0;
        int result = 0;
        
        for(int i = 0; i < s.size(); i++)
        {
            num = pow (26,len--)*(s[i]-'A'+1);
            
            result += num;
        }
        
        return result;
    }
};



class Solution {
public:
    int titleToNumber(string s) {
        
        
        int len = s.size()-1;
        int num = 0;
        int result = 0;
        
        for(int i = 0; i < s.size(); i++)
        {
            num = pow (26,len--)*(s[i]-'A'+1);
            
            result += num;
        }
        
        return result;
    }
};


class Solution {
public:
    int titleToNumber(string s) {
        
        
        int len = s.size()-1;
        int num = 0;
        int result = 0;
        
        for(int i = 0; i < s.size(); i++)
        {
            num = pow (26,len--)*(s[i]-'A'+1);
            
            result += num;
        }
        
        return result;
    }
};



class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()<2)
            return;
        
        k %= nums.size();
        vector<int> _nums(nums.size());
        int n = nums.size() - k;
        int begin = 0;
        int count = 0;
        for(int i = 0;i<k;i++)
        {
            _nums[i] = nums[n];
            n++;
            count++;
        }
        
        for(int j = count;j<nums.size();j++)
        {
            _nums[j] = nums[begin];
            begin++;
        }
        
        for(int l = 0;l<nums.size();l++)
            nums[l] = _nums[l];
        
    }
};