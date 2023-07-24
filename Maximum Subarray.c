int maxSubArray(int* nums, int numsSize){
    int max = nums[0]; // 目前為止的最大值
    //選擇一個起點I
    for(int i = 0 ; i < numsSize ; i++){
        int sum = 0;
        //選擇一個終點J
        for(int j = i ; j < numsSize ; j++){
            //計算從起點到終點的和
            sum += nums[j];
            //如果比原本的最大值大，就換掉
            if(sum>max){
                max = sum;
            }
        }
    }
    return max;
}
