#ifndef POULE_H
#define POULE_H

#include "animal.h"
#include "templateanimal.h"

class Poule : public TemplateAnimal<Poule> {
public:
    Poule();
};

#endif // POULE_H
