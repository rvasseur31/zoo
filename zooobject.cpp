#include "zooobject.h"
#include <QDebug>

QString ZooObject::getName() const
{
    return name;
}

void ZooObject::setName(const QString &value)
{
    name = value;
}

ZooObject::ZooObject(const QString &name)
{
    qDebug() << Q_FUNC_INFO << name;
    setName(name);
}

ZooObject::~ZooObject()
{
    qDebug() << Q_FUNC_INFO << getName();
}
