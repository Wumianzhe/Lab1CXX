#include <iostream>
#include <math.h>

using namespace std;
const double eps = 1e-8;

int solveQuadratic(const double a, const double b, const double c, double& x1, double& x2);

int main(int argc, char* argv[]) {
    double a, b, c;
    cout << "Enter equation (ax^2 + bx + c) coefficients" << endl;
    cin >> a >> b >> c;
    if (abs(a) < eps) {
        cout << "Equation is not quadratic" << endl;
        return 1;
    }
    double x1, x2;
    int count = solveQuadratic(a, b, c, x1, x2);
    switch (count) {
    case 0:
        cout << "Equation has no roots" << endl;
        break;
    case 1:
        cout << "Equation root: " << x1 << endl;
        break;
    case 2:
        cout << "Equation roots: " << x1 << ", " << x2 << endl;
        break;
    }
    return 0;
}

int solveQuadratic(const double a, const double b, const double c, double& x1, double& x2) {
    int count = 2;
    double d = b * b - 4 * a * c;
    if (abs(d) < eps) {
        d = 0;
        count = 1;
    }
    if (d < 0) {
        count = 0;
        x1 = 0;
        x2 = 0;
        return count;
    } else {
        d = sqrt(d);
    }
    x1 = (-b + d) / (2 * a);
    x2 = (-b - d) / (2 * a);
    return count;
}
