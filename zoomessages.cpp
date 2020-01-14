#include "zoomessages.h"
#include <QDebug>

QVector<ZooMessage *> ZooMessages::getMessages() const
{
    return messages;
}

QVector<ZooMessage *> ZooMessages::getMessagesByErrorLevel(ZooErrorLevel errorLevel) const
{
    QVector<ZooMessage *> newMessagesList;
    for(int i = 0; i < messages.size() - 1; i++){
        if (messages.at(i)->getErrorLevel() == errorLevel){
            newMessagesList.push_back(messages.at(i));
        }
    }
    return newMessagesList;
}

QVector<ZooMessage *> ZooMessages::getMessagesByEmitter(ZooObject* emitter) const
{
    QVector<ZooMessage *> newMessagesList;
    for(int i = 0; i < messages.size() - 1; i++){
        if (messages.at(i)->getEmitterName() == typeid (emitter).name()){
            newMessagesList.push_back(messages.at(i));
        }
    }
    return newMessagesList;
}

QString ZooMessages::getLastMessage() const
{

    return messages.last()->getMessage();
}

ZooMessages::ZooMessages():ZooObject("Mes logs")
{

}

void ZooMessages::addMessage(ZooMessage *zooMessage)
{
    messages.push_back(zooMessage);
}

ZooMessages::~ZooMessages(){
    qDebug() << Q_FUNC_INFO << getName();
    for(int i = 0; i < getMessages().size(); i++){
        qDebug() << Q_FUNC_INFO << getMessages().at(i)->getName();
        delete getMessages().at(i);
    }
}



