#ifndef ZOOANIMALS_H
#define ZOOANIMALS_H

#include "zoohabitat.h"

class ZooAnimals : public ZooObject
{
    ZooHabitat* parent = nullptr;
public:
    ZooAnimals(ZooHabitat* parent);
};

#endif // ZOOANIMALS_H
