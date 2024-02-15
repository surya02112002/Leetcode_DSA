class Solution {
public:
    bool isValid(string s) {
        stack<char> stackA;
        int n=s.size();
        for(int i=0;i<n;i++){
            char ch=s[i];
        // if openeing brackets are there
        if(ch=='(' || ch=='{' || ch=='['){
            stackA.push(ch);
        }
        else{
            // for closing brackets
            if(!stackA.empty()){
                char top=stackA.top();
                if( (ch==')' && top=='(') || (ch=='}' && top=='{') || (ch==']' && top=='[')){
                    stackA.pop();
                } else{
                    return false;
                }
            }
            else{
                return false;
            }
        } 
    }
    if(stackA.empty()){
            return true;  // ie stack has got emptied after all operations means all were valid
        }else{
            return false;
        }
    }   
};