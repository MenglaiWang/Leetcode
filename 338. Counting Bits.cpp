class Solution {
public:
	int count(int n){
		int count = 0;
		while(n){
			count++;
			n = n&(n-1);
		}
		return count;
	}
    vector<int> countBits(int num) {
       	if(num < 0) return vector<int>();
		std::vector<int> result(num+1,0);    	
       	for(int i = 1; i <= num; i++ ){
       		if(result[i] <=0){
       			result[i] = count(i);
       			int j = i<<1;
       			while(j <= num){
       				result[j]=result[i];
       				j= (j<<1);
       			}
       		}
       	}
       	return result;
    }
};