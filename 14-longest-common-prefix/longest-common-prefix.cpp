class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        sort(strs.begin(), strs.end());
        int n= strs.size();
        string first = strs[0];
        string last= strs[n-1];
        for(int i=0; i<min(first.length(), last.length());i++){
            if(first[i]== last[i] )
                ans+= last[i];
            else
                return ans;
        }
        return ans;
    }
};