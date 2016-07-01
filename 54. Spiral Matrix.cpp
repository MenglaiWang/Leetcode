class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty()) return result;
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0, top = 0, right = col-1, bottom = row-1;
        while(left <=right && top <=bottom){
        	for(int i = left; i<= right;i++)
        		result.push_back(matrix[top][i]);
        	for(int i = top+1; i <=bottom;i++)
        		result.push_back(matrix[i][right]);
        	for(int i = right-1; i >=left && bottom > top;i--)
        		result.push_back(matrix[bottom][i]);
        	for(int i = bottom-1;i >top && left < right;i--)
        		result.push_back(matrix[i][left]);
        	top++;bottom--;
        	left++;right--;
        }
        return result;
    }
};