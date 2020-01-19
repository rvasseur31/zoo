#include "animaltype.h"

AnimalType *AnimalType::animalTypeInstance = nullptr;

AnimalType *AnimalType::getInstance() {
    if(animalTypeInstance == nullptr) {
        animalTypeInstance = new AnimalType();
    }
    return animalTypeInstance;
}

QString AnimalType::getStringFromAnimalTypeEnum(AnimalTypeEnum animalType) {
    return mapAnimalTypeEnumToString[animalType];
}

AnimalTypeEnum AnimalType::getAnimalTypeEnumFromString(QString animalType){
    return mapStringToAnimalTypeEnum[animalType];
}

QString AnimalType::getStringFromAnimalTypeEnumForHabitatName(AnimalTypeEnum animalType) {
    switch (animalType) {
    case AnimalTypeEnum::AIGLE:
        return "Habitat d'aigle";
    case AnimalTypeEnum::POULE:
        return "Habitat de poule";
    case AnimalTypeEnum::TIGRE:
        return "Habitat de tigre";
    }
    return "Habitat non définie";
}

QStringList AnimalType::getAnimalTypeToStringList() {
    QStringList listToReturn;
    QMapIterator<AnimalTypeEnum, QString> i(mapAnimalTypeEnumToString);
    while (i.hasNext()) {
        i.next();
        listToReturn.append(i.value());
    }
    return listToReturn;
}

AnimalType::AnimalType() {
    mapAnimalTypeEnumToString[AnimalTypeEnum::AIGLE] = "AIGLE";
    mapAnimalTypeEnumToString[AnimalTypeEnum::POULE] = "POULE";
    mapAnimalTypeEnumToString[AnimalTypeEnum::TIGRE] = "TIGRE";

    QMapIterator<AnimalTypeEnum, QString> i(mapAnimalTypeEnumToString);
    while (i.hasNext()) {
        i.next();
        mapStringToAnimalTypeEnum[i.value()] = i.key();
    }

}
