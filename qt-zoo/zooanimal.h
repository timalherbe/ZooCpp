#ifndef ZOOANIMAL_H
#define ZOOANIMAL_H

#include "zooanimals.h"
#include "zooobject.h"

class ZooAnimal : public ZooObject
{
    ZooAnimals* parent = nullptr;
public:
    ZooAnimal(ZooAnimals* parent);
    ~ZooAnimal();

};

#endif // ZOOANIMAL_H
