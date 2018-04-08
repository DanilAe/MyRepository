#ifndef CALC_H
#define CALC_H
#include <QCoreApplication>

class Calc
{
    double GetResult(double num_1, double num_2, QChar oper);
public:
    double StartAnalize_GetResult(QString str);
};

#endif // CALC_H
