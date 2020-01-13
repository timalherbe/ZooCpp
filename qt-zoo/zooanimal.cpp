#include "zooanimal.h"

ZooAnimal::ZooAnimal(ZooAnimals* parent)
    :ZooObject("animal"), parent(parent)
{

}

ZooHabitat* ZooAnimal::getHabitat()
{
    return parent->getParent();
}

ZooAnimals *ZooAnimal::getParent() const
{
    return parent;
}

void ZooAnimal::setParent(ZooAnimals *value)
{
    parent = value;
}
