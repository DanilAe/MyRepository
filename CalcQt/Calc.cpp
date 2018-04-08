#include <QCoreApplication>
#include <QList>
#include <QDebug>
#include <calc.h>
#define NULL 0


double Calc::GetResult(double num_1, double num_2, QChar oper)
{
    double result = oper == '+' ? num_1 + num_2 : oper == '-' ? num_1 - num_2 : oper == '*' ? num_1 * num_2 : num_1 / num_2;
    qDebug() << "GetResult(" << num_1 << ", " << num_2 << ", " << oper << ") = " << result;
    return result;
}



double Calc::StartAnalize_GetResult(QString str)
{
    qDebug() << "\nAnalize: " << str;
    double result = 0;
    int count = 0;
    QString num = "";
    QChar oper;

    if(str.contains("+-"))
        str = str.replace("+-", "-");
    if(str.contains("--"))
        str = str.replace("--","+");
    QString s = (str + "$");
    for(int i = 0; i < s.length(); i++)
    {
        switch (s[i].unicode())
        {
        case '+':
            if(num != "")
                count == 0 ? result = num.toDouble() : result = GetResult(result, num.toDouble(), oper);
            num = "";
            count++;
            oper = '+';
            break;
        case '-':
            if(num != "")
                count == 0 ? result = num.toDouble() : result = GetResult(result, num.toDouble(), oper);
            num = "";
            count++;
            oper = '-';
            break;
        case '*':
            if(num != "")
                count == 0 ? result = num.toDouble() : result = GetResult(result, num.toDouble(), oper);
            num = "";
            count++;
            oper = '*';
            break;
        case '/':
            if(num != "")
                count == 0 ? result = num.toDouble() : result = GetResult(result, num.toDouble(), oper);
            num = "";
            count++;
            oper = '/';
            break;
        case '(':
        {
            QString expr = "";
            for(int k = ++i; s[k] != ')'; k++)
            {
                expr.append(s[k]);
                i++;
            }
            i--;
            count == 0 ? result = num.toDouble() : result = GetResult(result, StartAnalize_GetResult(expr), oper);;
            qDebug() << "\nContinue Analize: " << str;
            if( i >= s.length() || s[++i] == '$')
                return result;
            count++;
            break;
        }
        case '$':
            if(num != "")
                result = GetResult(result, num.toDouble(), oper);
            count++;
            break;
        default:
            num += s[i];
            break;
        }
    }
    return result;
}
