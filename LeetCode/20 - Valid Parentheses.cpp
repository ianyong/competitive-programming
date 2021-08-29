class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> m = {
            {')', '('},
            {'}', '{'},
            {']', '['},
        };
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ')' && s[i] != '}' && s[i] != ']') {
                st.push(s[i]);
                continue;
            }
            if (st.empty()) {
                return false;
            }
            if (st.top() != m[s[i]]) {
                return false;
            }
            st.pop();
        }
        return st.empty();
    }
};
