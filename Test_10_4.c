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






