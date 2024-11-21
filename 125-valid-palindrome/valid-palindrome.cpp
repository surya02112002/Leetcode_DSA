class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        string a;
        string b;
        for(int i=0; i<n ;i++){
            if(isalpha(s[i])|| isdigit(s[i])){
                a.push_back(tolower(s[i]));
            }
        }
        b=a;
        reverse(a.begin(),a.end());
        return a==b;
        
    }
};