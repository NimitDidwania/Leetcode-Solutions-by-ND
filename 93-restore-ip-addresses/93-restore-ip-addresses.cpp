class Solution {
public:
    void fun(string &s,int ind,string &curr,vector<string>&ans,int parts){
        
        if(ind==s.size())
        {
            if(parts==4)
            {
                string temp=curr;
                temp.pop_back();
                ans.push_back(temp);
            }
            return;
        }
        
        if(s[ind]=='0'){
            curr.push_back('0');
            curr.push_back('.');
            fun(s,ind+1,curr,ans,parts+1);
            curr.pop_back();
            curr.pop_back();
        }
        else{
            curr.push_back(s[ind]);
            curr.push_back('.');
            fun(s,ind+1,curr,ans,parts+1);
            curr.pop_back();
            curr.pop_back();
            //condition
            if(ind<s.size()-1)
            {curr.push_back(s[ind]);
            curr.push_back(s[ind+1]);
            curr.push_back('.');
            fun(s,ind+2,curr,ans,parts+1);
            curr.pop_back();
            curr.pop_back();
            curr.pop_back();}
            //condition
            
            if(ind<s.size()-2 ){
                string temp=s.substr(ind,3);
                int num=stoi(temp);
                if(num<=255){
            curr.push_back(s[ind]);
            curr.push_back(s[ind+1]);
            curr.push_back(s[ind+2]);
            curr.push_back('.');
            fun(s,ind+3,curr,ans,parts+1);
            curr.pop_back();
            curr.pop_back();
            curr.pop_back();
            curr.pop_back();}
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        string curr="";
        fun(s,0,curr,ans,0);
        return ans;
    }
};