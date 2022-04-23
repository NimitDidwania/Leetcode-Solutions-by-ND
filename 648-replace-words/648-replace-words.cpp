struct Node{
    Node *links[26];
    bool last=false;
    
    void insert(Node *root,string word){
        Node *node = root;
        for(auto ch:word){
            if(!node->links[ch-'a']){
                node->links[ch-'a']=new Node();
            }
            node=node->links[ch-'a'];
        }
        node->last=true;
    }
    string smallestPrefix(string word,Node *node){
        int ind=0;
        string curr="";
        // cout<<word<<endl;
        while(ind<word.size() && node->links[word[ind]-'a']){
            // if(word=="battery")cout<<word[ind];
            curr.push_back(word[ind]);
            if(node->links[word[ind]-'a']->last)return curr;
            node=node->links[word[ind]-'a'];
            ind++;
        }
        if(curr.size()==0||curr.size()>=word.size())return word;
        else{ 
            if(node->last)
            return curr;
        else return word;
        }
    }
};

class Solution {
public:
    string replaceWords(vector<string>& mine, string stc) {
        
        Node *root = new Node();
        for(int i=0;i<mine.size();i++){
            root->insert(root,mine[i]);
        }
        Node *temp=root;
//         for(int i=0;i<26;i++){
//             if(temp->links[i])cout<<(char)('a'+i)<<endl;
            
//         }
        stc+=" ";
        string ans="";
        int n=stc.size();
        for(int start=0;start<stc.size();){
            int end=start;
            while(stc[end]!=' ')end++;
            string word = stc.substr(start,end-start);
            // string replacement="";
            Node* node=root;
            //smallest prefix
            
           string help=node->smallestPrefix(word,node);
           ans+=help;
            ans.push_back(' ');
            // if(cmp=="battery")cout<<"check-"<<curr<<endl;
            start=end+1;
        }
        ans.pop_back();
        return ans;
    }
};