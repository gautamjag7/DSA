// Approach 1: Rotating the string one position at a time
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        // Loop to rotate the string `s` by one character each time and check if it matches `goal`
        for (int i = 0; i < n; i++) {
            // Rotate `s` one position to the left
            rotate(s.begin(), s.begin() + 1, s.end());
            
            // Check if the rotated string matches the target `goal`
            if (s == goal)
                return true;  
        }
        return false; 
    }
};

// Approach 2: Concatenate `s` with itself and check if `goal` is a substring
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        
        // If lengths are not equal, they cannot be rotations of each other
        if (n != goal.length())
            return false;
        
        // Concatenate `s` with itself, and check if `goal` is a substring
        // If `goal` is a substring of `s + s`, then `goal` is a rotation of `s`
        if ((s + s).find(goal) != string::npos) {
            return true;
        }
        return false;  
    }
};
