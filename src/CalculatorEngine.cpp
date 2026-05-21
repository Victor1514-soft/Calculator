#include "CalculatorEngine.h"
 double CalculatorEngine::Sum(double x, double y){
    return x + y;
}
double CalculatorEngine::Substract(double x, double y){
    return x - y;
}
double CalculatorEngine::Multiplicate(double x, double y){
    return x*y;
}
double CalculatorEngine::Division(double x, double y){
    if(y == 0.0){
        throw std::invalid_argument("Division by cero is not defined");
    }
    return x/y;
}
double CalculatorEngine::SquareRoot(double x){
    return sqrt(x);
}