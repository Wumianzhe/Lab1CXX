#include "solver.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

int main(int argc, char* argv[]) {
    cout << "Enter equation (ax^2 + bx + c) coefficients" << endl;
    const equation eqn(cin);
    const solution sln = eqn.solve();
    sln.printFancy(cout);
    return 0;
}
