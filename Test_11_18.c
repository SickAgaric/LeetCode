class LCA {
public:
    int getLCA(int a, int b) {
        while(a!=b)
        {
            if(a<b)
                b /= 2;
            else
                a /=2;
        }
        return a;
    }
};

#include<iostream>

using namespace std;

int main()
{
    int num = 0;
    while(cin >> num)
    {
        int count = 0,max = 0;
        while(num)
        {
            if(num&1)
            {
                ++count;
                if(max < count)
                    max = count;
            }
            else
            {
                count = 0;
            }

            num = num >> 1;
        }
    
    cout << max << endl;
    }
    return 0;
}