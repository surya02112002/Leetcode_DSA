class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();

        map<string,int> myMap;
        int count = 0 ;

        for(int i =0 ; i < n; i++){
            string temp = words[i];
            reverse(temp.begin(),temp.end());
            if(myMap.find(temp)!=myMap.end() && myMap[temp]>0){
                count += 4 ;
                myMap[temp]--;
            }
            else{
                myMap[words[i]]++;
            }
        }


        for(auto i : myMap){
            char fir = i.first[0];
            char sec = i.first[1];
            if(fir==sec && myMap[i.first]>0){
                count += 2 ;
                break;
            }
        }

        return count ;
        
    }
};