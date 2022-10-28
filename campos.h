#ifndef CAMPOS_H
#define CAMPOS_H

#include <QWidget>
#include "campo.h"
#include <QSet>
#include <set>
#include <QMap>

class Campos : public QWidget
{
    Q_OBJECT
public:
    explicit Campos(QWidget *parent = nullptr);
    void addCampo(Campo *campo);
    void mapLineEditToLabel();
    QMap<QString, QString> getMapLineELabel() const;
signals:

private:
    std::set<Campo *>
        campos;
    QMap<QString, QString> mapLineELabel;
};

#endif // CAMPOS_H
