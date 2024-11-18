class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1= s.length();
        int n2= t.length();
        int i=0; 
        int j=0;
        while(i<n1 &&j<n2 ){
            if(s[i]==t[j]){
                i++;
                
            }
            j++;
        }
        return i==n1;
    }
};