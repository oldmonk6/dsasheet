class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<n;i++){
            if(!st.empty() && st.top()=='{' && s[i]=='}'){
                st.pop();
                
            }
            else if(!st.empty() && st.top()=='(' && s[i]==')'){
                st.pop();
                
            }
            else if(!st.empty() && st.top()=='[' && s[i]==']'){
                st.pop();
                
            }
            else{
                st.push(s[i]);
            }
            

        }
        if(st.size()==0)return true;
        else return false;
        
    }
};