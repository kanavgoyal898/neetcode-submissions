class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Time Complexity: O(n)
        // Space Complexity: O(n)
        
        int n = nums.size();

        vector<int> prefixProduct(n, 1);
        vector<int> suffixProduct(n, 1);

        for (int i = 1; i < n; i++) {
            prefixProduct[i] = prefixProduct[i-1] * nums[i-1];
        }

        for (int i = n-2; i >= 0; i--) {
            suffixProduct[i] = suffixProduct[i+1] * nums[i+1];
        }

        vector<int> product(n);
        for (int i = 0; i < n; i++) {
            product[i] = prefixProduct[i] * suffixProduct[i];
        }

        return product;
    }
};
