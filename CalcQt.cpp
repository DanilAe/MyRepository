#include <QCoreApplication>
#include <QList>
#include <QDebug>

class Calc
{
public:
    static double StartAnalize_GetResult(const QString str)
    {
        double nums[10];
        int count = 0;
        QString num = "";
        QString oper;
        QString s = (str + "$");
        for(int i = 0; i < s.length(); i++)
        {
            switch (s[i].unicode())
            {
            case '+':
                nums[count] = oper == "-" ? -num.toDouble(): num.toDouble();
                num = "";
                count++;
                oper = "+";
                break;
            case '-':
                nums[count] = oper == "-" ? -num.toDouble(): num.toDouble();
                num = "";
                count++;
                oper = '-';
                break;
            case '$':
                nums[count] = oper == "-" ? -num.toDouble(): num.toDouble();
                num = "";
                count++;
                oper = "+";
                break;
            default:
                num += s[i];
                break;

            }
        }
        double result = 0;
        for(int i = 0; i < 10; i++)
        {
            result += nums[i];
        }
        return result;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString str = "10-10-10-10-10";
    qDebug() << str.toStdString().c_str();
    double result = Calc::StartAnalize_GetResult(str);
    qDebug() << "result = " << result;
    return a.exec();
}
