class MinStack {
public:
    stack<int> st;
    stack<int>minst;
    int mini=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(mini>=val){
            minst.push(mini);
            mini=val;
        }
    }
    
    void pop() {
        if(st.top()==mini){
            mini=minst.top();
            minst.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini;
    }
};
