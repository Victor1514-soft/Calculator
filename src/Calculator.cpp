#include "Calculator.h"
Calculator::Calculator(QWidget *parent){

    //init
    for(int i = 0; i < 10 ; ++i){
        NumberButtons[i] = new QPushButton(QString::number(i),this);
    }
    OperationButtons[0] = new QPushButton("+",this);
    OperationButtons[1] = new QPushButton("-",this);
    OperationButtons[2] = new QPushButton("x",this);
    OperationButtons[3] = new QPushButton ("/" ,this);
    OperationButtons[4] = new QPushButton("=",this);
    DeleteButton = new QPushButton("<-",this);
    ClearButton  = new QPushButton("C",this);
    NegativeSingButton = new QPushButton("-y",this);
    DecimalButton = new QPushButton(".",this);
    SquareRootButton = new QPushButton("sqrt()",this);

    QGridLayout *grid = new QGridLayout();

    grid->addWidget(NumberButtons[7],0,0);
    grid->addWidget(NumberButtons[8],0,1);
    grid->addWidget(NumberButtons[9],0,2);
    grid->addWidget(NumberButtons[4],1,0);
    grid->addWidget(NumberButtons[5],1,1);
    grid->addWidget(NumberButtons[6],1,2);
    grid->addWidget(NumberButtons[1],2,0);
    grid->addWidget(NumberButtons[2],2,1);
    grid->addWidget(NumberButtons[3],2,2);
    grid->addWidget(NegativeSingButton,3,0);
    grid->addWidget(NumberButtons[0],3,1);
    grid->addWidget(DecimalButton,3,2);
    grid->addWidget(OperationButtons[0],0,3);
    grid->addWidget(OperationButtons[1],1,3);
    grid->addWidget(OperationButtons[2],2,3);
    grid->addWidget(OperationButtons[3],3,3);
    grid->addWidget(OperationButtons[4],3,4);
    grid->addWidget(ClearButton,2,4);
    grid->addWidget(DeleteButton,1,4);
    grid->addWidget(SquareRootButton,0,4);
    grid->setSpacing(0);

    QVBoxLayout *Box = new QVBoxLayout(this);
    QLineEdit *display = new QLineEdit;

    display->setText("Hello");
    display->setReadOnly(true);
    display->setFixedHeight(75);
    
    Box->addWidget(display);
    Box->addLayout(grid);
    Box->setContentsMargins(20,20,20,0);
    Box->setSpacing(0);
}  
