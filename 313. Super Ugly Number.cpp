class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(n,INT_MAX);
        map<int,int>mp;
        for(auto p : primes)
        	mp[p] = 0;
        ugly[0] = 1;
        for(int i = 1;i < n; i++){
        	for(auto it = mp.begin();it != mp.end();it++){
        		ugly[i] = min(ugly[i],ugly[it->second]*(it->first));
        	}
        	for(auto it = mp.begin();it != mp.end();it++){
        		if(ugly[it->second]*(it->first) == ugly[i]) (it->second)++;
        	}
        }
        return ugly[n-1];
    }
};