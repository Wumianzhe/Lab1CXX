#include "solution.hpp"

solution::solution(int rootCount, double x1, double x2) : _rootCount(rootCount), _x1(x1), _x2(x2) {}

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
