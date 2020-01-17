#ifndef ZOOHABITATS_H
#define ZOOHABITATS_H

#include <QVector>
#include "zooobject.h"

class ZooHabitat;

typedef QVector<ZooHabitat*> HabitatList;
class ZooHabitats : public ZooObject
{
    static ZooHabitats *m_habitats;
    ZooHabitats();
    HabitatList *habitats;
public:
    static ZooHabitats* getInstance();
    HabitatList *getHabitats() const;
    void addHabitat(ZooHabitat* habitat);
};

#endif // ZOOHABITATS_H
