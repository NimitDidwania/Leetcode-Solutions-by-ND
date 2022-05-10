class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1] > b[1];
        }
        return a[0]<b[0] ;
    }
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),comp);
        int mx = INT_MIN,ans=0;
        int n=arr.size();
        for(int i=n-1;i>=0;i--){
            if(arr[i][1]<mx)ans++;
            mx=max(mx,arr[i][1]);
        }
        return ans;
    }
};