#ifndef ZOOANIMAL_H
#define ZOOANIMAL_H

#include "zooanimals.h"
#include "zooobject.h"
#include "zoohabitat.h"

class ZooAnimals;
class ZooHabitat;

class ZooAnimal : public ZooObject
{
    ZooAnimals* parent = nullptr;
public:
    ZooAnimal(ZooAnimals* parent);
    ~ZooAnimal();
    ZooHabitat* getHabitat();
    ZooAnimals *getParent() const;
    void setParent(ZooAnimals *value);
};

#endif // ZOOANIMAL_H
