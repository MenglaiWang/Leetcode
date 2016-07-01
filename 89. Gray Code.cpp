class Solution {
public:
   vector<int> grayCode(int n) {
	int size = 1 << n;
	vector<int> result(size);
	if(n==0) return result;
	if (n == 1){
		result[0] = 0;
		result[1] = 1;
		return result;
	}
	vector<int> temp = grayCode(n - 1);
	for (int i = 0; i < temp.size();i++) result[i] = temp[i];
	for (int i = size / 2; i <size; i++){
		result[i] = temp[size - i-1] + (1 << (n - 1));
	}
	return result;
}
};