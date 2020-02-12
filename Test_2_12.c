#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    string s1,s2,s3;
    vector<int> arr;
    while(getline(cin,s1)&&getline(cin,s2))
    {
        for(int i = 0;i < s2.size();i++)
        {
            int pos = s1.find(s2[i],0);
            if(pos >= 0)
                arr.push_back(pos);
        }
        int index = 0;
        sort(arr.begin(),arr.end());
        for(int j = 0;j < s1.size();j++)
        {
            if(j == arr[index])
                index++;
            else
                s3.push_back(s1[j]);
        }
        cout << s3 << endl;
    }
    return 0;
}


#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int arr[n];
    int sum = 0,maxarr = -1e5;
    for(int i = 0;i < n;i++)
    {
        cin >> arr[i];
        sum += arr[i];
        if(sum > maxarr)
            maxarr = sum;
        if(sum < 0)
            sum = 0;
    }
    cout << maxarr;
    return 0;
}