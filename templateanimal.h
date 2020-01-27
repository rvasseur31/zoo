#ifndef TEMPLATEANIMAL_H
#define TEMPLATEANIMAL_H

#include "animal.h"
#include "vendor.h"



template <class T>
class TemplateAnimal : public Animal {
  public:
    static Animal* Create(){
        Animal* animal = new T(nullptr);
        animal->setParent(nullptr);
        return animal;
    }
};


#endif // TEMPLATEANIMAL_H
