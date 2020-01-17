#include "zoohabitat.h"

class ZooHabitats;

ZooAnimals* ZooHabitat::getAnimals() const
{
    return animals;
}

void ZooHabitat::setAnimals(ZooAnimals *value)
{
    animals = value;
}

int ZooHabitat::getPrice() const
{
    return price;
}

void ZooHabitat::setPrice(int value)
{
    price = value;
}

ZooHabitat::ZooHabitat(ZooHabitats* parent)
    :ZooObject("habitats"), parent(parent)
{

}

ZooHabitat::~ZooHabitat()
{
    delete animals, parent;
}

ZooHabitats *ZooHabitat::getParent() const
{
    return parent;
}

void ZooHabitat::setParent(ZooHabitats *value)
{
    parent = value;
}
