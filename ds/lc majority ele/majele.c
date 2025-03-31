int majorityElement(int* nums, int numsSize) {
    int ele;
    int count;
    for(int i = 0; i<numsSize; i++)
    {
        count = 0;
        if(nums[i]==ele){
        continue;
        }
        ele = nums[i];
        for(int j = 0;j<numsSize;j++)
        {
            if(nums[j]==ele)
                count++;
        }
        if (count>(numsSize/2))
        {
            return ele;
            break;
        }

    }
    return ele;
}
