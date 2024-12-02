class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.length(), m = searchWord.length(), currIdx = 0, currWord = 1;
        for(char c : sentence){
            if(c == ' '){
                currIdx = 0;
                currWord++;
            }else if(currIdx == -1){
                continue;
            }else if(currIdx != -1 && c == searchWord[currIdx]){
                currIdx++;
                if(currIdx == m)
                    return currWord;
            }else if(currIdx != -1 && c != searchWord[currIdx]){
                currIdx = -1;
            }
        }
        return -1;
    }
};




