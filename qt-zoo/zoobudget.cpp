#include "zoobudget.h"
#include <QDebug>
#include "zoomessage.h"
#include "zoo.h"

ZooBudget *ZooBudget::m_budget = nullptr;

ZooBudget::ZooBudget(const QString &name)
    : ZooObject(name)
    , money(0)
{
    qDebug() << Q_FUNC_INFO << getName();
}

ZooBudget::~ZooBudget()
{

}

int ZooBudget::addMoney(int amount)
{
    money += amount;
    return money;
}

bool ZooBudget::removeMoney(int amount)
{
    if(money < amount){
        ZooMessage* message = new ZooMessage(ZooErrorLevel::ERROR, "Not enough credit", this);
        Zoo::getInstance()->getMessages()->addMessage(message);
        qDebug() << message;
        return false;
    }
    money -= amount;
    return true;
}

int ZooBudget::getMoney()
{
    return money;
}

void ZooBudget::setMoney(int value)
{
    money = value;
}


void ZooBudget::testMe()
{
    addMoney(500);
    if(getMoney() != 500){
        qDebug() << "Budget erroné 1";
    }
    removeMoney(50);
    if(getMoney() != 450){
        qDebug() << "Budget erroné 2";
    }
    if(!removeMoney(1000)){
        qDebug() << "Crédit insuffisant";
    }
    if(getMoney() != 450){
        qDebug() << "Budget erroné 3";
    }
}

ZooBudget *ZooBudget::getInstance()
{
    if(m_budget == nullptr) {
        m_budget = new ZooBudget("Mon budget");
    }
    return m_budget;
}
