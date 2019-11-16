class UnusualAdd {
public:
    int addAB(int A, int B) {
        // write code here
        int Xor, And;
        while(B != 0){
            Xor = A^B;
            And = (A&B)<<1;
            A = Xor;
            B = And;
        }
        return A;
    }
};

#include<iostream>


using namespace std;

int Get_step(int n,int m)
{
    if(m == 0||n == 0)
        return 1;
    return Get_step(n,m-1)+Get_step(n-1,m);
}

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
    cout << Get_step(n,m) << endl;
    
    }
    return 0;
}

class Solution {
public:
    string LeftRotateString(string str, int n) {
        /*for(int i = 0;i < n;i++)
        {
            char a = str[0];
            str[0] = str[(str.size()-1)];
            str[(str.size()-1)] = a;
        }*/
        /*string new_str;
        for(int i = n;i<str.size();i++)
        {
            new_str.push_back(str[i]);
        }
        
        for(int i = 0;i<n;i++)
        {
            new_str.push_back(str[i]);
        }
        str = new_str;*/
        
        
        
    }
};