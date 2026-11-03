class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixProduct(n, 1);

        for (int i = 1; i < n; i++) {
            prefixProduct[i] = prefixProduct[i-1] * nums[i-1];
        }

        int suffixProduct = 1;
        vector<int> prefixSuffixProduct(n, 1);
        for (int i = n-1; i >= 0; i--) {
            if (i < n - 1) {
                suffixProduct = suffixProduct * nums[i+1];
            }
            prefixSuffixProduct[i] = prefixProduct[i] * suffixProduct;
        }

        return prefixSuffixProduct;
    }
};
