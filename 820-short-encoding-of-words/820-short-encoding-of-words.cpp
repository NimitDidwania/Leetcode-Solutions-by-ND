struct Node{
    Node *links[26];
    bool last=false;
    void insert(string word,Node *node,int &ans){
        bool first=1;
        for(auto ch:word){
            if(!node->links[ch-'a']){
                node->links[ch-'a']=new Node();
                if(first)
                {
                    if(word=="em")cout<<"in";
                    ans+=word.size();
                    ans++;first=0;
                }
            }
            node=node->links[ch-'a'];
        }
        node->last=true;
    }
};

class Solution {
private:
    Node *root;
public:
    void reverse(string &x,int l,int h){
        while(l<h)swap(x[l++],x[h--]);
    }
    int minimumLengthEncoding(vector<string>& words) {
        
        root=new Node();
        int n=words.size();
        for(int i=0;i<n;i++){
            reverse(words[i],0,words[i].size()-1);
        }
        sort(words.begin(),words.end(),greater<string>());
        int ans=0;
        for(int i=0;i<n;i++){
            int x=0;
            cout<<words[i]<<endl;
            root->insert(words[i],root,x);
            ans+=x;
        }
        return ans;
    }
};