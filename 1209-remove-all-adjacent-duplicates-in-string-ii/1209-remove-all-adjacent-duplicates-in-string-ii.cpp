class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        st.push({s[0], 1});
        int i;
        for(i=1;i<s.size();i++) {
            if(s[i] == s[i-1]) {
                st.top().second++;
            } else {
                if(!st.empty() and st.top().second < k) {
                    // if less, push new element
                    st.push({s[i],1});
                } else {
                    if(!st.empty() and st.top().second == k) {
                        // if top == k, pop
                        st.pop();
                        // then check if current element is equal to 
                        // the top element
                        // else push current element
                        if(!st.empty() and st.top().first == s[i]) {
                            st.top().second++;
                        } else st.push({s[i],1});
                    }
                    if(!st.empty() and st.top().second > k) {
                        st.top().second %= k;
                        // if top == 0, pop
                        if(st.top().second == 0) {
                            st.pop();
                            // if top element is euql to current element
                            // else push current element
                            if(!st.empty() and 
                                st.top().first == s[i]) {
                                st.top().second++;
                            } else st.push({s[i],1});
                        } else st.push({s[i],1});
                    }
                }
            }
            if(!st.empty())
                cout<<st.top().first << " " << 
                st.top().second <<endl;
        }

        // check if last top element is greater than or equal to k
        if(!st.empty() and st.top().second == k) {
            // if equal pop
            st.pop();
        }
        if(!st.empty() and st.top().second > k) {
            st.top().second %= k;
            if(st.top().second == 0) {
                st.pop();
            }
        }

        string ans = "";
        while(!st.empty()) {
            pair<char,int> p = st.top();
            for(int i=1;i<=p.second;i++) {
                ans += p.first;
            }
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};