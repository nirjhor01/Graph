class Solution {
public:
    unordered_map<int,int>par,sz;
    void make_sets(int v){
        par[v] = v;
        sz[v] = 1;
    }
    int find_sets(int u){
        if(par[u] == u) return u;
        return par[u] = find_sets(par[u]);
    }
    void union_sets(int a, int b){
        a = find_sets(a);
        b = find_sets(b);
       // cout <<"check-a = " << a << " check-b = " << b<<'\n';
        if(a != b){
            if(sz[a] < sz[b]) swap(a, b);
                sz[a] += sz[b];
                par[b] = a;
            
        }
    }
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_map<int,int>mp;
        int len = nums.size();
        for(int i = 0; i < len; ++i){
            make_sets(nums[i]);
        }
        for(auto i: nums) mp[i] = 1;

        for(auto i: nums){
            if(mp[i + 1] == 1){
                union_sets(i, i + 1);
            }
        }
        int mx = 0;
        for(auto i: nums){
            mx = max(mx, sz[i]);
        }
        return mx;
    }
};
