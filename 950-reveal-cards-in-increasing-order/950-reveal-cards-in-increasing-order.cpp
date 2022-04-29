class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        if(n==1)return deck;
        queue<int>q;
        vector<int>help = deck;
        sort(help.begin(),help.end(),greater<int>());
        q.push(help[0]);
        q.push(help[1]);
        int i=2;
            while(q.size()!=deck.size()){
            int x=q.front();
            q.pop();
            q.push(x);
            q.push(help[i++]);
        }
        i=n-1;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            deck[i--]=x;
        }
        return deck;
    }
};