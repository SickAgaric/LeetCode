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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL)
            return pHead2;
        else if(pHead2 == NULL)
            return pHead1;
        else if(pHead1 == NULL && pHead2 == NULL)
            return NULL;
        
        ListNode* new_list = nullptr;
        if(pHead1->val < pHead2->val)
        {
            new_list = pHead1;
            pHead1 = pHead1->next;
        }
        else
        {
            new_list = pHead2;
            pHead2 = pHead2->next;
        }
        
        while(pHead1 && pHead2)
        {
            if(pHead1 < pHead2)
            {
                new_list->next = pHead1;
                new_list = new_list->next;
                new_list->next = pHead2;
            }
            else
            {
                new_list->next = pHead2;
                new_list = new_list->next;
                new_list->next = pHead1;
            }
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        
        if(pHead1)
        {
            new_list->next = pHead1;
        }
        else if(pHead2)
        {
            new_list->next = pHead2;
        }
        else
        {
            new_list->next = NULL;
        }
        
        return new_list;
    }
};
