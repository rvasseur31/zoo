#ifndef SHOWANIMALSINHABITAT_H
#define SHOWANIMALSINHABITAT_H


#include "mainwindow.h"
#include "zoo.h"

#include <QDebug>
#include <QDialog>

namespace Ui {
class ShowAnimalsInHabitat;
}

class ShowAnimalsInHabitat : public QDialog
{
    Q_OBJECT
    Habitat *habitatSelected;

public slots:
    void signalSetHabitatSelected(int habitatSelected);
public:
    ShowAnimalsInHabitat(MainWindow *parent = nullptr);
    ~ShowAnimalsInHabitat();

    int getHabitatSelected() const;

private:
    Ui::ShowAnimalsInHabitat *ui;
};

#endif // SHOWANIMALSINHABITAT_H
