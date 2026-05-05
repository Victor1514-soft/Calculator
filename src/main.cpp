#include <QApplication>
#include "Calculator.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Calculator calculator = Calculator();
    calculator.setFixedSize(640,450);
    calculator.setWindowTitle("Calculadora");
    calculator.show();
    return app.exec();
}