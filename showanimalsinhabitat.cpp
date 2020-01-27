#include "showanimalsinhabitat.h"
#include "ui_showanimalsinhabitat.h"


void ShowAnimalsInHabitat::signalSetHabitatSelected(int habitatSelected) {
    this->habitatSelected = Zoo::getInstance()
                        ->getHabitats()
                        ->getHabitatList().at(habitatSelected);
    qDebug() << __FUNCTION__ << this->habitatSelected->getCapacity();
}

ShowAnimalsInHabitat::ShowAnimalsInHabitat(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::ShowAnimalsInHabitat)
{
    ui->setupUi(this);
}

ShowAnimalsInHabitat::~ShowAnimalsInHabitat()
{
    delete ui;
}
