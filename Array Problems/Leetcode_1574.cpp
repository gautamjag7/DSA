class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1;
        // Find the longest prefix that is sorted
        while (left < n - 1 && arr[left] <= arr[left + 1]) {
            left++;
        }
        // If the whole array is already sorted
        if (left == n - 1) return 0;
        // Find the longest suffix that is sorted
        while (right > 0 && arr[right] >= arr[right - 1]) {
            right--;
        }
        // Calculate the minimum length of the subarray to be removed
        int result = min(n - left - 1, right); // Remove prefix or suffix

        // Try to merge the sorted prefix and suffix
        int i = 0, j = right;
        while (i <= left && j < n) {
            if (arr[i] <= arr[j]) {
                result = min(result, j - i - 1);
                i++;
            } else {
                j++;
            }
        }
        return result;
    }
};
