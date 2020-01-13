#include "zoohabitat.h"

ZooHabitat::ZooHabitat(ZooHabitats* parent)
    :ZooObject("habitats"), parent(parent)
{

}

ZooHabitats *ZooHabitat::getParent() const
{
    return parent;
}

void ZooHabitat::setParent(ZooHabitats *value)
{
    parent = value;
}

ZooHabitat::~ZooHabitat()
{
    delete animals;
}

void ZooHabitat::addAnimal(ZooAnimal *animal)
{
    animals->push_back(animal);
}

ZooHabitat::AnimalList* ZooHabitat::getAnimals()
{
    return animals;
}
