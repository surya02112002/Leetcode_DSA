class Solution {
public:
    string largestOddNumber(string num) {
        if(num.back()%2!=0){
            return num;
        }
        else{
            int n= num.length()-1;
            while(n>=0){
                if(num[n]%2==0){
                    n--;
                }
                else{
                    return num.substr(0,n+1);
                }
            }
        }
        return "";
    }
};