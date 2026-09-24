class Solution {
public:
    bool isValid(string s) {
        // Time Complexity: O(n)
        // Space Complexity: O(n)

        int n = s.length();

        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    return false;
                } else {
                    if ((s[i] == ')' && st.top() == '(') ||
                        (s[i] == '}' && st.top() == '{') ||
                        (s[i] == ']' && st.top() == '[')) {
                        st.pop();
                    } else {
                        return false;
                    }
                }
            }
        }

        return st.empty();
    }
};
