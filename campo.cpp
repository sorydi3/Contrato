#include "campo.h"

Campo::Campo(QWidget *parent)
    : QWidget{parent}
{
    setLayout(new QVBoxLayout());
    this->layout()->addWidget(&text);
    this->layout()->addWidget(&lineEdit);
    text.setFixedHeight(10);
    lineEdit.setFixedHeight(20);

    setFixedHeight(50);

    // setStyleSheet("background-color: #;");
}

void Campo::addText(QString text)
{

    Campo::text.setText(text);
}

QString Campo::getLineEditText()
{
    return lineEdit.text();
}

bool Campo::operator==(const Campo &campo) const
{
    qDebug() << "checking operator";
    return QString::compare(this->text.text(), campo.text.text(), Qt::CaseInsensitive) == 0;
}

QString Campo::getText() const
{
    return text.text();
}
