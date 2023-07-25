//Method 1
//如果n=19
int next_n(int n){  //回傳下一個n
    int r = 0;
    while(n!=0){
        int d = n % 10;  //d=9 ; d=1
        n /= 10;         //n=1 ; n=0
        r += d*d;        //r=81; r=82
    }
    return r;
}

bool contains(int *history, int size , int n){ //檢查n是否在history出現過
    for (int i = 0; i < size ;i++){
        if(history[i]==n){
            return true;
        }
    }
    return false;
}

bool isHappy(int n){
    int history[1000]; //去過哪裡
    int size = 0;      //總共幾個地方

    while(!contains(history,size,n)){
        history[size] = n;
        size++;
        n = next_n(n); 
    }
    return n == 1;
}

//Method 2
int next_n(int n){  //回傳下一個n
    int r = 0;
    while(n!=0){
        int d = n % 10;  //d=9 ; d=1
        n /= 10;         //n=1 ; n=0
        r += d*d;        //r=81; r=82
    }
    return r;
}

bool isHappy(int n){
    int slow = n;
    int fast = n;
    do{
        int slow = next_n(slow);
        int fast = next_n(next_n(fast));
    }while(slow != fast);
    return fast == 1;
}
