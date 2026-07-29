class CustomStack {
public:
    vector<int> st;
    int s = 0;
    CustomStack(int maxSize) {
        s = maxSize;
    }
    
    void push(int x) {
        if (st.size() < s){
            st.push_back(x);
        }
    }
    
    int pop() {
        if (st.size()){
            int val = st.back();
            st.pop_back();
            return val;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        if (st.size() <= k){
            for (int& each : st){
                each += val;
            }
        }
        else{
            for (int i = 0; i<k; i++){
                st[i] += val;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */