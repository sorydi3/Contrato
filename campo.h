#ifndef CAMPO_H
#define CAMPO_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>

class Campo : public QWidget
{
    Q_OBJECT
public:
    explicit Campo(QWidget *parent = nullptr);
    void addText(QString text);
    QString getText() const;
    QString getLineEditText();
    bool operator==(const Campo &campo) const;

signals:
private:
    QLabel text;
    QLineEdit lineEdit;
};
#endif // CAMPO_H
