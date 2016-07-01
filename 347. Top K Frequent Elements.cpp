class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> result;
        for(auto num : nums)
        	mp[num]++;
        // pair<first, second>: first is frequency,  second is number
        priority_queue<pair<int,int>> pq;
        for(auto it = mp.begin(); it != mp.end(); it++){
        	pq.push(make_pair(it->second,it->first));
        	if(pq.size() > mp.size() -k){
        		result.push_back(pq.top().second);
        		pq.pop();
        	}
        }
        return result;
    }
};