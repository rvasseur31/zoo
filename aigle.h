#ifndef AIGLE_H
#define AIGLE_H

#include "animal.h"
#include "templateanimal.h"

class Aigle : public TemplateAnimal<Aigle> {


public:
    Aigle();
};

#endif // AIGLE_H
