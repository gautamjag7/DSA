class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = spaces.size();
        string ans = "";
        ans += s.substr(0, spaces[0]);
        ans += " ";
        for (int i = 1; i < n; i++) 
        {
            ans += s.substr(spaces[i - 1], spaces[i] - spaces[i - 1]);
            ans += " ";
        }
        ans += s.substr(spaces[n - 1]);
        return ans;
    }
};
