class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        // sort(intervals.begin(),intervals.end());
        vector<int>ans(n,-1);
        vector<pair<vector<int>,int>>arr;
        for(int i=0;i<n;i++){
            arr.push_back({intervals[i],i});
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
        {
            int low=i,high=n-1;
            int ind=-1;
            while(low<=high)
            {
                int mid=low + (high-low)/2;
                if(arr[mid].first[0]>=arr[i].first[1])ind=mid,high=mid-1;
                else low=mid+1;
            }
            if(ind!=-1)
            ans[arr[i].second]=arr[ind].second;
        }
        return ans;
    }
};