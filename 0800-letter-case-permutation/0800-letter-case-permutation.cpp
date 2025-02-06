#define PB push_back
#define POP pop_back
typedef string str;
typedef vector<int> vi;
typedef vector<string> vs;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

class Solution {
    vi indices;
    str original;
    void backtrack(str s, int i, vs& ans, int n) {
        if(i >= n) {
            ans.PB(s);
            return ;
        }

        if(isdigit(s[i])) {
            backtrack(s, i+1, ans, n);
            return ;
        }
        s[i] = toupper(s[i]);
        backtrack(s, i+1, ans, n);
        s[i] = tolower(s[i]);
        backtrack(s, i+1, ans, n);
    }
public:
    vector<string> letterCasePermutation(string s) {
        FAST_IO;
        vs ans;
        backtrack(s, 0, ans, s.size());
        return ans;
    }
};