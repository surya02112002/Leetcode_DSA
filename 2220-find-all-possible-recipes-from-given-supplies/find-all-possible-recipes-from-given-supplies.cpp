class Solution {
public:
    vector<string> findAllRecipes(vector<string>& r, vector<vector<string>>& ing, vector<string>& s) {
        unordered_set<string>st;
        for(auto val:s)
        {
            st.insert(val);
        }
       
        unordered_set<string>ans;
        bool cont=true;
        while(cont)
        {
           cont =false;
           for(int i=0;i<r.size();i++)
           {
            if(st.count(r[i]))continue;

            bool check=true;
            for(auto pal:ing[i])
            {
                if(!st.count(pal))check=false;
            }

            if(check)
            {
                ans.insert(r[i]);
                st.insert(r[i]);
                cont=true;
            }
           }
        }
         vector<string>res;
        for(auto val:ans)
        {
            res.push_back(val);
        }


        return res;
    }
};