// method-4 Implement the stack using vector
// TC-> O(n) SC-> O(1)
class MinStack {
public:
    stack<long long>st;
    long long mini;
    MinStack() { // constructor
        mini = LLONG_MAX;
    }
    
    void push(int val) { // O(1)
        long long x = (long long)val;
        if(st.size()==0){
            st.push(x);
            mini = x;
        }
        else if(x>=mini) st.push(x);
        else{
            st.push(2*x-mini);
            mini = x;
        }
    }
    
    void pop() { // O(1)
        if(st.top()>=mini) st.pop();
        else{ // a fake value is present
           // before popping make sure to retrieve the old min
           long long oldMin = 2*mini-st.top();
           mini = oldMin;
           st.pop();
        }
    }
    
    int top() { // O(1)
        if(st.top()<mini) return (int)mini;
        else return (int)st.top();
    }
    
    int getMin() {
        return (int)mini;
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