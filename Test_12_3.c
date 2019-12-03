class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0)
            return 0;
        if(n == 1||n == 2)
            return 1;
        
        int a = 1,b = 1,num;
        for(int i = 3;i <= n;i++)
        {
            num = a + b;
            a = b;
            b = num;
        }
        return num;
    }
};

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int index_i = 0,index_j = 0;
        
        
        for(size_t i = 0;i < array[0].size()-1;++i)
            index_j++;
        
        while(index_j >= 0&&index_i < array.size())
        {
            if(array[index_i][index_j] > target)
                index_j--;
            else if(array[index_i][index_j] < target)
                index_i++;
            else
                return true;
        }
        
        return false;
    }
};