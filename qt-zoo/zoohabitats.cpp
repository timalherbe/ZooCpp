#include "zoohabitats.h"

ZooHabitats::ZooHabitats():ZooObject("habitats")
{

}

HabitatList *ZooHabitats::getHabitats() const
{
    return habitats;
}

void ZooHabitats::addHabitat(ZooHabitat *habitat)
{
    habitats->push_back(habitat);
}

ZooHabitats *ZooHabitats::getInstance()
{
    if(m_habitats == nullptr) {
        m_habitats = new ZooHabitats();
    }
    return m_habitats;
}
