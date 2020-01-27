#include "animals.h"

Habitat *Animals::getParent() const
{
    return parent;
}

void Animals::setParent(Habitat *value)
{
    parent = value;
}

QVector<Animal *> Animals::getAnimalList() const
{
    return animalList;
}

Animals::Animals(Habitat* parent)
    : ZooObject("Ma liste d'animaux d'un habitat")
    , parent(parent)
{}

bool Animals::buyAnimal(AnimalTypeEnum animalType) {
    Animal *animal = nullptr;
    animal = Vendor::getInstance()
            ->sellAnimal(AnimalType::getInstance()->getStringFromAnimalTypeEnum(animalType));
    animal->setParent(this);
    if (Zoo::getInstance()->removeMoney(animal->getBuyPrice())){
        animalList.push_back(animal);
        return true;
    }
    return false;
}

bool Animals::sellAnimal(Animal *animal) {
    if (killAnimal(animal)){
        return Zoo::getInstance()->removeMoney(animal->getSellPrice());
    }
    return false;
}

bool Animals::killAnimal(Animal *animal) {
    for(int i = 0; i < getAnimalList().size(); i++){
        if (getAnimalList().at(i) == animal) {
            delete getAnimalList().at(i);
        }
    }
    return false;
}
