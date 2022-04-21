struct Node{
    Node* link[26];
    bool last=false;
};

class WordDictionary {
    Node *root;
public:
    

    
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->link[word[i]-'a']){
                node=node->link[word[i]-'a'];
            }
            else {
                Node* temp=new Node();
                node->link[word[i]-'a']=temp;
                node=temp;
            }
        }
        node->last=true;
    }
    bool searchIt(string word,int ind,Node *node){
        if(node==NULL)return 0;
        if(ind==word.size()){
            return  node->last;
        }
        
        if(word[ind]!='.'){
            if(node!=NULL && node->link[word[ind]-'a'])return searchIt(word,ind+1,node->link[word[ind]-'a']);
        }
        else{
            for(int i=0;i<26;i++){
                Node* temp = node;
                node=node->link[i];
                if(searchIt(word,ind+1,node))return 1;
                node=temp;
            }
        }
        return 0;
    }
    
    bool search(string word) {
        Node* node = root;
        return searchIt(word,0,node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */