class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Time Complexity: O(n)
        // Space Complexity: O(1)

        int n = nums.size();

        int prefixProduct = 1;
        int suffixProduct = 1;

        vector<int> product(n, 1);

        for (int i = 1; i < n; i++) {
            prefixProduct = prefixProduct * nums[i-1];
            product[i] *= prefixProduct;
        }

        for (int i = n-2; i >= 0; i--) {
            suffixProduct = suffixProduct * nums[i+1];
            product[i] *= suffixProduct;
        }

        return product;
    }
};
