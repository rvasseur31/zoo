#ifndef TEMPLATEANIMAL_H
#define TEMPLATEANIMAL_H

#include "animal.h"



template <class T>
class TemplateAnimal : public Animal {
  public:
    static Animal* Create(Animals* parent){
        Animal* animal = new T;
        animal->setParent(parent);
        return animal;
    }
};


#endif // TEMPLATEANIMAL_H
