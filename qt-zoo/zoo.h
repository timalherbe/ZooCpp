#ifndef ZOO_H
#define ZOO_H

#include "zoobudget.h"
#include "zooobject.h"
#include "zoostock.h"
#include "zoomessages.h"
#include <QMap>
#include <QVector>
#include "zoohabitat.h"
#include "zoohabitats.h"

typedef QMap<QString, ZooStock*> Stocklist;

class Zoo : public ZooObject
{
    ZooBudget *m_budget;
    Stocklist stockList;
    static Zoo *m_zoo;
    ZooMessages *m_messages;
    ZooHabitats* habitats;
public:
    static Zoo *getInstance(const QString &name = "");
    ~Zoo();
    int addMoney(int amount);
    bool removeMoney(int amount);
    int getMoney();
    void testMe();
    ZooMessages *getMessages() const;
    bool buyHabitat();
    bool sellHabitat(ZooHabitat* habitat);
    bool destroyHabitat(ZooHabitat* habitat);
    ZooHabitats* getHabitats();

private:
    Zoo(const QString &name);
};

#endif // ZOO_H
