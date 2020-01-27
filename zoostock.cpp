#include "zoostock.h"
#include "zoo.h"

ZooStock::ZooStock(const QString &name, double quantity)
    : ZooObject(name)
    , quantity(quantity)
{}

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
    Zoo::getInstance()->getLog()->addMessage(new ZooMessage(ZooErrorLevel::INFO, "Vous venez d'ajouter " + QString::number(amount) + " Kg de " + getName(), this));
    return quantity;
}

bool ZooStock::removeQuantity(double amount)
{
    if(quantity < amount){
        Zoo::getInstance()->getLog()->addMessage(new ZooMessage(ZooErrorLevel::ERROR, "Il n'y a plus assez de " + getName(), this));
        return false;
    }
    quantity -= amount;
    Zoo::getInstance()->getLog()->addMessage(new ZooMessage(ZooErrorLevel::INFO, "Vous venez de retirer " + QString::number(amount) + " Kg de " + getName(), this));
    return true;
}

void ZooStock::test() {
        qDebug() << "Stock: " << getQuantity();
        if(!removeQuantity(12)){
            qDebug() << "Seed stock error";
        }
        qDebug() << "Stock : " << getQuantity();
}
