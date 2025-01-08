class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) 
    {
        int n=words.size(),res=0;
        for(int i=0;i<n-1;i++)
        {
            string str=words[i];
            int size=str.size();
            for(int j=i+1;j<n;j++)
            {
                string s=words[j];
                if(size<=s.size())
                {
                    int index=s.size()-size;
                    string ans=s.substr(0,size);
                    string rev=s.substr(index,size);
                    if(ans==str and rev==str)
                    {
                        res++;
                    }
                }
                
            }
        }    
        return res;
    }
};