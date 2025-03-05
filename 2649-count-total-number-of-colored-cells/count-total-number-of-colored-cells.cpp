class Solution {
public:
    long long coloredCells(int n) {
        long long sum=0;
        if(n==1)
            return 1;
        sum=n;
        sum=sum*(n-1);
        sum=sum/2;
        return 1+4*sum;
    }
};