#include "zoomessage.h"

ZooErrorLevel ZooMessage::getErrorLevel() const
{
    return errorLevel;
}

QString ZooMessage::getMessage() const
{
    return message;
}

ZooObject *ZooMessage::getFrom() const
{
    return from;
}

QString ZooMessage::getEmitterName() const
{
    return typeid (from).name();
}

ZooMessage::ZooMessage(ZooErrorLevel errorLevel, QString message, ZooObject *from)
    :ZooObject("ZooMessage"),
    errorLevel(errorLevel),
    message(message),
    from(from){}
