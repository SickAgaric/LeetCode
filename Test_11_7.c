#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str;
    
    getline(cin,str);
    
    string tmp,res;
    
    for(int i = 0;i < str.size();i++)
    {
        if(str[i] == ' ')
        {
            res = ' '+tmp+res;//这里不能用+=
            tmp = "";
        }
        else
        {
            tmp += str[i];
        }
    }
    
    if(tmp.size())
    {
        res = tmp+res;//注意+=用在这回发生错误，因为+=是追加字符串
    }
    
    cout << res << endl;
    return 0;
}