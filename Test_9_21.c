#include<iostream>
#include<string>

using namespace std;

int main()
{
    
    
    string s;
    while(cin>>s)
    {
    int i = 0;
    for(i = 0; i<s.size(); i++)
    {
        if(s.find(s[i]) == s.rfind(s[i]))
        {
            cout<<s[i]<<endl;
            break;
        }
        
    }
    
    
    if(i == s.size())
        cout<<"-1";
    }
    return 0;
}

#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		int time = 0;

		for (int j = i + 1; j < s.size(); j++)
		{
			if (s[i] == s[j])
			{
				time++;
				s[j] = '\0';
			}

		}
		if (time == 0)
		{
			cout << s[i] << endl;
			break;
		}
	}

	cout << "-1" << endl;


	system("pause");
	return 0;
}


#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str;
    getline(cin,str);
    //cin>>str;
    if(!str.find(' ',0))
        cout<<str.size()<<endl;
    
    size_t pos = str.rfind(' ');
    
    string _str = str.substr(pos+1,str.size());
    cout<<_str.size()<<endl;
    
    return 0;
}