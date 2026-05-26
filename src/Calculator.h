#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <cmath>
#include <string>
#include <iostream>

class Calculator:public QWidget{
Q_OBJECT
private:
QPushButton *NumberButtons[10];
QPushButton *OperationButtons[5];
QPushButton *DeleteButton;
QPushButton *ClearButton;
QPushButton*NegativeSingButton;
QPushButton*DecimalButton;
QPushButton*SquareRootButton;

//here i added de QGridLayout  QVBoxLayout and QLineEdit to can use slots

QVBoxLayout * box;
QGridLayout*  buttons_grid;
QLineEdit * display;

public:

 explicit Calculator(QWidget *parent = nullptr); //following Qt recomendation
 double Sum(double x, double y);
 double Substract(double x,double y);
 double Multiplicate(double x,double y);
 double Division(double x,double y);
 double SquareRoot(double x);

public slots:

void number_slot();
void operation_slot();
void delete_button_slot();
void clear_button_slot();
void sign_button_slot();
void decimal_button_slot();
void squareroot_slot(); 
};