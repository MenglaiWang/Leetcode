class Solution {
public:
    int hIndex(vector<int>& citations) {
    	int size = citations.size();
        vector<int> count(size+1);
        for(auto c:citations){
        	if(c > size) count[size]++;
        	else count[c]++;
        }
        int total = 0;
        for(int i = size; i >=0; i--){
        	total += count[i];
        	if(total >= i) return i;
        }
    }
};