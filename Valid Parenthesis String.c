//注意字串要用''
//因為*可表示()*，因此需用maxcount及mincount區間
bool checkValidString(char * s){
    int maxcount =0;
    int mincount =0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='('){
            maxcount++;
            mincount++;
        }else if(s[i]==')'){
            maxcount--;
            mincount--;
        }else if(s[i]=='*'){
            maxcount++;
            mincount--;
        }
        if(maxcount<0){
            return false;
        }
        if(mincount<0){
            mincount=0;
        }
    }
    return mincount == 0;
}
