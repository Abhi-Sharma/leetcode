class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;

        while(n) {
            digits.push_back(n % 10);
            n /= 10;
        }

        int maxProd = 0;

        for(int i = 0; i < digits.size(); ++i) {
            for(int j = i+1; j < digits.size(); ++j) {
                int prod = digits[i] * digits[j];
                maxProd = max(maxProd, prod);
            }
        }

        return maxProd;
    }
};
