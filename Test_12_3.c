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