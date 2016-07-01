class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if(size <=0) return 0;
        vector<int> candy(size,1);
        for(int i = 1 ; i < ratings.size();i++){
        	if(ratings[i-1] < ratings[i])
        		candy[i] = candy[i-1] + 1;
        	else candy[i] = 1;
        }
        int result = candy[size-1];
        for(int i = size-2;i >=0;i--){
        	if(ratings[i+1] < ratings[i])
        		candy[i] = max(candy[i+1]+1,candy[i]);
        	result += candy[i];
        }
        return result;
    }
};