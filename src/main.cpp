#include <QApplication>
#include "Calculator.h"
#include <QFile>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setApplicationDisplayName("Incredible MathTool Solver");
    QFile file = QFile("Calculator.qss");
    file.open(QFile::ReadOnly);
    QString style = file.readAll();
    Calculator calculator = Calculator(); 
    calculator.setFixedSize(400,500);  
    calculator.setStyleSheet(style);
    calculator.show();
    return app.exec();
}