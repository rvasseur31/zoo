#ifndef COQ_H
#define COQ_H


#include "animal.h"
#include "templateanimal.h"

class Coq : public TemplateAnimal<Coq> {
public:
    Coq();
};
#endif // COQ_H
