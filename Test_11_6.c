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

#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    
    int len = 0;
    int _len = 0;
    string tmp;
    string res;
    for(int i = 0;i < str.size();i++)
    {
        len = 0;
        while(str[i]>='0' && str[i]<='9')
        {
            tmp += str[i];
            i++;
            len++;
        }
        
        if(_len < len)
        {
            _len = len;
            res = tmp;
        }
        tmp = "";
    }
    cout << res <<endl;
}

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        
        if(numbers.empty())
            return 0;
        sort(numbers.begin(),numbers.end());
        
        int mid = numbers[numbers.size()/2];
        int time = 0;
        
        for(int i = 0;i<numbers.size();++i)
        {
            if(numbers[i] == mid)
            {
                time++;
            }
        }
        
        return (time>numbers.size()/2) ? time : 0;
        /*int num = 0;
        auto it = numbers.begin();
        
        vector<int> arr;
        while(it != numbers.end())
        {
            arr[*it]++;
            it++;
        }
        
        auto _it = arr.begin();
        
        for(int i = 0;i<arr.size();i++)
        {
            if(arr[i] > (numbers.size()/2))
                num = i;
        }
        
        return num;*/
        /*int a[10];
        for(int j = 0;j<10;j++)
        {
            a[j] = 0;
        }
        int num = 0;
        auto it = numbers.begin();
        
        while(it != numbers.end())
        {
            a[*it]++;
            it++;
        }
        
        for(int i = 0;i < 10;i++)
        {
            if(a[i] > (numbers.size()/2))
            {
                num = i;
            }
        }
        cout << num;
    }*/
    }
};