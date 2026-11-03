class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> suffixProduct(n, 1);

        for (int i = n-2; i >= 0; i--) {
            suffixProduct[i] = suffixProduct[i+1] * nums[i+1];
        }

        int prefixProduct = 1;
        vector<int> prefixSuffixProduct(n, 1);
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                prefixProduct = prefixProduct * nums[i-1];
            }
            prefixSuffixProduct[i] = prefixProduct * suffixProduct[i];
        }

        return prefixSuffixProduct;
    }
};
