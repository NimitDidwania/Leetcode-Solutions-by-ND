class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size() , l=0,h=n-1 , boats=0;
        sort(people.begin(),people.end());
        while(l<=h)
        {
            if((people[l]+people[h])<=limit){
                boats++;
                l++;
                h--;
            }
            else {
                boats++;
                h--;
            }
        }
        
        return boats;
    }
};