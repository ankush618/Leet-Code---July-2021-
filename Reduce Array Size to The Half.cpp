class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        priority_queue<int> pq;
        for(int i=0 ;i < arr.size();i++){
            mp[arr[i]]++;
        }
        for(auto it: mp)
            pq.push(it.second);
        int removed=0,res=0;
        while(removed<(arr.size()/2)){
            removed+=pq.top();
            pq.pop();
            res++;
        }
        return res;
    }
};
//happy coding
