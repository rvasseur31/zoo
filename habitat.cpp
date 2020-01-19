#include "habitat.h"
#include "animals.h"

Habitat::~Habitat(){
    qDebug() << __FUNCTION__;

}

Habitats *Habitat::getParent() const
{
    return parent;
}

void Habitat::setParent(Habitats *value)
{
    parent = value;
}

AnimalTypeEnum Habitat::getHabitatType() const
{
    return habitatType;
}

AnimalTypeEnum Habitat::stringToAnimalType()
{
    return AnimalTypeEnum::AIGLE;
}

void Habitat::setHabitatType(const AnimalTypeEnum &value)
{
    habitatType = value;
}

Animals *Habitat::getAnimals() const
{
    return animals;
}

void Habitat::setAnimals(Animals *value)
{
    animals = value;
}

double Habitat::getBuyPrice() const
{
    return buyPrice;
}

void Habitat::setBuyPrice(double value)
{
    buyPrice = value;
}

double Habitat::getSellPrice() const
{
    return sellPrice;
}

void Habitat::setSellPrice(double value)
{
    sellPrice = value;
}

int Habitat::getCapacity() const
{
    return capacity;
}

void Habitat::setCapacity(int value)
{
    capacity = value;
}

int Habitat::getRelatedLossOvercrowding() const
{
    return relatedLossOvercrowding;
}

void Habitat::setRelatedLossOvercrowding(int value)
{
    relatedLossOvercrowding = value;
}

Habitat::Habitat(Habitats *parent) : ZooObject("Un habitat")
    , animals(new Animals(this))
    , parent(parent)
{

}

int Habitat::getAnimalNumber() {
    return animals->getAnimalList().size();
}

/*bool Habitat::isFull(){
    if (getCapacite() >= animalList->) {
        return true;
    }
    return false;
}*/
