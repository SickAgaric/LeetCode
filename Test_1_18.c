class Solution {
public:
    string toLowerCase(string str) {
        if(str.size() == 0)
            return NULL;
        for(int i = 0;i < str.size();++i)
        {
            if(str[i] >= 'A' && str[i] <= 'Z')
                str[i] += 32;
        }
        return str;
    }
};