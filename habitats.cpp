#include "habitats.h"

#include <QDebug>



Habitats *Habitats::instanceHabitats = nullptr;

qVectorHabitatPtr& Habitats::getHabitatList()
{
    return habitatList;
}

Habitats::Habitats() : ZooObject("Ma liste d'habitats"){

}

Habitats *Habitats::getInstance() {
    if(instanceHabitats == nullptr) {
        instanceHabitats = new Habitats();
    }
    return instanceHabitats;
}

Habitats::~Habitats() {
    qDebug() << Q_FUNC_INFO << getName();
    for(int i = 0; i < getHabitatList().size(); i++){
        qDebug() << Q_FUNC_INFO << getHabitatList().at(i)->getName();
        delete getHabitatList().at(i);
    }
}

qVectorHabitatPtr Habitats::getHabitatListByHabitatType(AnimalTypeEnum animalType) const{
    QVector<Habitat *> habitatListToReturn;
    for(int i = 0; i < habitatList.length(); i++){
        if (habitatList.at(i)->getHabitatType() == animalType){
            habitatListToReturn.push_back(habitatList.at(i));
        }
    }
    return habitatListToReturn;
}

bool Habitats::buyHabitat(AnimalTypeEnum animalType){
    Habitat *habitat = nullptr;
    if (animalType == AnimalTypeEnum::AIGLE){
        habitat = new HabitatAigle(this);
    }
    else if (animalType == AnimalTypeEnum::POULE){
        habitat = new HabitatPoule(this);
    }
    else{
        habitat = new HabitatTigre(this);
    }
    if (Zoo::getInstance()->removeMoney(habitat->getBuyPrice())){
        habitatList.push_back(habitat);
        return true;
    }
    return false;
}

bool Habitats::removeHabitat(Habitat* habitat) {
    for(int i = 0; i < getHabitatList().size(); i++){
        Habitat* current = getHabitatList().at(i);
        if (current == habitat) {
            getHabitatList().erase(getHabitatList().begin() + i);
            return true;
        }
    }
    return false;
}

bool Habitats::sellHabitat(Habitat* habitat){
    if (removeHabitat(habitat)){
        Zoo::getInstance()->getLog()->addMessage(new ZooMessage(ZooErrorLevel::INFO, "Vous venez de vendre un habitat", this));
        Zoo::getInstance()->addMoney(habitat->getSellPrice());
        return true;
    }
    return false;
}

bool Habitats::destroyHabitat(Habitat* habitat){
    if (removeHabitat(habitat)){
        Zoo::getInstance()->getLog()->addMessage(new ZooMessage(ZooErrorLevel::INFO, "Vous venez de détruire un habitat", this));
        return true;
    }
    return false;
}
