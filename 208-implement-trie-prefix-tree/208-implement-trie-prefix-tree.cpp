struct Node{
    Node* link[26];
    bool last=false;
    bool isPresent(char ch,Node* node){
        if(link[ch-'a']==NULL)return false;
        else return true;
    }
    void isEnd(Node *node){
        node->last=true;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root =new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(int i=0;i<word.size();i++){
            if(node->isPresent(word[i],node)){
                node=node->link[word[i]-'a'];
            }
            else{
                Node* temp = new Node();
                node->link[word[i]-'a']= temp;
                node=temp;
            }
        }
        node->isEnd(node);
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->isPresent(word[i],node))return false;
            else node=node->link[word[i]-'a'];
        }
        return node->last;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0;i<prefix.size();i++){
            if(!node->isPresent(prefix[i],node))return false;
            else node=node->link[prefix[i]-'a'];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */