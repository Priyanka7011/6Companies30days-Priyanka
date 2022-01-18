int atoi(string str) {
        //Your code here
        int temp=1;
        int num=0;
        int sign=1;
        for(auto s:str){
            
            if(isdigit(s))
            num = num*10 + s-'0';
            else if(s=='-'){
                sign=-1*sign;
            }
            else{
                return -1;
            }
            
            
        }
        
        return num*sign;
    }