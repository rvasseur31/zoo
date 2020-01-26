#include "showanimalsinhabitat.h"
#include "ui_showanimalsinhabitat.h"
#include <QDebug>

ShowAnimalsInHabitat::ShowAnimalsInHabitat(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::ShowAnimalsInHabitat)
{
    ui->setupUi(this);
    qDebug() << Zoo::getInstance()
            ->getHabitats()
            ->getHabitatList().at(parent->getCurrentHabitatSelected())
            ->getCapacity();
}

ShowAnimalsInHabitat::~ShowAnimalsInHabitat()
{
    delete ui;
}
