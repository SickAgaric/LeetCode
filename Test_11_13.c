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