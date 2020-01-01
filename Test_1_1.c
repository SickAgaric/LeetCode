class Solution {
public:
    int findminList(vector<int>mArray, int left, int right)
    {
        int min = mArray[left];
        for (int i = left; i <= right; i++)
        {
            if (mArray[i] < min)
            {
                min = mArray[i];
            }
        }
        return min;
    }
 
    int minNumberInRotateArray(vector<int> rotateArray) {
        int index_left = 0, index_right = rotateArray.size()-1;
        int index_mid = 0;
        //旋转0个元素，依然为旋转数组
        if (rotateArray.size() < 1) return NULL;
        if (rotateArray[index_left] < rotateArray[index_right])
        {
            return rotateArray[index_left];
        }
         
        while (index_right-index_left>1)
        {
            index_mid = (index_left + index_right) / 2;
 
            if (rotateArray[index_left] == rotateArray[index_mid] && rotateArray[index_left] == rotateArray[index_right])
                return findminList(rotateArray, index_left, index_right);
            if (rotateArray[index_mid] >= rotateArray[index_left])
                index_left = index_mid;
            else if(rotateArray[index_mid]<=rotateArray[index_right])
            {
                index_right = index_mid;
            }
        }
        return rotateArray[index_right];
    }
};