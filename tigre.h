#ifndef TIGRE_H
#define TIGRE_H

#include "animal.h"
#include "templateanimal.h"

class Tigre : public TemplateAnimal<Tigre> {
public:
    Tigre();
};

#endif // TIGRE_H
