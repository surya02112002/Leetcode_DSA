class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n= text.length();
        int ans=0;
        int cntb=0, cnta=0,cntl=0,cnto=0,cntn=0;
        for(int i=0;i<n;i++){
            if(text[i]=='b'){
                cntb++;
            }
            if(text[i]=='a'){
                cnta++;
            }
            if(text[i]=='l'){
                cntl++;
            }
            if(text[i]=='o'){
                cnto++;
            }if(text[i]=='n'){
                cntn++;
            }
            if(cntb >=1 && cnta >=1 && cntl>=2 && cnto>=2 && cntn>=1){
            ans++;
            cntb--;
            cnta--;
            cntl=cntl-2;
            cnto=cnto-2;
            cntn--;
        }
        }
        
        return ans;
    }
};