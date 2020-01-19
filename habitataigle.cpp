#include "habitataigle.h"

HabitatAigle::HabitatAigle(Habitats *parent)
    : Habitat(parent)  {
    setBuyPrice(2000.0);
    setSellPrice(500.0);
    setCapacity(4);
    setRelatedLossOvercrowding(1);
    setHabitatType(AnimalTypeEnum::AIGLE);
}
