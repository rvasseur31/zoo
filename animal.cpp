#include "animal.h"
#include "animals.h"

Animals *Animal::getParent() const
{
    return parent;
}

void Animal::setParent(Animals *value)
{
    parent = value;
}

bool Animal::getIsFemale() const
{
    return isFemale;
}

void Animal::setIsFemale(bool value)
{
    isFemale = value;
}

FoodType Animal::getFoodType() const
{
    return foodType;
}

void Animal::setFoodType(const FoodType &value)
{
    foodType = value;
}

double Animal::getAmountOfFoodPerDay() const
{
    return amountOfFoodPerDay;
}

void Animal::setAmountOfFoodPerDay(double value)
{
    amountOfFoodPerDay = value;
}

int Animal::getDaysBeforeBeingHungry() const
{
    return daysBeforeBeingHungry;
}

void Animal::setDaysBeforeBeingHungry(int value)
{
    daysBeforeBeingHungry = value;
}

int Animal::getLitter() const
{
    return litter;
}

void Animal::setLitter(int value)
{
    litter = value;
}

int Animal::getSexualMaturity() const
{
    return sexualMaturity;
}

void Animal::setSexualMaturity(int value)
{
    sexualMaturity = value;
}

int Animal::getEndOfBreeding() const
{
    return endOfBreeding;
}

void Animal::setEndOfBreeding(int value)
{
    endOfBreeding = value;
}

int Animal::getChildMortality() const
{
    return childMortality;
}

void Animal::setChildMortality(int value)
{
    childMortality = value;
}

int Animal::getLifeExpectancy() const
{
    return lifeExpectancy;
}

void Animal::setLifeExpectancy(int value)
{
    lifeExpectancy = value;
}

double Animal::getBuyPrice() const
{
    return buyPrice;
}

void Animal::setBuyPrice(double value)
{
    buyPrice = value;
}

double Animal::getSellPrice() const
{
    return sellPrice;
}

void Animal::setSellPrice(double value)
{
    sellPrice = value;
}

QString Animal::getType() const
{
    return type;
}

void Animal::setType(const QString &value)
{
    type = value;
}

int Animal::getGestationPeriod() const
{
    return gestationPeriod;
}

void Animal::setGestationPeriod(int value)
{
    gestationPeriod = value;
}

QJsonDocument Animal::toJson() {
    QJsonObject animalObject;
    animalObject.insert("isFemale", getIsFemale());
    animalObject.insert("FoodType", getFoodType());
    animalObject.insert("amountOfFoodPerDay", getAmountOfFoodPerDay());
    animalObject.insert("daysBeforeBeingHungry", getDaysBeforeBeingHungry());
    animalObject.insert("litter", getLitter());
    animalObject.insert("sexualMaturity", getSexualMaturity());
    animalObject.insert("gestationPeriod", getGestationPeriod());
    animalObject.insert("endOfBreeding", getEndOfBreeding());
    animalObject.insert("childMortality", getChildMortality());
    animalObject.insert("lifeExpectancy", getLifeExpectancy());
    animalObject.insert("buyPrice", getBuyPrice());
    animalObject.insert("sellPrice", getSellPrice());
    animalObject.insert("type", getType());

    QJsonDocument doc(animalObject);
    //qDebug() << doc.toJson();
    return doc;
}

Animal::Animal(Animals* parent)
    : ZooObject("Un animal de l'habitat")
    , parent(parent)
{
}

Animal::Animal()
    : ZooObject("Un animal de l'habitat")
    , parent(nullptr)
{

}

Habitat* Animal::getHabitat() {
    return getParent()->getParent();
    // Animals -> Habitat
}
