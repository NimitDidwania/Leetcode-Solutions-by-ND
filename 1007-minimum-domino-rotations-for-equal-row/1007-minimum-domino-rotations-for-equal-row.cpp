class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans_top=INT_MAX , n=tops.size() , ans_bottom=INT_MAX;
        
        for(int i=1;i<=6;i++)
        {
            int currTop=0;
            int currBot=0;
            for(int j=0;j<n;j++)
            {
                //top
                
                if(tops[j]!=i && bottoms[j]!=i)goto here;
                else if(tops[j]!=i){currTop++;}
                
                if(tops[j]!=i && bottoms[j]!=i)goto here;
                else if(bottoms[j]!=i){currBot++;}
            }
            ans_bottom=min(ans_bottom,currBot);
            ans_top=min(ans_top,currTop);
            here:
            continue;
        }
        int ans=min(ans_top,ans_bottom);
        return (ans==INT_MAX)?-1:ans;
    }
};