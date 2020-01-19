#include "habitattigre.h"

HabitatTigre::HabitatTigre(Habitats *parent)
    : Habitat(parent)  {
    setBuyPrice(2000.0);
    setSellPrice(500.0);
    setCapacity(2);
    setRelatedLossOvercrowding(1);
    setHabitatType(AnimalTypeEnum::TIGRE);
}
