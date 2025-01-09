class Solution {
    int cal(string s, int i, int j, int ans) {
        unordered_map<char,int> temp;

        for(int t=i; t <= j; t++) {
            temp[s[t]]++;
        }

        ans += temp.size();
        return ans;
    }
public: 
    int countPalindromicSubsequence(string s) {
        unordered_map<char,int> charBegin;
        int ans = 0, n = s.size();

        for(int i=0;i<n;i++) {
            if(charBegin.find(s[i]) == charBegin.end())
                charBegin[s[i]] = i;
        }

        for(int i=n-1; i>=0; i--) {
            if(charBegin.find(s[i]) != charBegin.end() and charBegin[s[i]] != -1 and charBegin[s[i]] != i) 
            {
                ans += cal(s, charBegin[s[i]]+1, i-1, 0);
                charBegin[s[i]] = -1;
            }
        }
        
        return ans;
    }
};