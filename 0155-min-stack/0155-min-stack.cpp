class MinStack {
public:
stack<pair<int,int>>st;
    MinStack() {
    }
    
    void push(int value) {
        int t;
        if(!st.empty())t=st.top().second;
        if(!st.empty()&&t<value)st.push({value,t});
        else st.push({value,value});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        int t=st.top().first;
        return t;
    }
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */