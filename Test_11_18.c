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

//最近公共祖先
class LCA {
public:
    int getLCA(int a, int b) {
        vector<int> path_a;
        vector<int> path_b;
        //创建a,b的路径
        path_a.push_back(a);
        path_b.push_back(b);
        
        while(a >= 1)
        {
            a /= 2;
            path_a.push_back(a);
        }
        while(b >= 1)
        {
            b /= 2;
            path_b.push_back(b);
        }
        
        int i,j;
        i = path_a.size() - 1;//数组下标
        j = path_b.size() - 1;
        
        while(i >= 0 && j >= 0)//如果其中一个结束，那么祖先肯定是根结点
        {
            if(path_a[i] == path_b[j])
            {
                --i;
                --j;
            }
            else
                return path_a[++i];//不相等，由于左边小于右边，返回左边的上一个结点，就是他们的公共祖先
        }
        return 1;
        
    }
};