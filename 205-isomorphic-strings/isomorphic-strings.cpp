class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n1= s.size();
        int n2= t.size();
        if(n1!=n2){
            return 0;

        }
        map<char,char>m1,m2;
        for(int i=0; i<n1;i++){
            if(m1[s[i]]== 0 && m2[t[i]]==0){
                m1[s[i]]=t[i];
                m2[t[i]]=s[i];

            }
            if(m1[s[i]]!=t[i]&&m2[t[i]]!=s[i]){
                return 0;
            }
        }
        return 1;
    }
};