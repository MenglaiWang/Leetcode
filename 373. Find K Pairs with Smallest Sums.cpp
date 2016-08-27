class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> result;
        if(k <=0 || nums1.empty() || nums2.empty()) return result;
        priority_queue<pair<int,int>,vector<pair<int,int>>,mycmp> pq;
        for(int i= 0 ; i < min((int)nums1.size(),k);i++){
        	for(int j = 0;j < min((int)nums2.size(),k);j++){
        		if(pq.size() < k){
        			pq.push(make_pair(nums1[i],nums2[j]));
        		}
        		else if(nums1[i]+nums2[j] < pq.top().first+ pq.top().second){
        			pq.push(make_pair(nums1[i],nums2[j]));
        			pq.pop();
        		}
        	}
        }
        while(pq.size()){
        	result.push_back(pq.top());
        	pq.pop();
        }
       	return result;
    }
    struct mycmp
    {
    	bool operator()(pair<int,int>& p1,pair<int,int>& p2){
    		return p1.first + p1.second < p2.first + p2.second;
    	}
    };
};


class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> result;
        int m = nums1.size();
        int n = nums2.size();
        k = min(k, m * n);
        vector<int> index(m,0);
        while(k--){
        	int temp_idx = 0;
        	int temp_sum = INT_MAX;
        	for(int i =0 ; i < m;i++){
        		if(index[i] < n && temp_sum >= nums1[i] + nums2[index[i]]){
        			temp_idx = i;
        			temp_sum = nums1[i] + nums2[index[i]];
        		}
        	}
        	result.push_back(make_pair(nums1[temp_idx],nums2[index[temp_idx]]));
        	index[temp_idx]++;
        }
        return result;
    }
};