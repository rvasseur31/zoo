#ifndef ZOOSTOCK_H
#define ZOOSTOCK_H

#include "zooobject.h"



class ZooStock : public ZooObject
{
    double quantity;
public:
    ZooStock(const QString &name, double quantity);
    double getQuantity() const;
    double addQuantity(double amount);
    bool removeQuantity(double amount);
    void setQuantity(double value);
};

#endif // ZOOSTOCK_H
