class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i1 = 0, i2 = matrix.size() - 1;
        int j1 = 0, j2 = matrix[0].size() - 1;
        while(i1 <= i2 && j1 <= j2) {
            int imid = i1 + (i2 - i1) / 2;
            int jmid = j1 + (j2 - j1) / 2;

            if(matrix[imid][jmid] == target) {
                return true;
            }

            if(matrix[imid][jmid] < target) {
                if(matrix[imid][j2] == target) {
                    return true;
                }
                if(matrix[imid][j2] < target) {
                    i1 = imid + 1;
                }else {
                    j1 = jmid + 1;
                }
            }else {
                if(matrix[imid][j1] == target) {
                    return true;
                }
                if(matrix[imid][j1] > target) {
                    i2 = imid - 1;
                }else {
                    j2 = jmid - 1;
                }
            }
        }
        return false;
    }
};
