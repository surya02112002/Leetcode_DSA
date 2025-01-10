class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int mxfre[26]{};

        for(auto i : words2){
            int fre[26]{};

            for(auto j : i)fre[j - 'a']++;

            for(int i = 0 ;i < 26 ;i++)
                mxfre[i] = max(mxfre[i], fre[i]);
        }

        vector<string>ans;

        for(auto i : words1){
            int fre[26]{}, ok = 1;

            for(auto j : i)fre[j - 'a']++;

            for(int i = 0; i < 26 && ok; i++)
                if(fre[i] < mxfre[i])ok = 0;

            if(ok)ans.push_back(i);
        }

        return ans;
    }
};