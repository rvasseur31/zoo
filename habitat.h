#ifndef HABITAT_H
#define HABITAT_H

#include "zooobject.h"
#include "AnimalType.h"

#include <QVector>

class Animals;
class Habitats;

class Habitat : public ZooObject {
    AnimalType habitatType;
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
    AnimalType getHabitatType() const;
    void setHabitatType(const AnimalType &value);
    Habitats *getParent() const;
    void setParent(Habitats *value);
    Animals *getAnimals() const;
    void setAnimals(Animals *value);

    bool isFull();

    QString getHabitatTypeToString();
    int getAnimalNumber();
};

#endif // HABITAT_H
