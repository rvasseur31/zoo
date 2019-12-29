#ifndef ZOOMESSAGE_H
#define ZOOMESSAGE_H

#include "zooobject.h"

enum ZooErrorLevel {
    ERROR, WARNING, INFO, VERBOSE, DEBUG
};

class ZooMessage : public ZooObject
{
    ZooErrorLevel errorLevel;
    QString message;
    ZooObject* from;

public:
    ZooMessage(ZooErrorLevel errorLevel, QString message, ZooObject *from);
    ZooErrorLevel getErrorLevel() const;
    QString getMessage() const;
    ZooObject *getFrom() const;
    QString getEmitterName() const;
};

#endif // ZOOMESSAGE_H
