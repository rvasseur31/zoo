#include "zoostock.h"

ZooStock::ZooStock(const QString &name, double quantity)
    : ZooObject(name)
{
    setQuantity(quantity);
}

double ZooStock::getQuantity() const
{
    return quantity;
}

void ZooStock::setQuantity(double value)
{
    quantity = value;
}

double ZooStock::addQuantity(double amount)
{
    quantity += amount;
    return quantity;
}

bool ZooStock::removeQuantity(double amount)
{
    if(quantity < amount){
        return false;
    }
    quantity -= amount;
    return true;
}
