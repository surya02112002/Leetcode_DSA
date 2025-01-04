class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>first(26,INT_MAX);
        vector<int>last(26,INT_MIN);
        int result = 0;

        for(int i = 0 ;i<s.size() ;i++){
            first[s[i]-'a'] = min(first[s[i]-'a'],i);
            last[s[i]-'a'] = max(last[s[i]-'a'],i);
        }

        for(int i = 0;i<26;i++){
            if(first[i] == INT_MAX || last[i] == INT_MIN) continue;

            unordered_set<char>uniqueChar;
            for(int j = first[i]+1;j<last[i];j++){
                uniqueChar.insert(s[j]);
            }

            result +=uniqueChar.size();
        }
        return result;
    }
};