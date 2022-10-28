#include "campos.h"

Campos::Campos(QWidget *parent)
    : QWidget{parent}
{
    this->setLayout(new QVBoxLayout());
}

void Campos::addCampo(Campo *campo)
{
    std::pair<std::set<Campo *>::iterator, bool> ret = campos.insert(campo);
    if (ret.second == false)
    {
        qDebug() << "campo already exists";
        return;
    }
    else
    {
        qDebug() << "campo added";
        this->layout()->addWidget(campo);
    }
}

void Campos::mapLineEditToLabel()
{
    foreach (Campo *c, campos)
    {
        mapLineELabel.insert(c->getText(), c->getLineEditText());
    }
}

QMap<QString, QString> Campos::getMapLineELabel() const
{
    return mapLineELabel;
}
