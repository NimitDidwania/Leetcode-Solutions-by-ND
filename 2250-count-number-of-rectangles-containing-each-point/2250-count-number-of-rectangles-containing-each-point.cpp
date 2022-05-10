class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        int n=rectangles.size() , m=points.size();
        sort(rectangles.begin(),rectangles.end());
        
        vector<int>ans(m,0);
        vector<vector<int>>height(101);
        for(int i=0;i<n;i++){
            height[rectangles[i][1]].push_back(rectangles[i][0]);
        }
        for(int j=0;j<m;j++){
            int x=points[j][0] , y=points[j][1];
            int a=0;
            for(int i=y;i<=100;i++){
                int low = 0 , high = height[i].size()-1;
                int ind=-1;
                while(low<=high){
                    int mid = low+ (high-low)/2;
                    if(height[i][mid]>=x){
                        ind=mid;
                        high=mid-1;
                    }
                    else low=mid+1;
                }
                if(ind == -1){continue;}
                else a+= (height[i].size() -ind  );
            }
            ans[j]=a;
        }
        return ans;
    }
};