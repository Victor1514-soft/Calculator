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

    this->buttons_grid = new QGridLayout();

    buttons_grid->addWidget(NumberButtons[7],0,0);
    buttons_grid->addWidget(NumberButtons[8],0,1);
    buttons_grid->addWidget(NumberButtons[9],0,2);
    buttons_grid->addWidget(NumberButtons[4],1,0);
    buttons_grid->addWidget(NumberButtons[5],1,1);
    buttons_grid->addWidget(NumberButtons[6],1,2);
    buttons_grid->addWidget(NumberButtons[1],2,0);
    buttons_grid->addWidget(NumberButtons[2],2,1);
    buttons_grid->addWidget(NumberButtons[3],2,2);
    buttons_grid->addWidget(NegativeSingButton,3,0);
    buttons_grid->addWidget(NumberButtons[0],3,1);
    buttons_grid->addWidget(DecimalButton,3,2);
    buttons_grid->addWidget(OperationButtons[0],0,3);
    buttons_grid->addWidget(OperationButtons[1],1,3);
    buttons_grid->addWidget(OperationButtons[2],2,3);
    buttons_grid->addWidget(OperationButtons[3],3,3);
    buttons_grid->addWidget(OperationButtons[4],3,4);
    buttons_grid->addWidget(ClearButton,2,4);
    buttons_grid->addWidget(DeleteButton,1,4);
    buttons_grid->addWidget(SquareRootButton,0,4);
    buttons_grid->setSpacing(0);

    this->box = new QVBoxLayout(this);
    this->display= new QLineEdit;

    display->setReadOnly(true);
    display->setFixedHeight(75);
    
    box->addWidget(display);
    box->addLayout(buttons_grid);
    box->setContentsMargins(20,20,20,0);
    box->setSpacing(0);

    //Buttons Functionalities
    for(int j = 0; j < 10; j++){
    QObject::connect(NumberButtons[j],&QPushButton::clicked,this,&number_slot);
    }

    for(int k = 0; k < 5; k++){
    QObject::connect(OperationButtons[k],&QPushButton::clicked,this,&operation_slot);
    }

    QObject::connect(ClearButton,&QPushButton::clicked,this,&clear_button_slot);
    QObject::connect(DeleteButton,&QPushButton::clicked,this,&delete_button_slot);
    QObject::connect(NegativeSingButton,&QPushButton::clicked,this,&sign_button_slot);
    QObject::connect(DecimalButton,&QPushButton::clicked,this,&decimal_button_slot);
}  

void Calculator::number_slot(){
  QPushButton*number = qobject_cast<QPushButton*>(QObject::sender());
  display->setText(display->text() + number->text());
}
/*To be implemented*/
void Calculator::operation_slot(){
    QPushButton* button = qobject_cast<QPushButton*>(QObject::sender());
    if(display->text().isEmpty()){
        display->setText(display->text());
    }
    else if(display->text().at(display->text().length() - 1) == "+" || display->text().at(display->text().length() - 1) == "-" || display->text().at(display->text().length() - 1) == "x" || display->text().at(display->text().length() - 1) == "/" ){
        display->setText(display->text());
    }
    else if(display->text().contains(button->text()) && display->text().at(display->text().length() - 1).isDigit()){
        display->setText(display->text());
    } 
    else if(button->text()!="="){
        display->setText(display->text()  + button->text());
    }
    else{
        QString txt = display->text();
        QString symbol;
        QString number1;
        QString number2;
        QString result;
        int pos;
        for(int w = 0; w < txt.length(); ++w){
            if(txt[w] == "+" || txt[w] == "-" || txt[w] == "x" || txt[w] == "/"){
                symbol = txt[w];
                pos = w;
                break;
            }
        }
        number1 = txt.mid(0,pos);
        number2 = txt.mid(pos + 1,txt.length());
        if(symbol == "+"){
            result = QString::number(Sum(number1.toDouble(),number2.toDouble()));
        }
        else if(symbol == "-"){
            result = QString::number(Substract(number1.toDouble(),number2.toDouble()));
        }
        else if(symbol == "x"){
            result = QString::number(Multiplicate(number1.toDouble(),number2.toDouble()));
        }
        else if(symbol == "/"){
            result = (number2.toDouble() == 0)? "Division by cero is not defined" : QString::number(Division(number1.toDouble(),number2.toDouble()));
        }
        display->setText(result);
    }
}

void Calculator::decimal_button_slot(){
     if(display->text().isEmpty()){
        display->clear();
    }
    else if(display->text().contains('.')){
        display->setText(display->text());
    }
    else{
        display->setText(display->text() + ".");
    }
}

void Calculator::delete_button_slot(){
    QString txt = display->text();
    QString newtxt = txt.removeAt(txt.length() - 1);
    display->setText(newtxt);
}

void Calculator::sign_button_slot(){
    if(display->text().isEmpty()){
        display->clear();
    }
    else if(display->text().at(0) == '-'){
        display->setText(display->text());
    }
    else{
        display->setText("-" + display->text());
    }
}
/*To be implemented*/
void Calculator::squareroot_slot(){

}
void Calculator::clear_button_slot(){
    display->clear();
}

double Calculator::Sum(double x, double y){
    return x + y;
}
double Calculator::Substract(double x, double y){
    return x - y;
}
double Calculator::Multiplicate(double x, double y){
    return x*y;
}
double Calculator::Division(double x, double y){
    if(y == 0){
        throw std::invalid_argument("Division by cero is not defined");
    }
    return x/y;
}
double Calculator::SquareRoot(double x){
    return sqrt(x);
}