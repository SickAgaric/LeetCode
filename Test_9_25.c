class Solution {
public:
    string reverseStr(string s, int k) {
        /*if(s.size() < k)
        {
             reverse(s.begin(),s.end());
             return s;
        }*/
        
        int size = s.size();
        int i = 0;
        int time = s.size();
        int n = 0;
        
        while(size)
        {
            size /= (2*k);
            i++;
        }
        
        void my_reverse()
        {
            
        }
        
        while(1)
        {
            
            /*time -= (2*k);
            
            if(time<k)
            {
                
                reverse(n,s.end());
                return s;
            }
            
            else
            {
                
                reverse(n,n+k-1);
                n += (2*k);
            }*/
            
            
            
            if(time > (2*k))
            {
                //reverse(n,n+k-1);
                time -= (2*k);
                n += (2*k);
            }
            
            else
            {
                if((s.size() - n) > k)
                    //reverse(n,n+k-1);
                
                else
                    //reverse(n,(s.size() - 1));
                
                return s;
            }
            
        }
        
        
             
    }
};



class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i = 0;i < s.size(); i += 2*k)
        {
            if(i+2*k<=s.size() || i+k<=s.size())
                reverse(s.begin()+i,s.begin()+i+k);
            else
                reverse(s.begin()+i,s.end());
            
        }
        return s;
    }
};


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int num = nums[0];
        
        for(int i = 0;i<nums.size()-1; i++)
        {
            num ^= nums[i+1];
        }
        
        return num;
    }
};