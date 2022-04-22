struct Node{
    Node* links[26];
    bool last=false;
};



class Solution {
    
public:
    
    string longestWord(vector<string>& words) {
        Node* root= new Node();
        int n=words.size();
        for(int i=0;i<words.size();i++){
            Node* node=root;
            for(int j=0;j<words[i].size();j++){
                char ch = words[i][j];
                if(!node->links[ch-'a']){
                    Node* temp=new Node();
                    node->links[ch-'a']=temp;
                }
                node=node->links[ch-'a'];
            }
            node->last=true;
        }
        
        string ans="";
        for(int i=0;i<words.size();i++){
            Node* node=root;
           for(auto ch:words[i]){
               if(node->links[ch-'a']  &&  node->links[ch-'a']->last==true){
                   node=node->links[ch-'a'];
                   continue;
               }
               else goto here;
           }
            if(ans.size()==words[i].size()){
                if(words[i]<ans)ans=words[i];
            }
            if(ans.size()<words[i].size())ans=words[i];
            here:continue;
        }
        return ans;
    }
};