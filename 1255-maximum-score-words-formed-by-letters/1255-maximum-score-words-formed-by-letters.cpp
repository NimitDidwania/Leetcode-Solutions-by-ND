class Solution {
public:
    int fun(int ind,vector<int>&curr,vector<string>&words,vector<int>&help,vector<int>&score){
        
        if(ind==words.size())return 0;
        int choice1 = fun(ind+1,curr,words,help,score);int choice2 = INT_MIN;
        vector<int>restore = curr;
        int currScore = 0;
        vector<int>present(26,0);
        for(auto x:words[ind])
        {
            present[x-'a']++;
        }
        bool flag=0;
        for(int i=0;i<26;i++){
            if(help[i]< present[i])flag=1;
        }
        if(flag==0){
            for(int i=0;i<26;i++){help[i]-=present[i];currScore += (present[i]*score[i]);}
            choice2 = currScore + fun(ind+1,curr,words,help,score);
            for(int i=0;i<26;i++)help[i]+=present[i];
        }
        return max(choice1,choice2);
        
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>help(26,0);
        for(auto ch:letters){
            help[ch-'a']++;
        }
        vector<int>curr(26,0);
        return fun(0,curr,words , help , score);
    }
};