//Method 1(best solution)
//直接生出答案
//           =>有些時候需要額外空間
//           =>觀察寫入跟讀取的位置，如果寫入的東西不會再被讀\就沒問題
void moveZeroes(int* nums, int numsSize){
    int j = 0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]!=0){
            nums[j]=nums[i];
            j++;
        }
    }
    while(j<numsSize){
        nums[j]=0;
        j++;
    }
    return ;
}

//Method 2 bubble sort conception
void moveZeroes(int* nums, int numsSize){
    while(true){
        int count = 0;
        for(int i = 0; i+1 < numsSize ; i++){
            if(nums[i]==0 && nums[i+1]!=0){
                nums[i]=nums[i+1];
                nums[i+1]=0;
                count++;
            }    
        }
        if (count==0){
            break;
        }
    }
    return ;
}
