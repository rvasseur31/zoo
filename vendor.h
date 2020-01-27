#ifndef VENDOR_H
#define VENDOR_H

#include "animal.h"

#include <QList>
#include <QString>
#include <QDebug>


typedef  Animal* (*CreateAnimalFn)();

// Cette macro permet de transformer un pointeur en QString afin de l'afficher
#define STR_PTR(ptr) QString("0x%1").arg(reinterpret_cast<quintptr>(ptr), QT_POINTER_SIZE * 2, 16, QChar('0'))


class Vendor
{
    QList<Animal *> animalList;
    QMap<QString, CreateAnimalFn> m_factoryMap;
    static Vendor *vendorInstance;

public:
    static Vendor *getInstance();
    ~Vendor();

    void Register(QString animalName, CreateAnimalFn fn);
    void create(int animalNumber, QString animalName, int animalPrice);

    Animal *sellAnimal(QString type);
    void regiveAnimal(Animal *animal);

//    operator QString() const {
//        QString ret;
//        ret += "ACTIONS MAP:\n";
//        foreach (auto key, m_factoryMap.keys()) {
//            ret += " > " + key + ": " + STR_PTR(m_factoryMap[key]);
//            ret += '\n';
//        }

//        ret += "ANIMAL LIST DU VENDEUR:\n";

//        foreach (Animal *animal, animalList) {
//            ret += " > " + animal->type() + ": " + animal->name();
//            ret += '\n';
//        }

//        return ret;
//    }
private:
    Vendor();

};

#endif // VENDOR_H
