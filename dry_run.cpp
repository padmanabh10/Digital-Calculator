#include <iostream>
#include <string>
#include <stack>
#include <cctype> 
#include <cmath>
#include <map>
#include <windows.h>


using namespace std;

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
            cout << "Invalid Input" << endl;
        }
    }

    static float logten(float num) {
        if (num > 0) {
            return log10(num);
        } else {
            cout << "Invalid Input" << endl;
        }
    }

    static float ln(float num) {
        if (num > 0) {
            float e = exp(1);
            return log(num) / log(e);
        } else {
            cout << "Invalid Input" << endl;
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

    do {
        cout << "1. Arithmetic operation\n";
        cout << "2. Logarithmic operation\n";
        cout << "3. Trigonometric operation\n";
        cout << "4. Inverse Trigonometric Operation\n";
        cout << "5. Hyperbolic Operation\n";
        cout << "6, Power or Root Operation\n";
        cout << "7. EXIT\n";
        cout << "Enter your choice (1-7): "<<endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore(); 
                cout << "Enter an Arithmetic expression: "<<endl<<"(Add space after every Oprend)"<<endl;
                string expression;
                getline(cin, expression);
                Calculator calc;
                double result = calc.evaluateExpression(expression);
                cout << "Result = " << result << endl;
                break;
            }

            case 2: {
                cout << "Choose an Operation:\n";
                cout << "1. Logarithm\n";
                cout << "2. Log to base 10\n";
                cout << "3. Natural Log\n";
                int opchoice;
                cin >> opchoice;
                if (choice >= 2) {
            		cout << "Enter a number: ";
            		cin >> n1;
        		}
                float result;
                switch (opchoice) {
                    case 1:{
                    	float base;
                		cout << "Enter the base for the logarithmic operation: ";
                		cin >> base;
               			float result = otheroperations::logarithm(base, n1);
               			cout << "Result = " << result << endl;
						break;
					}
                        
                    case 2:{
                    	float result = otheroperations::logten(n1);
                		cout << "Result = " << result << endl;
						break;
					}
                       
                    case 3:{
                    	float result = otheroperations::ln(n1);
                		cout << "Result = " << result << endl;
						break;
					}
                        
                    default:
                        cout << "Invalid Choice" << endl;
                        break;
                }
                break;
            }

            case 3: {
                int trigChoice;
                cout << "Choose a Trigonometric Operation:\n";
                cout << "1. Sine\n";
                cout << "2. Cosine\n";
                cout << "3. Tangent\n";
                cin >> trigChoice;
                if (choice == 3) {
            		cout << "Enter a Number: ";
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
                        cout << "Invalid Trigonometric Operation Choice." << endl;
                        break;
                }
                cout << "Result = " << result << endl;
                break;
            }
            case 4: {
                int invtrigChoice;
                cout << "Choose an Inverse Trigonometric Operation:\n";
                cout << "1. Sine Inverse\n";
                cout << "2. Cosine Inverse\n";
                cout << "3. Tangent Inverse\n";
                cin >> invtrigChoice;
                if (choice == 4) {
            		cout << "Enter a Number: ";
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
                        cout << "Invalid Inverse Trigonometric Operation Choice." << endl;
                        break;
                }
                cout << "Result = " << result << endl;
                break;
            }
            case 6: {
                int powChoice;
                cout << "Choose a Power or Root Operation:\n";
                cout << "1. Power\n";
                cout << "2. Square Root\n";
                cout << "3. Cube Root\n";
                cin >> powChoice;
                if (powChoice == 1) {
            		cout << "Enter Base: ";
            		cin >> n1;
            		cout << "Enter Power: ";
            		cin>> n2;
        		}
        		else{
        		
            		cout << "Enter a Number: ";
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
                        cout << "Invalid Power or Root Choice." << endl;
                        break;
                }
                cout << "Result = " << result << endl;
                break;
            }

            case 7:
                return 0;

            default:
                cout << "Wrong Choice" << endl;
                break;
        }
        cout << "------------------------\n";
    } while (choice != 7);

    return 0;
}
	
