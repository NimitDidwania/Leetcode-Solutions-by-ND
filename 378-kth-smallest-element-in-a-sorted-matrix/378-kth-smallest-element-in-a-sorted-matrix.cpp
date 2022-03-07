class Solution {
public:
    int fun(vector<vector<int>>&matrix,int k)
    {
        int ct=0;
        for(int i=0;i<matrix.size();i++)
        {
            int low=0,high=matrix[0].size()-1;
            int ind=-1;
            while(low<=high)
            {
                int mid =low+(high-low)/2;
                if(matrix[i][mid]<k){ind=mid;low=mid+1;}
                else high=mid-1;
            }
            if(ind!=-1)
            {
                ct+=(ind+1);
            }
        }
        return ct;
    }
    
    
    
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int low=INT_MAX,high=INT_MIN,r=matrix.size(),c=matrix[0].size();
        
        for(int i=0;i<matrix.size();i++)
        {
            low=min(low,matrix[i][0]);
            high=max(high,matrix[i][c-1]);
        }
        int ans;
        while(low<=high)
        {
            int mid = low + (high -low)/2;
            int smallerThanMid = fun(matrix,mid);
            cout<<mid<<" "<<smallerThanMid<<endl;
            if(smallerThanMid<k){ans=mid,low=mid+1;}
            else high =mid-1;
        }
        return ans;
    }
};