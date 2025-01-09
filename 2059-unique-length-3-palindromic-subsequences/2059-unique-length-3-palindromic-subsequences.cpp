class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,int> charBegin, charEnd, temp;
        int ans = 0, n = s.size();

        for(int i=0;i<n;i++) {
            if(charBegin.find(s[i]) == charBegin.end()) 
                charBegin[s[i]] = i;
        }
        for(int i=n-1; i>=0; i--) {
            if(charEnd.find(s[i]) == charEnd.end() and charBegin[s[i]] != i) 
                charEnd[s[i]] = i;
        }
        // for(auto [c,i]:charBegin) cout<<c<<" "<<i<<endl;
        // cout<<endl;
        // for(auto [c,i]:charEnd) cout<<c<<" "<<i<<endl;

        for(auto [c,i]:charBegin) {
            int j = i;
            if(charEnd[c] > i) {
                j = charEnd[c];
                
                for(int t=i+1; t < j; t++) {
                    temp[s[t]]++;
                }
                ans += temp.size();
                temp.clear();
            }
        }
        
        return ans;
    }
};