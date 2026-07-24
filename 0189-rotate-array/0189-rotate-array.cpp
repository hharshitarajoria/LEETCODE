class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        k= k%n;
        vector<int> temp;
        // Store last k elements
        for (int i = 0; i < k; i++) {
            temp.push_back(nums[n - k + i]);
        }
        // Shift remaining elements to the right
        for (int i = n - k - 1; i >= 0; i--) {
            nums[i + k] = nums[i];
        }
        // Copy stored elements to the beginning
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};