class Solution {
public:
    	bool validMountainArray(vector<int>& A) {
		if (A.size() < 3)
			return false;

		int max = A[0];
		int index = 0;
		for (int i = 1; i < A.size(); ++i)
		{
			if (A[i] > max)
			{
				index = i;
				max = A[i];
			}
		}
//------------------------------------------判断临界条件，升序或者降序
        if(index == 0)
            return false;

		if (index == (A.size() - 1))
			return false;


		for (int i = 0; i < index - 1; ++i)
		{
			if (A[i] >= A[i + 1])
				return false;
		}

		for (int i = index; i < A.size() - 1; ++i)
		{
			if (A[i] <= A[i + 1])
				return false;
		}

		return true;
	}
};
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        if(nums.size() == 0)
            return false;
        sort(nums.begin(),nums.end());

        int i = 0;
        int min = 0;

        for(int i = 0;i<nums.size();i+=2)
            min += nums[i];

        return min;
    }
};
