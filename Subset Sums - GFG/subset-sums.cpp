//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
    int allsubsets(vector<int> arr, vector<int> &asum, int sum, int ind) {
        if(ind >= arr.size()) {
            return sum;
        }
        sum = allsubsets(arr, asum, sum+arr[ind], ind+1);
        asum.push_back(sum);
        sum = allsubsets(arr, asum, sum-arr[ind], ind+1);
        return sum;
    }
public:
    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int> asum = {0} ;
        int sum = 0;
        allsubsets(arr, asum, sum, 0);
        return asum;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends 