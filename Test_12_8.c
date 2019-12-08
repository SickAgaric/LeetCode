// write your code here cpp
#include<iostream>

using namespace std;


int main()
{
    int n;
    while(cin >> n)
    {
        if(n == 0)
            break;
        else if(n == 2 || n == 3)
            cout << 1 << endl;
        else 
        {
            int count = 0;
            while(n > 1)
            {
                if(n%3 == 0)
                    n /= 3;
                else
                    n = n/3+1;
                count++;
            }
            cout << count << endl;
        }
    }
}