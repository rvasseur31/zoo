#ifndef HABITATS_H
#define HABITATS_H

#include "zooobject.h"
#include "habitat.h"
#include "AnimalType.h"
#include "habitataigle.h"
#include "habitatpoule.h"
#include "habitattigre.h"
#include "zoo.h"

#include <QVector>
#include <QDebug>

class Habitat;

class Habitats: ZooObject {
    static Habitats *instanceHabitats;
    QVector<Habitat *> habitatList;
public:
    ~Habitats();
    QVector<Habitat *> getHabitatList() const;
    QVector<Habitat *> getHabitatListByHabitatType(AnimalType habitatType) const;
    bool buyHabitat(AnimalType habitatType);
    bool sellHabitat(Habitat* habitat);
    bool destroyHabitat(Habitat* habitat);
    static Habitats *getInstance();
    bool removeHabitat(Habitat *habitat);
private:
    Habitats();
};

#endif // HABITATS_H
