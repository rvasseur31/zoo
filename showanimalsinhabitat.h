#ifndef SHOWANIMALSINHABITAT_H
#define SHOWANIMALSINHABITAT_H

#include <QDialog>
#include "mainwindow.h"
#include "zoo.h"

namespace Ui {
class ShowAnimalsInHabitat;
}

class ShowAnimalsInHabitat : public QDialog
{
    Q_OBJECT
public:
    ShowAnimalsInHabitat(MainWindow *parent = nullptr);
    ~ShowAnimalsInHabitat();

private:
    Ui::ShowAnimalsInHabitat *ui;
};

#endif // SHOWANIMALSINHABITAT_H
