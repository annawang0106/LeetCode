// function，用來執行#刪除的動作，為了達成空間複雜度O(1)，在同一個字串上做讀寫。
char* process(char* str){
    int str_length = strlen(str);
    char* result=str;
    int j=0;
    for(int i=0; i<str_length;i++){
        if(str[i]!='#'){
            str[j]=str[i];
            j++;
        }else{
            if(j>0){
                j--;
            }
        }
    }
    result[j]="\0";
    return result; 
}

//比較兩個字串(s,t)是否相等
bool backspaceCompare(char * s, char * t){
   return strcmp(process(s),process(t))==0;
}
