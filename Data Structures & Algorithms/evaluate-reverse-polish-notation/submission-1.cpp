class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> vars;
        int var1 = 0, var2 = 0;
        for(int i = 0; i<tokens.size(); i++) {
            if(tokens[i] == "+") {
                if(!vars.empty()) {
                    var1 = vars.top();
                    vars.pop();
                }
                if(!vars.empty()) {
                    var2 = vars.top();
                    vars.pop();
                }
                int n = var1 + var2;
                vars.push(n);
            }else if(tokens[i] == "-") {
                if(!vars.empty()) {
                    var1 = vars.top();
                    vars.pop();
                }
                if(!vars.empty()) {
                    var2 = vars.top();
                    vars.pop();
                }
                int n = var2 - var1;
                vars.push(n);
            }else if(tokens[i] == "*") {
                if(!vars.empty()) {
                    var1 = vars.top();
                    vars.pop();
                }
                if(!vars.empty()) {
                    var2 = vars.top();
                    vars.pop();
                }
                int n = var1 * var2;
                vars.push(n);
            }else if(tokens[i] == "/") {
                if(!vars.empty()) {
                    var1 = vars.top();
                    vars.pop();
                }
                if(!vars.empty()) {
                    var2 = vars.top();
                    vars.pop();
                }
                int n = var2 / var1;
                vars.push(n);
            }else {
                int n = stoi(tokens[i]);
                vars.push(n);
            }
        }
        int result = 0;
        if(!vars.empty()) {
            result = vars.top();
            vars.pop();
        }
        return result;
    }
};
