#ifndef ANIMALS_H
#define ANIMALS_H

#include "zooobject.h"
#include "animaltype.h"
#include "poule.h"
#include "tigre.h"
#include "aigle.h"
#include "animal.h"
#include "zoo.h"

#include <QVector>

class Animal;
class Habitat;

class Animals : public ZooObject
{
    Habitat *parent = nullptr;
    QVector<Animal*> animalList;
public:
    Animals(Habitat* parent);

    Habitat *getParent() const;
    void setParent(Habitat *value);
    QVector<Animal *> getAnimalList() const;
    bool buyAnimal(AnimalTypeEnum animalType);
    bool sellAnimal(Animal *animal);
    bool killAnimal(Animal *animal);
};

#endif // ANIMALS_H
