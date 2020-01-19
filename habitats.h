#ifndef HABITATS_H
#define HABITATS_H

#include "zooobject.h"
#include "habitat.h"
#include "animaltype.h"
#include "habitataigle.h"
#include "habitatpoule.h"
#include "habitattigre.h"
#include "zoo.h"

#include <QVector>
#include <QDebug>

#include <iostream>
#include <memory>

using namespace std;

class Habitat; 

typedef QVector<Habitat*> qVectorHabitatPtr;

class Habitats: ZooObject {
    static Habitats *instanceHabitats;
    qVectorHabitatPtr habitatList;
public:
    ~Habitats();
    qVectorHabitatPtr &getHabitatList();
    qVectorHabitatPtr getHabitatListByHabitatType(AnimalTypeEnum habitatType) const;
    bool buyHabitat(AnimalTypeEnum habitatType);
    bool sellHabitat(Habitat* habitat);
    bool destroyHabitat(Habitat* habitat);
    static Habitats *getInstance();
    bool removeHabitat(Habitat *habitat);
private:
    Habitats();
};

#endif // HABITATS_H
