class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() <= 1)
            return;
        int tmp1 = 0,tmp2 = 0,end = 0;
        k %= (nums.size());
        for(int i = 0;i < k;i++)
        {
            end = nums[nums.size()-1];
            tmp1 = nums[0];
            for(int j = 1;j < nums.size();++j)
            {
                tmp2 = nums[j];
                nums[j] = tmp1;
                tmp1 = tmp2;
            }
            nums[0] = end;
        }
    }
};

class Solution {
public:
    void swap(int *a,int *b)
    {
        int k = 0;
        k = *a;
        *a = *b;
        *b = k;
    }
    void rotate(vector<int>& nums, int k) {
        if(nums.size() <= 1)
            return;
        if(nums.size() <= 2)
        {
            if(k%2 == 1)
            {
                int k = 0;
                swap(&nums[0],&nums[1]);
                printf("aaa");
            }
        }
        int begin = 0,end = nums.size() - 1;
        int tmp = 0;
        for(int i = 0;i < nums.size()/2;++i)
        {
            swap(&nums[begin],&nums[end]);
            begin++;
            end--;
        }

        begin = 0;
        end = k-1;
        for(int i = 0;i < k/2;i++)
        {
            swap(&nums[begin],&nums[end]);
            begin++;
            end--;
        }

        begin = k;
        end = nums.size() - 1;
        for(int i = 0;i < (nums.size()-k)/2;++i)
        {
            swap(&nums[begin],&nums[end]);
            begin++;
            end--;
        }
    }
};