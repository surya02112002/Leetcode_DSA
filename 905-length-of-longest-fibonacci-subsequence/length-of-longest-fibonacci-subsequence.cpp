class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        unordered_set<int>st;
        int maxLen=0;
        for(int i=0;i<n;i++) st.insert(arr[i]);
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=0;j--){
                int a=arr[i];
                int b=arr[j];
                int len=2;
                int diff=a-b;
                while(st.count(diff) && diff!=a && diff!=b && diff<b) {
                    len++; 
                    a=b;
                    b=diff;
                    diff=a-b;
                }
                maxLen=max(maxLen,len);
            }
        }
        if(maxLen<3) return 0;
        return maxLen;
    }

};