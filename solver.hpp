#ifndef SOLVER_H_
#define SOLVER_H_

#include <iostream>
class solution {
  public:
    void printFancy(std::ostream& out) const;
    int _rootCount;
    double _x1;
    double _x2;
};

class equation {
  public:
    equation(std::istream& in);
    solution solve() const;

  private:
    double _a;
    double _b;
    double _c;
};

#endif // SOLVER_H_
