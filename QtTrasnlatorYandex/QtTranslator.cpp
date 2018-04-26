void Widget::on_pushButton_clicked()
{
    QString text = ui->plainTextEdit->toPlainText();
    GetTranslate(text);

}

void Widget::GetTranslate(QString text)
{
    QString args[2];
    args[0] = apikey;
    args[1] = text;
    QString url = format("https://translate.yandex.net/api/v1.5/tr/translate?key={0}&lang=ru-en&text={1}&format=html",args,2);
    qDebug() << url;
    manager = new QNetworkAccessManager();
    reply = manager->get(QNetworkRequest(QUrl(url)));
    connect(reply, SIGNAL(finished()), this,SLOT(replyfinished()));
}

void Widget::replyfinished()
{
    QString text;
    text.append(reply->readAll());
    QDomDocument doc;
    doc.setContent(text);
    QDomElement element = doc.documentElement();
    QDomNode node = element.firstChild();
    QDomElement el = node.toElement();
    qDebug() << el.text();
    ui->plainTextEdit_2->setPlainText(el.text());
}

QString Widget::format(const QString format, const QString args[], const int count)
{
    QString str = format;
    for(int i = 0; i < count;i++)
    {
        str = str.replace("{" + QString::number(i) + "}", args[i]);
    }
    return str;
}
