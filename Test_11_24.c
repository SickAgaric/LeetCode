class Solution {
public:
    string intToRoman(int num) {
        vector<string> digit2mode={"","0","00","000","01","1","10","100","1000","02"};
        vector<string> pos2char = {"IVX","XLC","CDM","M"};
        string ans;
        for(int i=0;num;i++)
        {
            int digit = num%10;
            num/=10;
            if(digit==0) continue;
            string s;
            for(int j=0;j<digit2mode[digit].size();j++)
            {
                s+=pos2char[i][digit2mode[digit][j]-'0'];
            }
            ans=s+ans;
        }
        return ans;
    }
};