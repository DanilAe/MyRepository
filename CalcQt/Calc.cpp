#include <QCoreApplication>
#include <QList>
#include <QDebug>
#include <calc.h>
#include <num.h>

double Calc::GetResult(double num_1, double num_2, QChar oper)
{
    double result = oper == PLUS ? num_1 + num_2 : oper == MINUS ? num_1 - num_2 : oper == MUL ? num_1 * num_2 : num_1 / num_2;
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
        case PLUS:
            if(num != "")
                count == 0 ? result = num.toDouble() : result = GetResult(result, num.toDouble(), oper);
            num = "";
            count++;
            oper = PLUS;
            break;
        case MINUS:
            if(num != "")
                count == 0 ? result = num.toDouble() : result = GetResult(result, num.toDouble(), oper);
            num = "";
            count++;
            oper = MINUS;
            break;
        case MUL:
            if(num != "")
                count == 0 ? result = num.toDouble() : result = GetResult(result, num.toDouble(), oper);
            num = "";
            count++;
            oper = MUL;
            break;
        case DIV:
            if(num != "")
                count == 0 ? result = num.toDouble() : result = GetResult(result, num.toDouble(), oper);
            num = "";
            count++;
            oper = DIV;
            break;
        case BRACKET:
        {
            QString expr = "";
            for(int k = ++i; s[k] != ')'; k++)
            {
                expr.append(s[k]);
                i++;
            }
            i--;
            count == 0 ? result = num.    if(ui->label->text() == "0" && ui->label_2->text() == "")
272
        return;
273
    if(ui->label_2->text() == "" && ui->label->text() != "0")
274
    {
275
        Calc calc;
276
        ui->label->setText(QString::number(calc.GetResult(0, ui->label->text().toDouble(), '+')));
277
    }
278
    else
279
    {
280
        QString str;
281
        QString label = (!ui->label->text().endsWith(".") ? ui->label->text() : ui->label->text() + "0");
282
        bool b = label.startsWith("-") && ((ui->label_2->text().endsWith("*")) || (ui->label_2->text().endsWith("÷")));
283
        str = (b ? ui->label_2->text() + "(" + label + ")" : ui->label_2->text()  + label);
284
        str = str.replace("÷", "/");
285
        ui->label->setText(QString::number(calc.StartAnalize_GetResult(str)));
286
        ui->label_2->setText("");
287
    }
288
}
289
​
290
void CalcWidget::on_pushButton_14_clicked()
291
{
292
    double num = ui->label->text().toDouble();
293
    ui->label->setText(QString::number(num * -1, 'g', 10));
294
}
295
​
296
void CalcWidget::on_pushButton_Point_clicked()
297
{
298
    if(!ui->label->text().contains("."))
299
        ui->label->setText(ui->label->text() + ".");
300
}
301
​
302
​
303
void CalcWidget::on_pushButton_16_clicked()
304
{
305
    ui->label->setText(QString::number(ui->label->text().toDouble() / 100));
306
}
307
​
308
void CalcWidget::on_pushButton_17_clicked()
309
{
310
    if(ui->label_2->text().endsWith("+") || ui->label_2->text().endsWith("-") || ui->label_2->text().endsWith("/") || ui->label_2->text().endsWith("*") || (ui->label->text() == "0"))
311
    {
312
        if(ui->label->text() == "0")
313
             ui->label->setText("3.1415");
314
        else
315
            ui->label->setText(ui->label->text() + "3.1415");
316
    }    if(ui->label->text() == "0" && ui->label_2->text() == "")
272
        return;
273
    if(ui->label_2->text() == "" && ui->label->text() != "0")
274
    {
275
        Calc calc;
276
        ui->label->setText(QString::number(calc.GetResult(0, ui->label->text().toDouble(), '+')));
277
    }
278
    else
279
    {
280
        QString str;
281
        QString label = (!ui->label->text().endsWith(".") ? ui->label->text() : ui->label->text() + "0");
282
        bool b = label.startsWith("-") && ((ui->label_2->text().endsWith("*")) || (ui->label_2->text().endsWith("÷")));
283
        str = (b ? ui->label_2->text() + "(" + label + ")" : ui->label_2->text()  + label);
284
        str = str.replace("÷", "/");
285
        ui->label->setText(QString::number(calc.StartAnalize_GetResult(str)));
286
        ui->label_2->setText("");
287
    }
288
}
289
​
290
void CalcWidget::on_pushButton_14_clicked()
291
{
292
    double num = ui->label->text().toDouble();
293
    ui->label->setText(QString::number(num * -1, 'g', 10));
294
}
295
​
296
void CalcWidget::on_pushButton_Point_clicked()
297
{
298
    if(!ui->label->text().contains("."))
299
        ui->label->setText(ui->label->text() + ".");
300
}
301
​
302
​
303
void CalcWidget::on_pushButton_16_clicked()
304
{
305
    ui->label->setText(QString::number(ui->label->text().toDouble() / 100));
306
}
307
​
308
void CalcWidget::on_pushButton_17_clicked()
309
{
310
    if(ui->label_2->text().endsWith("+") || ui->label_2->text().endsWith("-") || ui->label_2->text().endsWith("/") || ui->label_2->text().endsWith("*") || (ui->label->text() == "0"))
311
    {
312
        if(ui->label->text() == "0")
313
             ui->label->setText("3.1415");
314
        else
315
            ui->label->setText(ui->label->text() + "3.1415");
316
    }
317
}
318
​
319

317
}
318
​
319
toDouble() : result = GetResult(result, StartAnalize_GetResult(expr), oper);;
            qDebug() << "\nContinue A    if(ui->label->text() == "0" && ui->label_2->text() == "")
272
        return;
273
    if(ui->label_2->text() == "" && ui->label->text() != "0")
274
    {
275
        Calc calc;
276
        ui->label->setText(QString::number(calc.GetResult(0, ui->label->text().toDouble(), '+')));
277
    }
278
    else
279
    {
280
        QString str;
281
        QString label = (!ui->label->text().endsWith(".") ? ui->label->text() : ui->label->text() + "0");
282
        bool b = label.startsWith("-") && ((ui->label_2->text().endsWith("*")) || (ui->label_2->text().endsWith("÷")));
283
        str = (b ? ui->label_2->text() + "(" + label + ")" : ui->label_2->text()  + label);
284
        str = str.replace("÷", "/");
285
        ui->label->setText(QString::number(calc.StartAnalize_GetResult(str)));
286
        ui->label_2->setText("");
287
    }
288
}
289
​
290
void CalcWidget::on_pushButton_14_clicked()
291
{
292
    double num = ui->label->text().toDouble();
293
    ui->label->setText(QString::number(num * -1, 'g', 10));
294
}
295
​
296
void CalcWidget::on_pushButton_Point_clicked()
297
{
298
    if(!ui->label->text().contains("."))
299
        ui->label->setText(ui->label->text() + ".");
300
}
301
​
302
​
303
void CalcWidget::on_pushButton_16_clicked()
304
{
305
    ui->label->setText(QString::number(ui->label->text().toDouble() / 100));
306
}
307
​
308
void CalcWidget::on_pushButton_17_clicked()
309
{
310
    if(ui->label_2->text().endsWith("+") || ui->label_2->text().endsWith("-") || ui->label_2->text().endsWith("/") || ui->label_2->text().endsWith("*") || (ui->label->text() == "0"))
311
    {
312
        if(ui->label->text() == "0")
313
             ui->label->setText("3.1415");
314
        else
315
            ui->label->setText(ui->label->text() + "3.1415");
316
    }
317
}
318
​
319
nalize: " << str;
            if( i >= s.length() || s[++i] == '$')
                return result;
            count++;
            break;
        }
        case END:
            if(num != "")
                result = GetResult(result, num.toDouble(), oper);
            count++;
            break;
        default:
            num += s[i];
            break;
        }
    }
    qDebug() << "Result = " << result;
    return result;
}

