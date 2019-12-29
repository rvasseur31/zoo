#ifndef ZOOBUDGET_H
#define ZOOBUDGET_H

#include "zoomessage.h"
#include "zooobject.h"


class ZooBudget : public ZooObject
{
    int money;
    static ZooBudget *m_budget;
public:
    ~ZooBudget();
    int addMoney(int amount);
    bool removeMoney(int amount);
    int getMoney();
    void testMe();
    static ZooBudget *getInstance();
private:
    ZooBudget(const QString &name);
    void setMoney(int value);
};

#endif // ZOOBUDGET_H
