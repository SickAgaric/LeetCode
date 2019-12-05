class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        /*vector<int> v;
        if(input.empty() || k > input.size())
            return v;
        
        sort(input.begin(),input.end());
        
        
        
        for(int i = 0;i < k;++i)
            v.push_back(input[i]);
        return v;*/
         vector<int> v;
        if(input.empty() || k > input.size())
            return v;
        
        priority_queue<int, vector<int>, greater<int>> q1(input.begin(), input.end());
        
        
        for(int i = 0;i < k;i++)
        {
            
            v.push_back(q1.top());
            q1.pop();
        }
        
        return v;
        
    }
};

#include<iostream>
#include<string>

using namespace std;

string string_sum(string& s1,string& s2)
{
    int len1 = s1.size() - 1;
    int len2 = s2.size() - 1;
    int t = 0;
    string res;
    int i,j;
    for(i = len1,j = len2;i >= 0&&j >= 0;i--,j--)
    {
        t += ((s1[i] - '0') + (s2[j] - '0'));
        res = (char)(t%10 + '0') + res;
        t /= 10;
    }
    
    while(i >= 0)
    {
        t += ((s1[i]) - '0');
        res = (char)(t + '0') + res;
        t /= 10;
        i--;
    }
    
    while(j >= 0)
    {
        t += ((s2[j]) - '0');
        res = (char)(t + '0') + res;
        t /= 10;
        j--;
    }
    
    if(t > 0)
        res = (char)(t + '0') + res;
    
    return res;
}

bool compare(string s1,string s2)
{
    if(s1.size() > s2.size())
        return true;
    else if(s1.size() < s2.size())
        return false;
    else
        return s1 > s2;
}

int main()
{
    string a,b,c;
    while(cin >> a >> b >> c)
    {
        /*if(a.size() + b.size() > c.size() && a.size() - b.size() < c.size())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;*/
        
        if(compare(string_sum(a,b),c) && compare(string_sum(b,c),a) &&compare(string_sum(a,c),b))//2.与第三项比较
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}