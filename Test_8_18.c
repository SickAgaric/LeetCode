int search(int* nums, int numsSize, int target){
    int left, right, mid;
    left = 0; right = numsSize - 1;
    while(left <= right){
        mid = left + (right - left) / 2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] < nums[right] && nums[mid] < target && target <= nums[right]){
            left = mid + 1;
        }else if(nums[left] < nums[mid] && nums[left] <= target && target < nums[mid]){
            right = mid - 1;
        }else{
            if(nums[mid] > nums[right]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
    }
    return -1;
}
