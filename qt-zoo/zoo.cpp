#include "zoo.h"
#include <QDebug>

Zoo *Zoo::m_zoo = nullptr;

Zoo::Zoo(const QString &name)
    : ZooObject(name)
    , m_budget(ZooBudget::getInstance())
    , m_messages(new ZooMessages())
{
    qDebug() << Q_FUNC_INFO << getName();
    stockList["seed"] = new ZooStock("seed", 12.5);
    stockList["meat"] = new ZooStock("meat", 50);
}

ZooMessages *Zoo::getMessages() const
{
    return m_messages;
}

bool Zoo::buyHabitat()
{
    ZooHabitat* habitat;
    int amount = habitat->getPrice();
    ZooBudget* budget = ZooBudget::getInstance();
    if (budget->removeMoney(amount)){
        ZooHabitats::getInstance()->addHabitat(habitat);
        return true;
    }
    return false;
}

bool Zoo::sellHabitat(ZooHabitat* habitat)
{
    ZooBudget::getInstance()->addMoney(ZooHabitats::getInstance()->getHabitats()->contains(habitat));//pas fini
}

bool Zoo::destroyHabitat(ZooHabitat* habitat)
{

}

ZooHabitats *Zoo::getHabitats()
{

    return ZooHabitats::getInstance();
}

Zoo *Zoo::getInstance(const QString &name)
{
    if(m_zoo == nullptr) {
        m_zoo = new Zoo(name);
    }
    return m_zoo;
}

Zoo::~Zoo()
{
    qDebug() << Q_FUNC_INFO;
    delete m_budget;
    delete m_messages;

    Stocklist::iterator i;
    for(i = stockList.begin(); i != stockList.end(); ++i){
        qDebug() << Q_FUNC_INFO << i.value()->getName();
        delete i.value();
    }
}

int Zoo::addMoney(int amount)
{
    return m_budget->addMoney(amount);
}

bool Zoo::removeMoney(int amount)
{
    return m_budget->removeMoney(amount);
}

int Zoo::getMoney()
{
    return m_budget->getMoney();
}

//void Zoo::testStock()
//{
//    qDebug() << "Meat stock: " << getMeat();
//    qDebug() << "Seed stock: " << getSeed();
//    if(!removeSeed(12)){
//        qDebug() << "Seed stock error";
//    }
//    if(addMeat(21.5) != 71.5){
//        qDebug() << "Meat stock error";
//    }
//    qDebug() << "Meat stock: " << getMeat();
//    qDebug() << "Seed stock: " << getSeed();
//}

void Zoo::testMe()
{
    qDebug() << Q_FUNC_INFO << getName();
    m_budget->testMe();
//    testStock();
}
