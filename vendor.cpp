#include "vendor.h"

Vendor *Vendor::vendorInstance = nullptr;

Vendor *Vendor::getInstance()
{
    if(vendorInstance == nullptr) {
        vendorInstance = new Vendor();
    }
    return vendorInstance;
}

Vendor::Vendor(){}

Vendor::~Vendor() {
    foreach (auto animal, animalList) { delete animal; }
}

void Vendor::Register(QString animalName, CreateAnimalFn fn)
{
    qDebug() << __FUNCTION__ << animalName <<  STR_PTR(fn);
    m_factoryMap[animalName] = fn;
}

void Vendor::create(int animalNumber, QString animalName, int animalPrice)
{
    qDebug() << __FUNCTION__ << animalNumber << animalName << animalPrice;

    // on recupere le pointeur sur fonction de la Map
    CreateAnimalFn fn = m_factoryMap[animalName];
    if (fn == nullptr) {
        qDebug() <<"Unable to create " + animalName;
        return;
    }

    for(int i = 0; i < animalNumber; i++){
        // on appel la fonction désignée par le pointeur 'fn'
        Animal *animal = fn();
        animal->setType(animalName);
        animal->setName(QString(animalName + " #%1").arg(animalList.size()));
        animal->setBuyPrice(animalPrice);

        // on le rajoute à la liste des objets de la Factory
        animalList.append(animal);
    }
}

Animal *Vendor::sellAnimal(QString type) {
    qDebug() << __FUNCTION__ << type;
    for(int i = 0; i<animalList.size(); i++){
        if(animalList.at(i)->getType() == type){
            Animal *animalToReturn = animalList.at(i);
            animalList.removeAt(i);

            return animalToReturn;
        }
    }
    return nullptr;
}

void Vendor::regiveAnimal(Animal * animal){
    animalList.append(animal);
}

