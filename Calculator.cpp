#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<float> numbers;
    vector<char> operators;
    float number;
    char op;
    char continueInput = 'y';

    // Take the first number
    cout << "Enter a number: ";
    cin >> number;
    numbers.push_back(number);

    // Loop to take subsequent numbers and operators
    while (continueInput == 'y' || continueInput == 'Y') {
        cout << "Enter operator (+, -, *, /): ";
        cin >> op;
        operators.push_back(op);

        cout << "Enter another number: ";
        cin >> number;
        numbers.push_back(number);

        cout << "Do you want to enter another operation (y/n)? ";
        cin >> continueInput;
    }

    // Perform the calculations
    float result = numbers[0];
    for (size_t i = 0; i < operators.size(); ++i) {
        switch(operators[i]) {
            case '+':
                result += numbers[i + 1];
                break;
            case '-':
                result -= numbers[i + 1];
                break;
            case '*':
                result *= numbers[i + 1];
                break;
            case '/':
                if (numbers[i + 1] != 0) {
                    result /= numbers[i + 1];
                } else {
                    cout << "Error! Division by zero." << endl;
                    return 1;
                }
                break;
            default:
                cout << "Error! Invalid operator." << endl;
                return 1;
        }
    }

    // Output the result
    cout << "The result is: " << result << endl;

    return 0;
}