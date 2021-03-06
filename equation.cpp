#include "equation.hpp"
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
