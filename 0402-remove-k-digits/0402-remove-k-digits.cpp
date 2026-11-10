class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        while(k > 0) {
            st.pop();
            k--;
        }

        if(st.empty()) return "0";

        string res;

        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        while(res.size() > 0 && res[0] == '0') {
            res.erase(0, 1);
        }

        if(res.empty()) return "0";

        return res;
    }
};
