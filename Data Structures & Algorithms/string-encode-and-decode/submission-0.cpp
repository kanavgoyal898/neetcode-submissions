class Solution {
private:
    pair<int, int> findStrDetails(string& s, int index) {
        int i = index + 1;
        int length = 0;

        while (s[i] != '#') {
            length = length * 10 + (s[i] - '0');
            i += 1;
        }

        return {i + 1, length};
    }

public:
    string encode(vector<string>& strs) {
        // Time Complexity: O(m)
        // Space Complexity: O(1)
        
        string encodedString = "";

        for (int i = 0; i < strs.size(); i++) {
            int strLength = strs[i].length();

            encodedString += "#" + to_string(strLength) + "#";
            encodedString += strs[i];
        }

        return encodedString;
    }

    vector<string> decode(string s) {
        // Time Complexity: O(m)
        // Space Complexity: O(1)
        
        int n = s.length();
        vector<string> strs;

        for (int i = 0; i < n; i++) {
            pair<int, int> strDetails = findStrDetails(s, i);

            int startIndex = strDetails.first;
            int strLength = strDetails.second;

            strs.push_back(s.substr(startIndex, strLength));

            i = startIndex + strLength - 1;
        }

        return strs;
    }
};