#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <cmath>
#include <map>

using namespace std;

const string RESET = "\x1B[0m";
const string RED = "\x1B[31m";
const string GREEN = "\x1B[32m";
const string CYAN = "\x1B[36m";
const string WHITE = "\x1B[37m";
const string BOLD = "\x1B[1m";

class Calculator {
public:
    stack<char> operators;
    stack<double> numbers;
    map<char, int> precedence;

public:
    Calculator() {
    	
        precedence['+'] = 1;
        precedence['-'] = 1;
        precedence['*'] = 2;
        precedence['/'] = 2;
    }

    double evaluateExpression(string expression) {
        for (size_t i = 0; i < expression.size(); ++i) {
            char c = expression[i];
            if (isdigit(c) || (c == '.')) {
                double number = 0;
                while (i < expression.size() && (isdigit(expression[i]) || expression[i] == '.')) {
                    number = number * 10 + (expression[i] - '0');
                    i++;
                }
                numbers.push(number);
            } else if (c == ' ') {
                continue; 
            } else if (c == '+' || c == '-' || c == '*' || c == '/') {
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

        return numbers.top();
    }
};

class otheroperations {
public:
    float n1;
    otheroperations(float a) : n1(a) {}
    static float logarithm(float base, float num) {
        if (base > 0 && num > 0) {
            return  log(num) / log(base);
        } else {
            cout << RED << "Invalid input" << RESET << endl;
        }
    }

    static float logten(float num) {
        if (num > 0) {
            return log10(num);
        } else {
            cout << RED << BOLD << "Invalid input" << RESET << endl;
        }
    }

    static float ln(float num) {
        if (num > 0) {
            float e = exp(1);
            return log(num) / log(e);
        } else {
            cout << RED << BOLD << "Invalid input" << RESET << endl;
        }
    }

    static float sine(float angle) {
        return sin(angle);
    }

    static float cosine(float angle) {
        return cos(angle);
    }

    static float tangent(float angle) {
        return tan(angle);
    }
};

int main() {
    float n1, n2;
    int choice;

    do {
        cout << CYAN << BOLD <<"1. Arithmetic operation\n"<< RESET;
        cout << CYAN << BOLD <<"2. Logarithmic operation\n" << RESET;
        cout << CYAN << BOLD << "3. Trigonometric operation\n" << RESET;
        cout << CYAN << BOLD << "4. EXIT\n" << RESET;
        cout << WHITE << BOLD <<"Enter your choice (1-4): " << RESET;
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore(); 
                cout << "Enter an arithmetic expression \033[1m(add space after each operand)\033[0m: ";
                string expression;
                getline(cin, expression);
                Calculator calc;
                double result = calc.evaluateExpression(expression);
                cout << GREEN << "Result: " << result << RESET << endl;
                break;
            }

            case 2: {
                cout << WHITE << "Choose an operation:\n" << RESET;
                cout << CYAN << BOLD << "1. Logarithm\n" << RESET;
                cout << CYAN << BOLD << "2. Log to base 10\n"<< RESET;
                cout << CYAN << BOLD << "3. Natural Log\n" << RESET;
                int opchoice;
                cin >> opchoice;
                if (choice >= 2) {
            		cout << BOLD << "Enter a number: ";
            		cin >> n1;
        		}
                float result;
                switch (opchoice) {
                    case 1:{
                    	float base;
                		cout << BOLD << "Enter the base for the logarithmic operation: ";
                		cin >> base;
               			float result = otheroperations::logarithm(base, n1);
               			cout << GREEN << BOLD << "Result = " << result << RESET << endl;
						break;
					}
                        
                    case 2:{
                    	float result = otheroperations::logten(n1);
                		cout << GREEN << BOLD << "Result = " << result << RESET << endl;
						break;
					}
                       
                    case 3:{
                    	float result = otheroperations::ln(n1);
                		cout << GREEN << BOLD << "Result = " << result << RESET << endl;
						break;
					}
                        
                    default:
                        cout << RED << BOLD << "Invalid choice" << RESET << endl;
                        break;
                }
                break;
            }

            case 3: {
                int trigChoice;
                cout << "Choose a trigonometric operation:\n";
                cout << CYAN << BOLD << "1. Sine\n";
                cout << CYAN << BOLD << "2. Cosine\n";
                cout << CYAN << BOLD << "3. Tangent\n";
                cin >> trigChoice;
                if (choice == 3) {
            		cout << "Enter a number: ";
            		cin >> n1;
        		}
                float result;
                switch (trigChoice) {
                    case 1:
                        result = otheroperations::sine(n1);
                        break;
                    case 2:
                        result = otheroperations::cosine(n1);
                        break;
                    case 3:
                        result = otheroperations::tangent(n1);
                        break;
                    default:
                        cout <<RED << BOLD <<"Invalid trigonometric operation choice."<< RESET << endl;
                        break;
                }
                cout <<GREEN << BOLD << "Result = " << result << RESET << endl;
                break;
            }

            case 4:
                return 0;

            default:
                cout << RED << BOLD << "Wrong choice" << RESET << endl;
                break;
        }
        cout << "------------------------\n";
    } while (choice != 4);

    return 0;
}

