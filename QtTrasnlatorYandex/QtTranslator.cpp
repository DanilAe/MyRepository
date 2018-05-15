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
    QString url = "https://translate.yandex.net/api/v1.5/tr/translate?key=%1&lang=ru-en&text=%2&format=html";
    url = url.arg(apikey).arg(text);
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

