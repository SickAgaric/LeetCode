class Solution {
public:
    int countPrimes(int n) {
        if(n < 3)
            return 0;
        int count = 1;
        for(int i = 3;i < n;i++)
        {
            bool sign = true;

            for(int j = 2;j*j <= i;j++)
            {
                if(i%j == 0)
                {
                    
                    sign = false;
                    break;
                }

            }
            if(sign)
                count++;
        }
        return count;
    }
};


#include<iostream>

using namespace std;

int main()
{
	int j;
	int n = 0;
	cin >> n;
	if (n >= 2)
		cout << 2 << "  ";
	for (int i = 2; i <= n; i++)
	{
		for (j = 2; j*j <= i; j++)
		{
			if (i%j == 0)
				break;
		}

		if (i%j != 0)
			cout << i << "  ";

	}
	system("pause");
	return 0;
}