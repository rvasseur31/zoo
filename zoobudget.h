#ifndef ZOOBUDGET_H
#define ZOOBUDGET_H

#include "zooobject.h"
#include "zoomessage.h"


class ZooBudget : public ZooObject
{
    double money;
    static ZooBudget *m_budget;
public:
    ~ZooBudget();
    double addMoney(double amount);
    bool removeMoney(double amount);
    double getMoney();
    void testMe();
    static ZooBudget *getInstance();
private:
    ZooBudget(const QString &name);
    void setMoney(double value);
};

#endif // ZOOBUDGET_H
