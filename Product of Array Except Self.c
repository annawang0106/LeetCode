/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//思路:i=nums[0]*nums[1]*.....nums[i-1]*nums[i+1]*.....nums[nums-1]
//       [      right                 ][          left            ] 
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;                                        //回傳result陣列大小與numsSize相等
    int* result = malloc(sizeof(int)*numsSize);                    //配置記憶體
    result[numsSize-1] = 1;                                        //計算right
    for(int i=numsSize-2;i>=0;i--){
        result[i] = result[i+1]*nums[i+1];
    }

    int lefts=1;                                                   //計算left
    for(int i=0;i<numsSize;i++){
        result[i] = lefts*result[i];
        lefts = lefts*nums[i];
    }
    return result;
}
