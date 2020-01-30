#include "aigle.h"
#include "FoodType.h"
#include "animals.h"
#include "animal.h"

Aigle::Aigle() {
    setBuyPrice(4000.0);
    setSellPrice(2000.0);
    setFoodType(FoodType::MEAT);
    setAmountOfFoodPerDay(0.25);
    setDaysBeforeBeingHungry(10);
    setSexualMaturity(12*4);
    setEndOfBreeding(14);
    setLifeExpectancy(25);
}
