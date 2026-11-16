class MyQueue {
public:
//  pop efficient approach  TC-> O(1)
//  q.front = st.top  and q.back = st.bottom
    stack<int>st;
    stack<int>helper;
    MyQueue() {
        
    }
    
    void push(int x) { // O(n)
        // push at bottom
        if(st.size()==0 ){
            st.push(x);
            return ;
        }
        else {
            while(st.size()>0){
                helper.push(st.top());
                st.pop();
            }
            st.push(x);
            while(helper.size()>0){
                st.push(helper.top());
                helper.pop();
            }
        }
    }
    
    int pop() { // 0(1) remove at the bottom of stack
        int x = st.top();
        st.pop();
        return x;
    }
    
    int peek() { // O(1) front
        return st.top();
    }
    
    bool empty() {
        if(st.size()==0) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */