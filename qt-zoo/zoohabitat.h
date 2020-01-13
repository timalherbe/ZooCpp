#ifndef ZOOHABITAT_H
#define ZOOHABITAT_H

#include "zooobject.h"
#include <QVector>
#include "zooanimal.h"
#include "zoohabitats.h"

class ZooHabitat : public ZooObject
{
    typedef QVector<ZooAnimal*> AnimalList;
    ZooHabitats* parent = nullptr;
    AnimalList *animals;
public:
    ZooHabitat(ZooHabitats* parent);
    ~ZooHabitat();
    void addAnimal(ZooAnimal *animal);
    AnimalList* getAnimals();
};

#endif // ZOOHABITAT_H