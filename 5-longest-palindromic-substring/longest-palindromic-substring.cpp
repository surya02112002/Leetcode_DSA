class Solution {
public:
    string longestPalindrome(string s) {
        int maxlen = 1;
        int svpos = 0;
        int curpos = 0;
        int odd = 1;
        for (size_t i = 1; i < 2*s.size() - 1; ++i) {
            int curlen = 1;
            if (i%2 == 0) {
                for (int k = 1; k <= min(curpos, int(s.size() - curpos)); ++k) {
                    if (s[curpos + k] == s[curpos - k]) {
                        curlen += 2;
                    } else break;
                } 
                
                if (curlen > maxlen) {
                    maxlen = curlen;
                    svpos = curpos;
                    odd = 1;
                }
            } else {
                if (s[curpos] == s[curpos + 1]) {
                    int npos = curpos + 1;
                    curlen = 2;
                    for (int k = 1; k <= min(curpos, int(s.size() - curpos)); ++k) {
                        if (s[npos + k] == s[curpos - k]) {
                            curlen += 2;
                        } else break;
                    }
                    if (curlen > maxlen) {
                        maxlen = curlen;
                        svpos = curpos;
                        odd = 2;
                    }
                }
            }
            if (i % 2 == 1) {
                curpos++;
            }
        }
        string res = "";
        if (odd == 1) {
            for(int i = svpos - maxlen/2; i <= svpos + maxlen/2; ++i) {
                res+=s[i];
            }
        }
        if (odd == 2) {
            for(int i = svpos - maxlen/2 + 1; i <= svpos + maxlen/2; ++i) {
                res+=s[i];
            }
        }
        return res; 
    }
};