#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLineEdit>
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
QPushButton*SquareRootButton;

public:

explicit Calculator(QWidget *parent = nullptr); //following Qt recomendation
};