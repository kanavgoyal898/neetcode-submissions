class Solution {
private:
    bool isOperator(string s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }

public:
    int evalRPN(vector<string>& tokens) {
        // Time Complexity: O(n)
        // Space Complexity: O(1)

        int n = tokens.size();

        stack<string> st;
        for (int i = 0; i < n; i++) {
            string s = tokens[i];

            if (!isOperator(s)) {
                st.push(s);
            } else {
                int op_2 = stoi(st.top());
                st.pop();
                int op_1 = stoi(st.top());
                st.pop();
                if (s == "+") {
                    st.push(to_string(op_1 + op_2));
                }
                if (s == "-") {
                    st.push(to_string(op_1 - op_2));
                }
                if (s == "*") {
                    st.push(to_string(op_1 * op_2));
                }
                if (s == "/") {
                    st.push(to_string(op_1 / op_2));
                }
            }
        }

        string total = st.top();
        return stoi(total);
    }
};
