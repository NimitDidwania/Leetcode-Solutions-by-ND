class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>help;
        for(int i=1;i<=n;i++)help.push_back(to_string(i));
        sort(help.begin(),help.end());
        vector<int>ans;
        for(int i=0;i<n;i++)ans.push_back(stoi(help[i]));
        return ans;
    }
};