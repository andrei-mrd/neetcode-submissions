class MinStack {
public:
vector<int> v;
    MinStack() {
    }
    
    void push(int val) {
        v.push_back(val);
    }
    
    void pop() {
        v.erase(v.end() - 1);
    }
    
    int top() {
        return v[v.size() - 1];
    }
    
    int getMin() {
        int mini = INT_MAX;
        for(int i = 0; i<v.size(); i++) {
            if(v[i] < mini) {
                mini = v[i];
            }
        }
        return mini;
    }
};
