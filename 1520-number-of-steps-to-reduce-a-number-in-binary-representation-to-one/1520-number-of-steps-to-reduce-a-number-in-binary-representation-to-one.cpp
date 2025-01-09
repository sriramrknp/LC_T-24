class Solution {
public:
    int numSteps(string s) {
        int n = s.size()-1;
        int ans = 0;
        bool one = false, zero = false;
        
        while(s[n] != '1') {
            n--;
            ans++;
        }
        
        if(n == 0) return ans;
        
        for(int i=n; i>=0; i--) {
            if(!one and s[i] == '1') {
                ans += 2; one = true; zero = false;
            } else if(one and s[i] == '1') {
                ans++;
            }
            else if(!zero and s[i] == '0') {
                ans++; zero = true; one = false;
            } else if(zero and s[i] == '0') {
                ans += 2;
            }
        }
        return ans;
    }
};