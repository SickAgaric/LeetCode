#include<iostream>


using namespace std;
#define MAX(a, b)       (((a) > (b) ) ? (a) : (b))
#define MIN(a, b)       (((a) < (b) ) ? (a) : (b))
#define MID(a,b,c)      (MAX(a,b)>c?MAX(MIN(a,b),c):MIN(MAX(a,b),c))


int main()
{
    int n;
    cin >> n;
    
    int len = 3*n;
    int* a = new int [len];
    cin >> a >> endl;
    
    int i = 0;
    int* b = new int [3];
    int result = 0;
    while(i<len)
    {
        for(int i = 0;i < 3;i++)
        {
            b[i] = a[i];
        }
        result += MID(b[i],b[i+1],b[i+2]);
        
        i+=3;
    }
    return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> v;
    v.resize(3*n);
    
    for(int i = 0;i<3*n;i++)
    {
        cin >> v[i];
    }
    
    sort(v.begin(),v.end());
    
    long long sum = 0;
    
    for(int i = n;i<n*3;i+=2)
    {
        sum += v[i];
    }
    cout << sum;
    return 0;;
}