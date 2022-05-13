class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int x=0,ind=0 , n=nums.size();
        for(int i=0;i<nums.size();i++)x=x^nums[i];
        while(ind<32){
            if((x>>ind)&1)break;
            ind++;
        }
        int y=x;
        for(int i=0;i<n;i++){
            if((nums[i]>>ind)&1)x=x^nums[i];
        }
         y=x^y;
        vector<int>v(2);
        v[0]=x,v[1]=y;
        return v;
    }
};