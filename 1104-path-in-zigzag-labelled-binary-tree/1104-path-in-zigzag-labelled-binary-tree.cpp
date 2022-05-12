class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int>ans;
        int level = log2(label);
        int x = level;
        ans.push_back(label);
        while(level!=0){
            int srNo;
            int p = pow(2,level);
            if(!(level&1)){
                srNo = label - p ; 
                int leftParent=0;
                if(srNo!=0)
                 leftParent = srNo/2;
                int parentLevel = level-1;
                int pMax = p -1;
                label = pMax - leftParent;
            }
            else {
                srNo = 2*p -label-1;
                int leftParent=0;
                if(srNo!=0)
                 leftParent =srNo/2;
                int parentMin = p/2;
                label=parentMin + leftParent;
            }
            ans.push_back(label);
            level--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};