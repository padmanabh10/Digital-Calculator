#include <iostream>
#include <stack>
#include <map>
#include <string>
#include <cctype> // for isdigit
using namespace std;

int main() {
    stack<char> operators;
    stack<double> numbers;
    map<char, int> precedence;

    // Define operator precedence
    precedence['+'] = 1;
    precedence['-'] = 1;
    precedence['*'] = 2;
    precedence['/'] = 2;

    string input;
    
    cout << "Enter an arithmetic expression: ";
    getline(cin, input);

    for (size_t i = 0; i < input.size(); ++i) {
        char c = input[i];
        if (isdigit(c)) {
            double number = 0;
            while (i < input.size() && isdigit(input[i])) {
                number = number * 10 + (input[i] - '0');
                i++;
            }
            numbers.push(number);
        } else if (c == ' ') {
            continue; // Ignore spaces
        } else {
            while (!operators.empty() && precedence[operators.top()] >= precedence[c]) {
                char op = operators.top();
                operators.pop();
                double operand2 = numbers.top();
                numbers.pop();
                double operand1 = numbers.top();
                numbers.pop();
                if (op == '+')
                    numbers.push(operand1 + operand2);
                else if (op == '-')
                    numbers.push(operand1 - operand2);
                else if (op == '*')
                    numbers.push(operand1 * operand2);
                else if (op == '/')
                    numbers.push(operand1 / operand2);
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();
        double operand2 = numbers.top();
        numbers.pop();
        double operand1 = numbers.top();
        numbers.pop();
        if (op == '+')
            numbers.push(operand1 + operand2);
        else if (op == '-')
            numbers.push(operand1 - operand2);
        else if (op == '*')
            numbers.push(operand1 * operand2);
        else if (op == '/')
            numbers.push(operand1 / operand2);
    }

    cout << "Result: " << numbers.top() << endl;
    return 0;
}


