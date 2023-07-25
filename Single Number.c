#Method 1
int singleNumber(int* nums, int numsSize){
    for (int i = 0 ; i < numsSize ; i ++){
        printf("%d\n", nums[i]);
        
        int count = 0 ;
        for (int j = 0 ; j < numsSize ; j++){
            if (nums[j] == nums [i]){
                count++;
            }
        }
        if (count == 1){
            return nums[i];
        }
    }
    return -1;
}

#Method 2(best solution) exclusive or
int singleNumber(int* nums, int numsSize){
    int n = nums[0] ;
    for (int i = 1; i< numsSize ; i++){
        n ^= nums[i];
    }
    return n;
}
