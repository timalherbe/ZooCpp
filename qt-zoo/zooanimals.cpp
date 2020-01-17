#include "zooanimals.h"

ZooHabitat *ZooAnimals::getParent() const
{
    return parent;
}

void ZooAnimals::setParent(ZooHabitat *value)
{
    parent = value;
}

AnimalList *ZooAnimals::getAnimals() const
{
    return animals;
}

void ZooAnimals::addAnimal(ZooAnimal *animal)
{
    animals->push_back(animal);
}

ZooAnimals::ZooAnimals(ZooHabitat* parent):ZooObject("Animals"), parent(parent)
{

}
