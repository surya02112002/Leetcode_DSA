class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = 0;
        for(int i=0; i<32; i++){
            if(num2 & (1<<i)){
                cnt++;
            }
        }
        

        int x = 0;
        for(int i=31; i>=0 && cnt > 0; i--){
            if(num1 & (1<<i)){
                x = x | (1<<i);
                cnt--;
            }
        }


        for(int i=0; i<32 && cnt > 0; i++){
            if(!(x & (1<<i))){
                x = x | (1<<i);
                cnt--;
            }
        }


        return x;
    }
};