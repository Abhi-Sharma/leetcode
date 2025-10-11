class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int rowIndex = 0;
        int colIndex = m-1;
        while(rowIndex < n && colIndex >= 0){
            if(target == matrix[rowIndex][colIndex]) return true;
            if(target < matrix[rowIndex][colIndex]) colIndex--;
            else rowIndex++;
        }
        return false;
    }
};