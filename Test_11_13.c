#include<iostream>

using namespace std;

int main()
{
    int N = 0;
    cin >> N;
    
    int x = 0,y = 1;
    int c = 0;
    
    while(1)
    {
        if(c >= N)
            break;
        c = x + y;
        x = y;
        y = c;
    }
    if((y-N)<(N-x))
        cout << (y-N);
    else
        cout << (N-x);
    return 0;
}


class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        
        int count = 0;
        
        auto it = A.begin();
        while(it != A.end())
        {
            if(*it == '(')
                count++;
            if(*it == ')')
                count--;
            it++;
        }
        return (count == 0);
    }
};


#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool Lex_Gra(vector<string> str)
{
    int i = 0;
    
    while((i+1) < str.size())
    {
        if(str[i].compare(str[i+1]) > 0)
            return false;
        i++;
    }
    return true;
}

bool Lengths(vector<string> str)
{
    /*int len = strlen(str[0]);
    
    for(int i = 1;i < str.size();i++)
    {
        if(len > strlen(str[i]))
            return false;
        len = strlen(strlen[i]);
    }*/
    int i = 0;
    
    while((i+1) < str.size())
    {
        if(str[i].size() > str[i+1].size())
            return false;
        i++;
    }
    return true;
}

int main()
{
    int n = 0;
    cin >> n;
    string s;
    vector<string> str;
    
    for(int i = 0;i < n;i++)
    {
        cin >> s;
        str.push_back(s);
    }
    
    Lex_Gra(str);
    Lengths(str);
    
    if(Lex_Gra(str) && Lengths(str))
        cout << "both";
    else if(Lengths(str) && !Lex_Gra(str))
        cout << "lengths";
    else if(!Lengths(str) && Lex_Gra(str))
        cout << "lexicographically";
    else
        cout << "none";
}

#include<iostream>

using namespace std;


int main()
{
    int A,B;
    
    cin >> A >> B;
    int i = 1;
    int n = 1;
    if(A<B)
    {
        int tmp = A;
        A = B;
        B = tmp;
    }
    while(i<A)
    {
        if(A%i == 0 && B%i == 0)
            n = i;
        i++;
    }
    
    cout << (((A/n)*(B/n)*n));
    return 0;
}