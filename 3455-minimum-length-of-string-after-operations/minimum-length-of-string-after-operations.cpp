class Solution {
public:
    int minimumLength(string s) {
        int charFreq[26];
        for(auto i : s) charFreq[i - 'a'] ++;
        int res = 0;
        for(auto i : charFreq)
            if(i) res += 1 + (i % 2 == 0);
        return res;
    }
};