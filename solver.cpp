#include "solver.hpp"
#include "math.h"
#include <stdexcept>

const double eps = 1e-8;
equation::equation(std::istream& in) { in >> _a >> _b >> _c; }

solution equation::solve() const {
    if (abs(_a) < eps) {
        return {1, -_c / _b, -_c / _b};
    }
    int rootCount = 2;
    double d = _b * _b - 4 * _a * _c;
    if (abs(d) < eps) {
        d = 0;
        rootCount = 1;
    }
    if (d < 0) {
        return {0, 0, 0};
    } else {
        d = sqrt(d);
    }
    double x_1 = (-_b + d) / (2 * _a);
    double x_2 = (-_b - d) / (2 * _a);
    return {rootCount, x_1, x_2};
}

void solution::printFancy(std::ostream& out) const {
    switch (_rootCount) {
    case 0:
        out << "Equation has no roots";
        break;
    case 1:
        out << "Equation root: " << _x1;
        break;
    case 2:
        out << "Equation roots: " << _x1 << ", " << _x2;
        break;
    }
    out << std::endl;
}
