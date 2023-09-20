class MinStack {
public:
    // maintaning prefix min for every 
    //  push, pop and returning the 
    //  last element of the prefix
    vector<pair<int,int>> mst;
    MinStack() {
        
    }
  
    void push(int val) {
        if(mst.size() > 0) {
            // min updates the prefix val
            mst.push_back( {val, min(val, mst[mst.size()-1].second)} );
        } else {
            mst.push_back({val,val});
        }
    }
    
    void pop() {
        if(mst.size() > 0)
            mst.pop_back();
    }
    
    int top() {
        // pair first is stack
        return mst[mst.size()-1].first;
    }
    
    int getMin() {
        // pair second is prefix
        return mst[mst.size()-1].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */