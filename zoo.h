#ifndef ZOO_H
#define ZOO_H

#include "zooobject.h"
#include "zoobudget.h"
#include "zoomessages.h"
#include "zoostock.h"
#include "habitats.h"

#include "AnimalType.h"

#include <QDebug>
#include <QMap>

typedef QMap<QString, ZooStock*> Stocklist;

class Habitats;
class Habitat;

class Zoo : public ZooObject
{
    ZooBudget *m_budget;
    Stocklist stockList;
    ZooMessages *log;
    Habitats *habitats;

    static Zoo *m_zoo;
public:
    static Zoo *getInstance(const QString &name = "");
    ~Zoo();
    double addMoney(double amount);
    bool removeMoney(double amount);
    double getMoney();
    void testMe();

    Stocklist getStockList() const;
    ZooMessages *getLog() const;

    QVector<Habitat *> getHabitatListByHabitatType(AnimalType animalType);
    Habitats *getHabitats() const;
    bool buyHabitat(AnimalType animalType);
    void testHabitat();
    bool sellHabitat(Habitat *habitat);
    bool destroyHabitat(Habitat *habitat);
private:
    Zoo(const QString &name);
};

#endif // ZOO_H
