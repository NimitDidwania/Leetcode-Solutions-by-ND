
struct Node{
    Node *links[26];
    bool last=false;
};

class MagicDictionary {
private:
    Node *root;
public:
    MagicDictionary() {
        root=new Node();
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto word:dictionary){
            Node *node =root;
            for(auto ch:word){
                if(!node->links[ch-'a'])node->links[ch-'a']=new Node();
                node=node->links[ch-'a'];
            }
            node->last=true;
        }
    }
    bool helper(string word,Node *node){
        for(int i=0;i<word.size();i++){
            if(node->links[word[i]-'a']){
                node=node->links[word[i]-'a'];
            }
            else return false;
        }
        return node->last;
    }
    
    
    bool search(string sword) {
        Node *node = root;
        string word=sword;
        int n=sword.size();
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<26;j++){
                if(sword[i]=='a'+j){
                    continue;
                }
                word[i]='a'+j;
                if(helper(word,root))return 1;
            }
            word[i]=sword[i];
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */