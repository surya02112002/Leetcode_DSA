class Solution {
public:
    bool check(int x, int len){
        if(x<0) return false;
        if (len == 0 || len == 1 ) return true;
        
        int last = x%10;
        int front = x/pow(10,(len-1));
        
        cout<<" "<<front <<" "<<last;
        if(last != front ) return false;
        else {
            x = x - front*(pow(10,len-1)); x=x/10; len = len-2;
            return check(x,len);
        };
    }

    bool isPalindrome(int x) {
        int len = to_string(x).length();
        return check(x, len);
    }
}; 