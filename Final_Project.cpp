#include <iostream>
#include <string>
#include <stack>
#include <cctype> 
#include <cmath>
#include <map>
#include <windows.h>


using namespace std;

const string RESET = "\x1B[0m";
const string RED = "\x1B[31m";
const string GREEN = "\x1B[32m";
const string CYAN = "\x1B[36m";
const string WHITE = "\x1B[37m";
const string BOLD = "\x1B[1m";
const string BLUE = "\x1B[34m";

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
            return log(num) / log(base);
        } else {
            cout << RED << BOLD << "Invalid Input" << RESET << endl;
        }
    }

    static float logten(float num) {
        if (num > 0) {
            return log10(num);
        } else {
            cout << RED <<BOLD << "Invalid Input"<< RESET << endl;
        }
    }

    static float ln(float num) {
        if (num > 0) {
            float e = exp(1);
            return log(num) / log(e);
        } else {
            cout << RED << BOLD << "Invalid Input" << RESET << endl;
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
     static float sine_inverse(float num) {
        return asin(num);
    }

    static float cosine_inverse(float num) {
        return acos(num);
    }

    static float tangent_inverse(float num) {
        return atan(num);
    }
    static float sine_hyp(float num) {
        return sinh(num);
    }

    static float cosine_hyp(float num) {
        return cosh(num);
    }

    static float tangent_hyp(float num) {
        return tanh(num);
    }
    static float power(float base, float exp){
    	return pow(base,exp);
	}
	static float sqroot( float num ){
		return sqrt(num);
	}
	static float cbroot( float num ){
		return cbrt(num);
	}
};

int main() {
	float n1, n2;
    int choice;
    cout << "=======================================" << endl;
    	cout << "        DIGITAL CALCULATOR " << endl;
    	cout << "=======================================" << endl;

    do {
        cout << CYAN << BOLD << "1. Arithmetic Operation\n" << RESET;
        cout << CYAN << BOLD << "2. Logarithmic Operation\n" << RESET;
        cout << CYAN << BOLD << "3. Trigonometric Operation\n" << RESET;
        cout << CYAN << BOLD << "4. Inverse Trigonometric Operation\n" << RESET;
        cout << CYAN << BOLD << "5. Hyperbolic Operation\n" << RESET;
        cout << CYAN << BOLD << "6. Power or Root Operation\n" << RESET;
        cout << CYAN << BOLD << "7. EXIT\n" << RESET;
        cout << CYAN << "Enter your choice (1-7): " << RESET <<endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore(); 
                cout << CYAN << "Enter an Arithmetic Expression: " << RESET <<endl<< BOLD <<"(Add space after every Operand)"<<endl;
                string expression;
                getline(cin, expression);
                Calculator calc;
                double result = calc.evaluateExpression(expression);
                cout << GREEN << BOLD << "Result = " << result << RESET << endl;
                break;
            }

            case 2: {
                cout << CYAN << "Choose an Operation:\n" << RESET;
                cout << CYAN << BOLD <<  "1. Logarithm\n" << RESET;
                cout << CYAN << BOLD << "2. Log to base 10\n" << RESET;
                cout << CYAN << BOLD << "3. Natural Log\n" << RESET;
                int opchoice;
                cin >> opchoice;
                if (choice >= 2) {
            		cout << BLUE << "Enter a number: " << RESET;
            		cin >> n1;
        		}
                float result;
                switch (opchoice) {
                    case 1:{
                    	float base;
                		cout << BLUE << "Enter the base for the logarithmic operation: " << RESET;
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
                        cout << RED << BOLD << "Invalid Choice" << RESET << endl;
                        break;
                }
                break;
            }

            case 3: {
                int trigChoice;
                cout << CYAN << "Choose a Trigonometric Operation:\n" << RESET;
                cout << CYAN << BOLD << "1. Sine\n" << RESET;
                cout << CYAN << BOLD << "2. Cosine\n" << RESET;
                cout << CYAN << BOLD << "3. Tangent\n" << RESET;
                cin >> trigChoice;
                if (choice == 3) {
            		cout << BLUE << "Enter a Number: " << RESET;
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
                        cout << RED << BOLD << "Invalid Trigonometric Operation Choice." << RESET <<endl;
                        break;
                }
                cout << GREEN << BOLD << "Result = " << result << RESET << endl;
                break;
            }
            case 4: {
                int invtrigChoice;
                cout << CYAN << "Choose an Inverse Trigonometric Operation:\n" << RESET;
                cout << CYAN << BOLD << "1. Sine Inverse\n" << RESET;
                cout << CYAN << BOLD << "2. Cosine Inverse\n" << RESET;
                cout << CYAN << BOLD << "3. Tangent Inverse\n" << RESET;
                cin >> invtrigChoice;
                if (choice == 4) {
            		cout << BLUE <<  "Enter a Number: " << RESET;
            		cin >> n1;
        		}
                float result;
                switch (invtrigChoice) {
                    case 1:
                        result = otheroperations::sine_inverse(n1);
                        break;
                    case 2:
                        result = otheroperations::cosine_inverse(n1);
                        break;
                    case 3:
                        result = otheroperations::tangent_inverse(n1);
                        break;
                    default:
                        cout << RED << BOLD << "Invalid Inverse Trigonometric Operation Choice." << RESET << endl;
                        break;
                }
                cout << GREEN << BOLD << "Result = " << result << RESET << endl;
                break;
            }
             case 5: {
                int hypChoice;
                cout << CYAN << "Choose a Hyperbolic Operation:\n"<< RESET;
                cout << CYAN << BOLD << "1. Hyperbolic Sine\n"<< RESET;
                cout << CYAN << BOLD <<"2. Hyperbolic Cosine\n"<< RESET;
                cout << CYAN << BOLD <<"3. Hyperbolic Tangent\n"<<  RESET;
                cin >> hypChoice;
                if (choice == 5) {
            		cout << BLUE << "Enter a Number: "<< RESET;
            		cin >> n1;
        		}
                float result;
                switch (hypChoice) {
                    case 1:
                        result = otheroperations::sine_hyp(n1);
                        break;
                    case 2:
                        result = otheroperations::cosine_hyp(n1);
                        break;
                    case 3:
                        result = otheroperations::tangent_hyp(n1);
                        break;
                    default:
                        cout << RED << BOLD << "Invalid Hyperbolic Choice." << RESET << endl;
                        break;
                }
                cout << GREEN << BOLD << "Result = " << result << RESET <<endl;
                break;
            }
            
            case 6: {
                int powChoice;
                cout << CYAN << "Choose a Power or Root Operation:\n" << RESET;
                cout << CYAN << BOLD << "1. Power\n" << RESET;
                cout << CYAN << BOLD << "2. Square Root\n" << RESET;
                cout << CYAN << BOLD << "3. Cube Root\n" << RESET;
                cin >> powChoice;
                if (powChoice == 1) {
            		cout << BLUE << "Enter Base: " << RESET;
            		cin >> n1;
            		cout << BLUE << "Enter Power: " << RESET;
            		cin>> n2;
        		}
        		else{
        		
            		cout << BLUE << "Enter a Number: " << RESET;
            		cin >> n1;
				}
                float result;
                switch (powChoice) {
                    case 1:
                        result = otheroperations::power(n1,n2);
                        break;
                    case 2:
                        result = otheroperations::sqroot(n1);
                        break;
                    case 3:
                        result = otheroperations::cbroot(n1);
                        break;
                    default:
                        cout << RED << BOLD << "Invalid Power or Root Choice." << RESET << endl;
                        break;
                }
                cout << GREEN << BOLD << "Result = " << result << RESET << endl;
                break;
            }

            case 7:
                return 0;

            default:
                cout << RED << BOLD << "Wrong Choice" << RESET << endl;
                break;
        }
        cout << "------------------------\n";
    } while (choice != 7);

    return 0;
}
