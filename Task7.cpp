#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isOperator(char x)
{
    return (x == '+' || x == '-' || x == '*' || x == '/');
}

bool isOperand(char x)
{
    return ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'));
}
bool higherPriority(char x, vector <char> stack)
{
    return ((stack.back() == '-' || stack.back() == '+') && (x == '*' || x == '/'));
}

void retrieve(vector <char>& stack, string& postfix, char x)
{
    if (x == '+' || x == '-') {
        while (stack.back() != '(')  {
            postfix += stack.back();
            stack.pop_back();
            if (stack.empty()) break;
        }
        stack.push_back(x);
    }
    else {
        while (stack.back() != '(') {
            postfix += stack.back();
            stack.pop_back();
            if (stack.back() == '-' || stack.back() == '+') break;
        }
        stack.push_back(x);
    }
}

void retrieveTo(vector <char>& stack, string& postfix)
{
    while (stack.back() != '(') {
        postfix += stack.back();
        stack.pop_back();
    }
    stack.pop_back();
}
string fromInfixToPostfix(string infix)
{
    vector <char> stack;
    string postfix = "";
    char symbol;
    while (infix.size() != 0) {
        symbol = infix[0];
        if (symbol == ' ') {
            infix.erase(0, 1);
            continue;
        };
        if (isOperator(symbol)) {
            if (stack.size() == 0 || stack.back() == '(') {
                stack.push_back(symbol);
            }
            else if (higherPriority(symbol, stack)) {
                stack.push_back(symbol);
            }
            else {
                retrieve(stack, postfix, symbol);
            }
        }
        else if (symbol == '(') {
            stack.push_back(symbol);
        }
        else if (symbol == ')') {
            retrieveTo(stack, postfix);
        }
        else {
            postfix += symbol;
        }
    }
    while (stack.size() != 0) {
        postfix += stack.back();
        stack.pop_back();
    }
    return postfix;
}

string fromPostfixToInfix(string postfix) { //Получить инфиксную запись по постфиксной
    vector <string> stack;
    for (int i = 0; i < postfix.size(); i++) {
        if (postfix[i] == ' ') continue;
        if (isOperand(postfix[i])) { //Операнды - в стек
            string op(1, postfix[i]);
            stack.push_back(op);
        }
        else {
            string operator1 = stack.back();
            stack.pop_back();
            string operator2 = stack.back();
            stack.pop_back();
            stack.push_back(operator2 + postfix[i] + operator1);
        }

    }
    return stack.back();
}

string fromPostfixToPrefix(string postfix)
{
    vector <string> stack;
    for (int i = 0; i < postfix.size(); i++) {
        if (postfix[i] == ' ') continue;
        if (isOperator(postfix[i])) {
            string operator1 = stack.back();
            stack.pop_back();
            string operator2 = stack.back();
            stack.pop_back();
            string temp = postfix[i] + operator2 + operator1;
            stack.push_back(temp);
        }
        else {
            stack.push_back(string(1, postfix[i]));
        }
    }
    string result = "";
    while (!(stack.empty())) {
        result += stack.back();
        stack.pop_back();
    }
    return result;
}

float calculatePostfixExpression(string postfix)
{
    vector <float> stack;
    char symbol = 0;
    for (int i = 0; i < postfix.size(); i++) {
        symbol = postfix[i];
        if (symbol == ' ') continue;
        if (isOperator(symbol)) {
            int x1 = stack.back();
            stack.pop_back();
            int x2 = stack.back();
            stack.pop_back();
            if (symbol == '+') stack.push_back(x2 + x1);
            else if (symbol == '-') stack.push_back(x2 - x1);
            else if (symbol == '*') stack.push_back(x1 * x2);
            else if (symbol == '/') stack.push_back(x2 / x1);
        }
        else {
            stack.push_back(symbol - '0');
        }
    }
    return stack.back();
}
int main()
{
    string line;
    getline(cin, line);
   // cout << fromInfixToPostfix(line);
  //  cout << fromPostfixToInfix(line) << endl;
   // cout << fromPostfixToPrefix(line);
    cout << calculatePostfixExpression(line);
}

