#ifndef ZOO_H
#define ZOO_H

#include "zoobudget.h"
#include "zoomessages.h"
#include "zooobject.h"
#include "zoostock.h"
#include <QMap>

typedef QMap<QString, ZooStock*> Stocklist;

class Zoo : public ZooObject
{
    ZooBudget *m_budget;
    Stocklist stockList;
    ZooMessages *log;
    static Zoo *m_zoo;
public:
    static Zoo *getInstance(const QString &name = "");
    ~Zoo();
    int addMoney(int amount);
    bool removeMoney(int amount);
    int getMoney();
    void testMe();

    Stocklist getStockList() const;

    ZooMessages *getLog() const;

private:
    Zoo(const QString &name);
};

#endif // ZOO_H
