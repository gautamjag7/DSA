class Solution {
public:
    string compressedString(string s) {
        string ans = "";
        int ct = 1;er
        int n = s.length();
        for (int i = 1; i < n; i++) { 
            if (s[i] == s[i - 1]) {
                ct++;
                if (ct == 9) { // When count reaches 9, add it to `ans`
                    ans += to_string(ct) + s[i - 1];
                    ct = 0;
                }
            } else {
                if (ct > 0) { 
                    ans += to_string(ct) + s[i - 1];
                }
                ct = 1; 
            }
        }
        // Add the last group to `ans`
        if (ct > 0) {
            ans += to_string(ct) + s[n - 1];
        }

        return ans;
    }
};
