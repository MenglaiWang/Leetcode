class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if(matrix.empty() || k < 1 || k >n*n) return -1;
        int low = matrix[0][0],high = matrix[n-1][n-1];
        while(low < high){
        	int mid  = (low+high)/2;
        	int num = 0;
        	for(int i =0; i < n;i++){
        		for(int j = 0;j < n;j++){
        			if(matrix[i][j] <= mid) num++;
        			if(matrix[i][j] > mid) break;
        		}
        	}
        	if(num < k) low = mid+1;
        	else high = mid;
        }
        return low;
    }
};