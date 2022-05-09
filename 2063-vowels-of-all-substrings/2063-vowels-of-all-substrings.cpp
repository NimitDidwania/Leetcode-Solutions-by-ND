#define ll long long
class Solution {
public:
    bool vowel(char c){
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }
    
    long long countVowels(string word) {
        int n=word.size();
        vector<ll>prefix(n,0);
        ll prev=0 , sum=0;
        for(int i=0;i<n;i++){
           prefix[i]=prev; if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u'){
                prefix[i]++;
            }
            prev=prefix[i];
            sum+=prefix[i];
        }
        cout<<sum<<endl;
        ll last=sum ,ans=sum;
        for(int i=1;i<n;i++){
            if(vowel(word[i-1]) && vowel(word[i]) ||  vowel(word[i-1])&& !vowel(word[i]))
            {
                last -= (n-i+1);
            }
           
            ans = ans +  last;
        }
        return ans;
    }
};