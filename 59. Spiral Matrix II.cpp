class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n,vector<int>(n));
        int top = 0, bottom = n-1, left = 0, right = n-1;
        int count =1;
        while(top <= bottom && left <= right){
        	for(int i = left;i <=right;i++) result[top][i] = count++;
        	for(int i = top+1; i <= bottom;i++) result[i][right] = count++;
        	for(int i = right-1; i >= left && top < bottom;i--) result[bottom][i] = count++;
        	for(int i = bottom-1; i> top && left < right; i--) result[i][left] = count++;
        	left++;right--;top++;bottom--;
        }
        return result;
    }
};