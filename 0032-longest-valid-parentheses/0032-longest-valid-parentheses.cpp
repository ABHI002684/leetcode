class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size(),len=0;
        stack<int> st;
        st.push(-1);

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }else{
                st.pop();

                if(st.empty()){
                    st.push(i);
                }else{
                    len=max(len,i-st.top());
                }
            }
        }

        return len;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna