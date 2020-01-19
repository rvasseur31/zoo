#ifndef HABITAT_H
#define HABITAT_H

#include "zooobject.h"
#include "animaltype.h"

#include <QVector>

class Animals;
class Habitats;

class Habitat : public ZooObject {
    AnimalTypeEnum habitatType;
    double buyPrice;
    double sellPrice;
    int capacity;
    int relatedLossOvercrowding;

    Animals* animals;
    Habitats* parent = nullptr;
public:
    Habitat(Habitats *parent);

    double getBuyPrice() const;
    void setBuyPrice(double value);
    double getSellPrice() const;
    void setSellPrice(double value);
    int getCapacity() const;
    void setCapacity(int value);
    int getRelatedLossOvercrowding() const;
    void setRelatedLossOvercrowding(int value);
    AnimalTypeEnum getHabitatType() const;
    void setHabitatType(const AnimalTypeEnum &value);
    Habitats *getParent() const;
    void setParent(Habitats *value);
    Animals *getAnimals() const;
    void setAnimals(Animals *value);

    bool isFull();


    AnimalTypeEnum stringToAnimalType();
    int getAnimalNumber();
    ~Habitat();
};

#endif // HABITAT_H
