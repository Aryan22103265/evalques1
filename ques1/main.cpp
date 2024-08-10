
#include <iostream>
#include <vector>
using namespace std;

vector<int> calculateDerivative(const vector<int>& coefficients) {
    vector<int> derivative;
    int degree = coefficients.size() - 1;

    for (int i = 0; i < degree; ++i) {
        derivative.push_back(coefficients[i] * (degree - i));
    }

    return derivative;
}

void printPolynomial(const vector<int>& coefficients) {
    int degree = coefficients.size() - 1;

    for (int i = 0; i <= degree; ++i) {
        if (coefficients[i] != 0) {
            if (i != 0 && coefficients[i] > 0) {
                cout << " + ";
            } else if (coefficients[i] < 0) {
                cout << " - ";
            }

            if (abs(coefficients[i]) != 1 || i == degree) {
                cout << abs(coefficients[i]);
            }

            if (i < degree) {
                cout << "x";
                if (degree - i > 1) {
                    cout << "^" << (degree - i);
                }
            }
        }
    }
    cout << endl;
}

int main() {
    vector<int> coefficients;
    int degree;

    cout << "Enter the degree of the polynomial (up to 5): ";
    cin >> degree;

    if (degree < 0 || degree > 5) {
        cout << "Invalid degree!" << endl;
        return 1;
    }

    cout << "Enter the coefficients from highest degree to constant term:" << endl;
    for (int i = 0; i <= degree; ++i) {
        int coeff;
        cin >> coeff;
        coefficients.push_back(coeff);
    }

    cout << "Original polynomial: ";
    printPolynomial(coefficients);

    vector<int> derivative = calculateDerivative(coefficients);

    cout << "Derivative: ";
    printPolynomial(derivative);

    return 0;
}









