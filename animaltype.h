#ifndef ANIMALTYPE_H
#define ANIMALTYPE_H

#include <QMap>
#include <QDebug>

enum AnimalTypeEnum {
    AIGLE,
    POULE,
    TIGRE
};

class AnimalType {
    QMap<AnimalTypeEnum, QString> mapAnimalTypeEnumToString;
    QMap<QString, AnimalTypeEnum> mapStringToAnimalTypeEnum;

    static AnimalType *animalTypeInstance;
public:
    static AnimalType *getInstance();
    QString getStringFromAnimalTypeEnum(AnimalTypeEnum animalType);
    AnimalTypeEnum getAnimalTypeEnumFromString(QString animalType);
    QString getStringFromAnimalTypeEnumForHabitatName(AnimalTypeEnum animalType);
    QStringList getAnimalTypeToStringList();
private:
    AnimalType();
};

#endif // ANIMALTYPE_H
