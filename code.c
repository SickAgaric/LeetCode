class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        //此题目自我困难之处，是对二维数组的行、列掌握不到位
        //对于求行，求列知识点遗忘
        int rowCount = array.size();//行
        int colCount = array[0].size();//列
        
        int i = rowCount - 1;
        int j = 0;
        
        
        while(i >= 0 && j < colCount)//注意对边界条件的判断
        {
            if(target == array[i][j])
                return true;
            if(target < array[i][j])
                i--;
            else if(target > array[i][j])
                j++;
        }
        return false;
        //25minutes
    }
};

class Solution {
public:
	void replaceSpace(char *str,int length) {
        //自己对字符类的操作掌握及其不好
        //看过答案之后，恍然大悟，char类型是内置类型，他不是自定义类型，没有任何的运算符重载，
        //所以在修改char类型的字符串的时候，此题的操作就是覆盖
        int count = 0;
        int str_len = 0;
        int i = 0;
        while(str[i] != '\0')
        {
            str_len++;
            
            if(str[i] == ' ')//此处*str未改变为str[i]导致count为0，结果出错
                count++;
            i++;
        }
        
        /*while(*str++ != '\0')
        {
            str_len++;
            
            if(*str == ' ')//此处*str未改变为str[i]导致count为0，结果出错
                count++;
        }*/
        
        int new_len = str_len + count * 2;
        if(new_len > length)
            return;
        
        
        while(str_len >= 0)
        {
            if(str[str_len] == ' ')
            {
                str[new_len--] = '0';
                str[new_len--] = '2';
                str[new_len--] = '%';
            }
            else{
                str[new_len--] = str[str_len];
            }
            str_len--;
        }
	}
};










class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int left = 0;
        int right = rotateArray.size() - 1;
        int mid = 0;
        
        while(left < right)
        {
            mid = (left+right)/2;
            if(rotateArray[mid] > rotateArray[right])
                left = mid+1;
            else if(rotateArray[mid] < rotateArray[right])
                right = mid;//存在数组[5,7]这种长度为2的情况
            else
                right -=1;
        }
        return rotateArray[left];
   }
};


class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0)
            return 0;
        if(n <= 2)
            return 1;
        
        int n1 = 1;
        int n2 = 1;
        int sum = 0;
        
        int count = n - 2;
        while(count--)
        {
            sum = n1+n2;
            n1 = n2;
            n2 = sum;
        }
        return sum;
    }
};


/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> arr1;
        while(head)
        {
            arr1.push_back(head->val);
            head = head->next;
        }
        
        int time = arr1.size()/2;
        int begin = 0;
        int end = arr1.size() - 1;
        while(time--)
        {
            int tmp = arr1[begin];
            arr1[begin] = arr1[end];
            arr1[end] = tmp;
            begin++;
            end--;
        }
        //reverse(arr1.begin(),arr1.end());
        
        return arr1;
    }
};


class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int num = stack2.top();
        stack2.pop();
        
        return num;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};


class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         if(n < 0)
         {
             n = n & 0x7FFFFFFF;
             count++;
         }
         while(n)
         {
             count += (n & 1);
             n = n >> 1;
         }
         return count;
     }
};

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int begin = 0;
        int end = array.size() - 1;
        int tmp = 0;
        while(begin <= end)
        {
            if(array[begin] % 2 != 0)
                begin++;
            if(array[end] % 2 == 0)
                end--;
            if(array[begin] % 2 == 0 && array[end] % 2 != 0)
            {
                tmp = array[begin];
                array[begin] = array[end];
                array[end] = tmp;
            }
        }
    }
};
		

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> odd;
        vector<int> even;
        for(int i = 0;i < array.size();i++)
        {
            if(array[i] % 2 != 0)
                odd.push_back(array[i]);
            else
                even.push_back(array[i]);
        }
        for(int i = 0;i < even.size();i++)
            odd.push_back(even[i]);
        array = odd;
    }
};		
		
		class Solution {
public:
    void reOrderArray(vector<int> &array) {
        queue<int> odd;
        queue<int> even;
        for(int i = 0;i < array.size();i++)
        {
            if(array[i] % 2 != 0)
               odd.push(array[i]);
            else
               even.push(array[i]);
        }
        for(int i = 0;i < array.size();++i)
        {
            if(!odd.empty())
            {
                array[i] = odd.front();
                odd.pop();
            }
            else
            {
                array[i] = even.front();
                even.pop();
            }
        }
    }
};

class Solution {
public:
    double Power(double base, int exponent) {
        if(base == 0 && exponent != 0)
            return 0;
        else if(base != 0 && exponent == 0)
            return 1;
        else
        {
            double result = base;
            int sign = 0;
            if(exponent < 0)
            {
                sign = 1;
                exponent *= -1;
            }
            for(int i = 0;i < exponent - 1;++i)
            {
                result *= base;
            }
            if(sign == 0)
                return result;
            else
                return 1/result;
        }
    }
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        stack<int> s1;
        ListNode* tmp = pHead;
        while(tmp)
        {
            s1.push(tmp->val);
            tmp = tmp->next;
        }
        tmp = pHead;
        while(tmp)
        {
            tmp->val = s1.top();
            s1.pop();
            tmp = tmp->next;
        }
        return pHead;
    }
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
       if(pHead == NULL)
           return NULL;
        ListNode* cur = pHead;
        ListNode* pre = NULL;
        ListNode* next = NULL;
 
        while(cur)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
	vector<int> arrayRankTransform(vector<int>& arr) {
		set<int> sort_set;

		for (auto e : arr)
			sort_set.insert(e);

		vector<int> newArr;
		vector<int> indexArr;

		for (auto e : sort_set)
			newArr.push_back(e);

		for (int i = 0; i < arr.size(); ++i)
		{
			int index = 0;
			while (1)
			{
				if (arr[i] == newArr[index])
				{
					indexArr.push_back(index+1);
					break;
				}
				index++;
			}
		}
		return indexArr;
	}
};

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n < 1)
            return 0;
        
        int count = 0;
        for(int i = 1;i <= n;++i)
        {
            int tmp = i;
            while(tmp)
            {
                if(tmp % 10 == 1)
                    count++;
                tmp /= 10;
            }
        }
        return count;
    }
};
#define forp(i,s,n) for(int i=(s);i<(n);i++)
class Solution {
public:
    string reorganizeString(string S) {
        
//记录字母数并降序排列
        vector<pair<char,int>> h(26,make_pair('a',0));
        
        for(int i=0;i<26;i++)
            h[i].first+=i;
        for(char p:S)
            h[p-'a'].second++;
        sort(h.begin(),h.end(),[](pair<char,int> a,pair<char,int> b){return a.second>b.second;});
        
//判断是否能够重构
        if(h[0].second>(S.size()+1)/2)
            return "";
        
//答案有size个字符串拼接而成，轮转排入。
        int size=h[0].second;
        vector<string> ans(size);
        int l=0;
        
        forp(i,0,26){
            int n=h[i].second;
            forp(j,0,n){
                ans[l++%size].push_back(h[i].first);
            }
        }
        
        string res;
        forp(i,0,size){
            res+=ans[i];
        }
        
        return res;
    }
};



#include<vector>
#include<iostream>

using namespace std;


#define Size 3
#define TimeRange 2
#define TimeDay 24

int Calculation(int time)
{
	return time /= (60 * 60);
}

int main()
{
	//构建数组
	int num = 0;
	cin >> num;

	vector<vector<int>> v;
	v.resize(num);

	for (int i = 0; i < v.size(); ++i)
	{
		v[i].resize(3);
		for (int j = 0; j < Size; ++j)
		{
			cin >> v[i][j];
		}
	}

	vector<int> arrT;
	arrT.resize(TimeDay);

	//计算
	for (int i = 0; i < num; ++i)
	{
		int time = Calculation(v[i][1]), money = v[i][2];

		arrT[time] += money;

		if ((time - 1) < 0)
			time = TimeDay - 1;
		arrT[time] += money;
	}


	int resTime = 0, resMoney = arrT[0];
	int index = 0;
	for (int i = 1; i < TimeDay; ++i)
	{
		if (resMoney < arrT[i])
		{
			resMoney = arrT[i];
			index = i;
		}
	}

	for (int i = 0; i < num; ++i)
	{
		if (Calculation(v[i][1]) == index || (Calculation(v[i][1]) - 1) == index)
		{
			resTime = Calculation(v[i][1]);
			break;
		}
	}
	cout << resTime << resMoney << endl;

	return 0;
}


//int main()
//{
//	int n, m;
//	cin >> n >> m;
//
//	vector<vector<int>> v;
//
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < m; ++j)
//		{
//			cin >> v[i][j];
//		}
//	}
//
//	/*2 3
//	0 1 1
//	1 1 0*/
//
//
//	return 0;
//}
### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        if(nums1.size() < 1 && nums1.size() > 0)
        {
            if(nums2.size() % 2 == 1)
                return (double)nums2[nums2.size()/2];
            else
                return (((double)nums2[nums2.size()/2-1] + (double)nums2[nums2.size()/2]) / 2);
        }
        if(nums2.size() < 1 && nums1.size() > 0)
        {
            if(nums1.size() % 2 == 1)
                return (double)nums1[nums1.size()/2];
            else
                return (((double)nums1[nums1.size()/2-1] + (double)nums1[nums1.size()/2]) / 2);
        }
        
        int index1 = 0,index2 = 0;
        while(index1 < nums1.size() && index2 < nums2.size())
        {
            if(nums1[index1] <= nums2[index2])
                res.push_back(nums1[index1++]);
            else
                res.push_back(nums2[index2++]);
        }

        if(index1 == nums1.size())
        {
            while(index2 < nums2.size())
                res.push_back(nums2[index2++]);
        }

        if(index2 == nums2.size())
        {
            while(index1 < nums1.size())
                res.push_back(nums1[index1++]);
        }

        int len = nums1.size() + nums2.size();

        double n = 0;
        if((len % 2) == 1)
            return (double)(res[len/2]);
        else
            return (((double)res[len/2-1] + (double)res[len/2]) / 2);
    }
};
```
