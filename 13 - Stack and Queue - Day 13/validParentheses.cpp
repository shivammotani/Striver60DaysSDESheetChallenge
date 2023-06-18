bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char>s;
    for(int i=0; i<expression.size(); i++){
        if(expression[i] == '[' || expression[i] == '{' || expression[i] == '(') s.push(expression[i]);
        else if(expression[i] == ']' && !s.empty() && s.top() == '[') s.pop();
        else if(expression[i] == '}' && !s.empty() && s.top() == '{') s.pop();
        else if(expression[i] == ')' && !s.empty() && s.top() == '(') s.pop();
        else return false;
    }
    if(s.empty()) return true;
    return false;
    
}