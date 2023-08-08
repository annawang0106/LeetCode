int extraMax(int* stones, int stonesSize){         //此function用來找出最大值的index
    int max_i = 0;                                 
    for (int i=1;i<stonesSize;i++){
        if(stones[i]>stones[max_i]){
            max_i = i;
        } 
    }

    int max = stones[max_i];                      //將最大值index存入max變數
    stones[max_i] = 0;                            //最大值index內容設為0
    return max;
}

void insert(int*stones, int stonesSize, int value){  //此function用來插入y-x後的值，插入在index為0的欄位
    for(int i=0; i <stonesSize;i++){                 
        if(stones[i]==0){
            stones[i] = value;
            return;
        }
    }
}

int lastStoneWeight(int* stones, int stonesSize){
    while(true){
        int y = extraMax(stones,stonesSize);         //extraMax function用於取第一大數
        int x = extraMax(stones,stonesSize);         //extraMax function用於取第二大數
    
        if (x==0){                                   //如果陣列中y=Value，x=0或者y、x=0，都return y
            return y;                            
        }if (x !=y ){                                //如果陣列中x、y都有不為0的value，用insert function
            insert(stones, stonesSize, y-x);
         }
    }
    return 0;
}
