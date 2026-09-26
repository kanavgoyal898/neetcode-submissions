class MinStack {
private:
    stack<pair<int, int>> st;

public:
    MinStack() {
        // Time Complexity: O(1)
        // Space Complexity: O(n)
    }
    
    void push(int val) {
        if (this->st.empty()) {
            this->st.push({val, val});
        } else {
            int val_ = this->st.top().first;
            int minVal = this->st.top().second;
            this->st.push({val, min(val, minVal)});
        }
    }
    
    void pop() {
        if (!this->st.empty()) {
            this->st.pop();
        }
    }
    
    int top() {
        if (!this->st.empty()) {
            int val = this->st.top().first;
            int minVal = this->st.top().second;
            return val;
        } else {
            return -1;
        }
    }
    
    int getMin() {
        if (!this->st.empty()) {
            int val = this->st.top().first;
            int minVal = this->st.top().second;
            return minVal;
        } else {
            return -1;
        }
    }
};
