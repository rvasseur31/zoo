#include "habitatpoule.h"

HabitatPoule::HabitatPoule(Habitats *parent)
    : Habitat(parent)  {
    setBuyPrice(300.0);
    setSellPrice(50.0);
    setCapacity(10);
    setRelatedLossOvercrowding(4);
    setHabitatType(AnimalTypeEnum::POULE);
}
