#ifndef ZOOMESSAGES_H
#define ZOOMESSAGES_H

#include "zoomessage.h"
#include "zooobject.h"
#include <QVector>

class ZooMessages : public ZooObject
{
    QVector<ZooMessage*> messages;
public:
    ZooMessages();
    ~ZooMessages();
    void addMessage(ZooMessage *zooMessage);
    QVector<ZooMessage *> getMessages() const;
    QVector<ZooMessage *> getMessagesByErrorLevel(ZooErrorLevel errorLevel) const;
    QVector<ZooMessage *> getMessagesByEmitter(ZooObject *emitter) const;
    QString getLastMessage() const;
};

#endif // ZOOMESSAGES_H
