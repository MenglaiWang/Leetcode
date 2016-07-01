//直接当成有序数组做
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = 0, ii = m -1, jj = n-1;
        while(i <= ii && j <= jj){
        	int mid_i = (i+ii)/2;
        	int mid_j = (j+jj)/2;
        	if(matrix[mid_i][mid_j]==target) return true;
        	if(matrix[mid_i][mid_j] < target) {
        		i = i + (j+1)/n;
        		j = (j+1)%n;
        	}else {
        		if(jj-1 <0) {
        		    ii = ii-1;
        		    jj = n-1;
        		}
        		else{ 
        		    mid_i = ii;
        		    jj--;
        		}
        	}
        }
        return false;
    }
};


//更简单的办法
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = m*n -1 ;
        while( i <= j){
        	int mid = (i + j)/2;
        	if(matrix[mid/n][mid%n] == target) return true;
        	if(matrix[mid/n][mid%n] < target) i = mid + 1;
        	else j = mid - 1;
        }
        return false;
    }
};
