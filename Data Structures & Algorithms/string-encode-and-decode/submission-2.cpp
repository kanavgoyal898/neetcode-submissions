class Solution {
public:

    string encode(vector<string>& strs) {
        string delimiter = "--------";

        string s = "";
        for (string str : strs) {
            s += str + delimiter;
        }

        return s;
    }

    vector<string> decode(string s) {
        int n = s.length();

        string delimiter = "--------";
        int m = delimiter.length();

        string str = "";
        vector<string> strs;

        for (int i = 0; i < n; i++) {
            if (s.substr(i, m) == delimiter) {
                strs.push_back(str);
                str = "";
                i += m - 1;
            } else {
                str += s[i];
                i += 1 - 1;
            }
        }

        return strs;
    }
};
