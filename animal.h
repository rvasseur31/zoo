#ifndef ANIMAL_H
#define ANIMAL_H

#include "zooobject.h"
#include "FoodType.h"

class Animals;
class Habitat;

class Animal : public ZooObject
{
    bool isFemale;
    FoodType foodType;
    double amountOfFoodPerDay;
    int DaysBeforeBeingHungry;
    int litter;
    int sexualMaturity;
    int endOfBreeding;
    int childMortality;
    int lifeExpectancy;
    double buyPrice;
    double sellPrice;

    Animals* parent = nullptr;

public:
    Animal(Animals* parent);

    Animals *getParent() const;
    void setParent(Animals *value);

    Habitat* getHabitat();
    bool getIsFemale() const;
    void setIsFemale(bool value);
    FoodType getFoodType() const;
    void setFoodType(const FoodType &value);
    double getAmountOfFoodPerDay() const;
    void setAmountOfFoodPerDay(double value);
    int getDaysBeforeBeingHungry() const;
    void setDaysBeforeBeingHungry(int value);
    int getLitter() const;
    void setLitter(int value);
    int getSexualMaturity() const;
    void setSexualMaturity(int value);
    int getEndOfBreeding() const;
    void setEndOfBreeding(int value);
    int getChildMortality() const;
    void setChildMortality(int value);
    int getLifeExpectancy() const;
    void setLifeExpectancy(int value);
    double getBuyPrice() const;
    void setBuyPrice(double value);
    double getSellPrice() const;
    void setSellPrice(double value);
};

#endif // ANIMAL_H
