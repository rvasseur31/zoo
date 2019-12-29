#ifndef ZOOOBJECT_H
#define ZOOOBJECT_H

#include <QString>



class ZooObject
{
    QString name;
public:
    ZooObject(const QString &name);
    ~ZooObject();
    QString getName() const;
    void setName(const QString &value);
};

#endif // ZOOOBJECT_H
