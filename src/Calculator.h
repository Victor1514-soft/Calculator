#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include "CalculatorEngine.h"
#include <stack>
class Calculator:public QWidget{
Q_OBJECT
private:

CalculatorEngine engine;
QPushButton *NumberButtons[10];
QPushButton *OperationButtons[5];
QPushButton *DeleteButton;
QPushButton *ClearButton;
QPushButton*NegativeSingButton;
QPushButton*DecimalButton;
double result;
std::stack<double>History;

public:

Calculator();
double getResult();
void setResult(double result);

};