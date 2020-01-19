#include "zoo.h"

Zoo *Zoo::m_zoo = nullptr;

Zoo::Zoo(const QString &name)
    : ZooObject(name)
    , m_budget(ZooBudget::getInstance())
    , log(new ZooMessages())
    , habitats(Habitats::getInstance())
{
    qDebug() << Q_FUNC_INFO << getName();
    stockList["seed"] = new ZooStock("seed", 12.5);
    stockList["meat"] = new ZooStock("meat", 50);
}

Stocklist Zoo::getStockList() const
{
    return stockList;
}

ZooMessages *Zoo::getLog() const
{
    return log;
}

Habitats *Zoo::getHabitats() const
{
    return habitats;
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
    qDebug() << Q_FUNC_INFO << getName();
    delete m_budget;

    Stocklist::iterator i;
    for(i = stockList.begin(); i != stockList.end(); ++i){
        qDebug() << Q_FUNC_INFO << i.value()->getName();
        delete i.value();
    }

    delete log;
    delete habitats;
}

double Zoo::addMoney(double amount)
{
    return m_budget->addMoney(amount);
}

bool Zoo::removeMoney(double amount)
{
    return m_budget->removeMoney(amount);
}

double Zoo::getMoney()
{
    return m_budget->getMoney();
}

QVector<Habitat *> Zoo::getHabitatListByHabitatType(AnimalTypeEnum animalType){
    return habitats->getHabitatListByHabitatType(animalType);
}

bool Zoo::buyHabitat(AnimalTypeEnum animalType){
    return habitats->buyHabitat(animalType);
}

bool Zoo::sellHabitat(Habitat *habitat){
    return habitats->sellHabitat(habitat);
}

bool Zoo::destroyHabitat(Habitat *habitat){
    return habitats->destroyHabitat(habitat);
}

void Zoo::testHabitat(){
    buyHabitat(AnimalTypeEnum::AIGLE);
    buyHabitat(AnimalTypeEnum::AIGLE);
    buyHabitat(AnimalTypeEnum::AIGLE);
    QVector<Habitat *> habitatList = getHabitatListByHabitatType(AnimalTypeEnum::AIGLE);
    for (int i = 0; i < habitatList.length(); i++) {
        qDebug() << Q_FUNC_INFO << i+1;
    }
}

//void Zoo::testMe()
//{
//    qDebug() << Q_FUNC_INFO << getName();
//    m_budget->testMe();
//    testStock();
//}
