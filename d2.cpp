#include <iostream>
#include <cmath>
using namespace std;

class Calculator {
public:
    float n1;
	float n2;

    Calculator(float a, float b)
    {
    	n1=a;
    	n2=b;
	}

    float add() {
        return (n1+n2);
    }

    float subtract() {
        return (n1-n2);
    }

    float multiply() {
        return (n1*n2);
    }

    float divide() {
        if (n2 != 0) {
            return (n1/n2);
        } else {
            cout << "division by zero isn't allowed" << endl;
        }
    }
};

class otheroperations{
public:
	float n1;
	otheroperations(float a) : n1(a) {}
    static float logarithm(float base, float num) {
        if (base > 0 && num > 0) {
            return log(num) / log(base);
        } else {
            cout << "Invalid input" << endl;
        }
    }
    
    static float logten(float num) {
        if (num > 0) {
        	return log10(num);
        } else {
            cout << "Invalid input" << endl;
        }
    }
    
    static float ln(float num) {
        if (num > 0) {
        	float e= exp(1);
            return log(num) / log(e);
        } else {
            cout << "Invalid input" << endl;
        }
    }


    static float sine(float angle) {
        return sin(angle);
    }

    static float cosine(float angle) {
        return cos(angle);
    }
    
    static float tangent(float angle){
    	return tan(angle);
	}
};

int main() {
    float n1, n2;
    int choice;

    do {
        cout << "1. Arithmetic operation\n";
        cout << "2. Logarithmic operation\n";
    	cout << "3. Trigonometric operation\n";
        cout << "4. EXIT\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        
        
        switch (choice) {
            case 1: {
                cout << "Choose an operation:\n";
                cout << "1. Addition\n";
                cout << "2. Subtraction\n";
                cout << "3. Multiplication\n";
                cout << "4. Division\n";
                int opchoice;
                cin >> opchoice;
                if (choice == 1) {
            		cout << "Enter two numbers: ";
            		cin >> n1 >> n2;
        		}
                float result;
                	Calculator calc(n1, n2);
                 switch (opchoice) {
                 	
                    case 1:
                        result = calc.add();
                        break;
                    case 2:
                        result = calc.subtract();
                        break;
                    case 3:
                        result = calc.multiply();
                        break;
                    case 4:
                        result = calc.divide();
                        break;
                    default:
                        cout << "invalid choice" << endl;
                        break;
                }
                cout << "result = " << result << endl;
                break;
            }
            
           case 2: {
                cout << "Choose an operation:\n";
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
                        cout << "Invalid choice" << endl;
                        break;
                }
                break;
            }
            
            case 3: {
                int trigChoice;
                cout << "Choose a trigonometric operation:\n";
                cout << "1. Sine\n";
                cout << "2. Cosine\n";
                cout << "3. Tangent\n";
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
                        cout << "Invalid trigonometric operation choice." << endl;
                        break;
                }
                cout << "Result = " << result << endl;
                break;
            }
            case 4:
                return 0;
            default:
                cout << "Wrong choice" << endl;
                break;
        }
        cout << "------------------------\n";
    } while (choice != 4);

}
