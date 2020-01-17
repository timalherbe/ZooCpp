#ifndef ZOOANIMALS_H
#define ZOOANIMALS_H

#include "zooanimal.h"
#include "zoohabitat.h"
#include <QVector>

class ZooAnimal;

typedef QVector<ZooAnimal*> AnimalList;
class ZooAnimals : public ZooObject
{
    ZooHabitat* parent = nullptr;
    AnimalList *animals;
public:
    ZooAnimals(ZooHabitat* parent);
    ZooHabitat *getParent() const;
    void setParent(ZooHabitat *value);
    AnimalList *getAnimals() const;
    void addAnimal(ZooAnimal* animal);
};

#endif // ZOOANIMALS_H
