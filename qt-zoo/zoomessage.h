#ifndef ZOOMESSAGE_H
#define ZOOMESSAGE_H

#include "zooobject.h"
#include <QString>

enum ZooErrorLevel{
    ERROR, WARNING, INFO, VERBOSE, DEBUG
};
class ZooMessage : public ZooObject
{
private:
    ZooErrorLevel errorLevel;
    QString message;
    ZooObject* from; //emetteur

public:
    ZooMessage(ZooErrorLevel errorLevel, QString message, ZooObject* from);

    ZooErrorLevel getErrorLevel() const;
    QString getMessage() const;
    ZooObject *getFrom() const;
    QString getEmittorName();
};

#endif // ZOOMESSAGE_H
