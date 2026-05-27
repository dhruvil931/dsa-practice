// Problem: Postfix to Infix
// Source: GFG
// Approach: Stack
// Time: O(n)
// Space: O(n)

// User function Template for C++

class Solution {
  public:
    string postToInfix(string &exp) {
        stack<string> st;
        int i=0;
        
        while(i < exp.size()) {
            if(
                exp[i] >= 'A' && exp[i] <= 'Z' ||    
                exp[i] >= 'a' && exp[i] <= 'z' ||    
                exp[i] >= '0' && exp[i] <= '9'    
            ) {
                st.push(string(1, exp[i]));
            }
            
            else {
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();
                string con = "(" + t2 + string(1, exp[i]) + t1 + ")";
                st.push(con);
            }
            
            i++;
        }
        
        return st.top();
    }
};
