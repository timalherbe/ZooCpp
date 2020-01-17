#ifndef ZOOHABITAT_H
#define ZOOHABITAT_H

#include "zooobject.h"
#include "zooanimals.h"

class ZooHabitats;
class ZooAnimals;

class ZooHabitat : public ZooObject
{
    ZooHabitats* parent = nullptr;
    ZooAnimals* animals = nullptr;
    int price;
public:
    ZooHabitat(ZooHabitats* parent);
    ~ZooHabitat();
    ZooHabitats *getParent() const;
    void setParent(ZooHabitats *value);
    ZooAnimals* getAnimals() const;
    void setAnimals(ZooAnimals *value);
    int getPrice() const;
    void setPrice(int value);
};

#endif // ZOOHABITAT_H
