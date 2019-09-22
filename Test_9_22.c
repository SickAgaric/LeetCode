class Solution {
public:
    string addStrings(string num1, string num2) {
        
        
        
        */string str;
        int sign = 0;
        int end1 = num1.size()-1;
        int end2 = num2.size()-1;

        while(end1>=0||end2>=0||sign!=0)
        {
            
            if(end1>=0)
                sign += num1[end1--] - '0';
            if(end2>=0)
                sign += num1[end2--] - '0';
            
            str += to_string(sign%10);
            //str.push_back((sign%10)+'0');
            sign/=10;
           /* int n3 = n2+n1;
            
            
            if(sign==1)
            {
                n3++;
                sign--;
            }
                
            
            if(n3 > 10)
                sign++;
            
            
            
            str.push_back(((n3%10)+'0'));
            end1--;
            end2--;*/
        }
        reverse(str.begin(),str.end());
        return str;*/
		
		class Solution {
public:
    string addStrings(string num1, string num2) {
        string str;
        
        int n = 0;
        int n1 = num1.size() -1;
        int n2 = num2.size() -1; 
        
        while(n1>=0 || n2>=0 || n!=0)
        {
            if(n1>=0)
                n += num1[n1--] - '0';
            if(n2>=0)
                n += num2[n2--] - '0';
            
            str += to_string(n%10);
            
            n/=10;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
    }
};


class Solution {
public:
    bool isPalindrome(string s) {
         /*int len = s.size();
        string new_str = new string();
        int j = 0;
        for(int i = 0; i<s.size(); i++)
        {
            if(s.[i]>65 && s.[i]<90)
            {
                
                new_str[j] = s.[i];
                j++
            }
            if(s.[i]>97 && s[i]<122)
            {
                new_str[j] = s.[i] -32;
                j++;
            }
        }
        
        for(int _i = 0; _i<new_str.size()/2; _i++)
        {
            int _j = new_str.size();
            if(new_str[i]!=new_str[_j])
                return false;
        }
        return true;
    }*/
        if(s.size()<2)
            return true;
        
        string str;
        
        for(auto a:s)
        {
            if(a>=48 && a<=57 || a>=97 && a<=122)
                str.push_back(a);
            if(a>=65 && a<=90)
                str.push_back(a+32);
        }
        
        int i = 0;
        int j = str.size()-1;
        
        while(i<j)
        {
            if(str[i++]!=str[j--])
                return false;
        }
        
        return true;
    }
};