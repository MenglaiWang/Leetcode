class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        if(height.size() < 2) return result;
        int i = 0, j = height.size()-1;
        while( i < j) {
        	int h = min(height[i],height[j]);
        	result = max(result,h*(j-i));
        	while(height[i] <= h && i < j) i++;
        	while(height[j] <= h && i < j) j--;
        }
        return result;
    }
};