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