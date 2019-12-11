class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int ch_s[128] = {0};
        int ch_t[128] = {0};
        int size = s.size();
       for(int i = 0;i < size;++i)
       {
        //    if(s.find(s[i]) != t.find(t[i]))
        //         return false;
           ch_s[s[i]] += i+1;
           ch_t[t[i]] += i+1;
           
           if(ch_s[s[i]] != ch_t[t[i]])
                return false;
       } 
       return true;
    }
};