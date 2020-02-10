class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        string str;
        //sprintf(str,"%d",data);
        //itoa(x,str,10);
        while(x)
        {
            str = ((char)(x%10)) + str;
            x /= 10;
        }

        int begin = 0;
        int end = str.size() - 1;
        while(begin <= end)
        {
            if(str[begin++] != str[end--])
                return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || x%10 == 0 && x!=0)//负数和末尾为0的都不是回文数
            return false;

        int revertedNumber = 0;
        while(x > revertedNumber)
        {
            revertedNumber = revertedNumber*10 + x%10;
            x /= 10;
        }

        return x == revertedNumber || x == (revertedNumber/10);
    }
};


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int arr[26] = {0};
        
        for(auto j :magazine)
        {
            arr[j-'a']++;
        }

        
        for(auto i : ransomNote)
            arr[i-'a']--;

        //magazine在前，因为如果顺序调换，那么可能会存在一直false的情况
        
        for(int i = 0;i < 26;++i)
        {
            if(arr[i] < 0)
                return false;
        }
        printf("%d",arr[0]);

        return true;
    }
};