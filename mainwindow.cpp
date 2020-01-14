#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "zoo.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Zoo *zoo = Zoo::getInstance("ZooTycoon");
    zoo->addMoney(4000.0);
    ui->lbl_zooName->setText(zoo->getName());
    setEditMode(false);

    ui->lineEdit_zooName->move(ui->lbl_zooName->pos());
    ui->btn_validateZooName->move(ui->btn_updateZooName->pos());
    updateDisplay();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete Zoo::getInstance();
}


void MainWindow::on_btn_updateZooName_clicked()
{
    setEditMode(true);
}

void MainWindow::on_lineEdit_zooName_returnPressed()
{
    setEditMode(false);
}

void MainWindow::setEditMode(bool editMode)
{
    QLineEdit *zooName = ui->lineEdit_zooName;

    ui->lbl_zooName->hide();
    zooName->hide();
    ui->btn_updateZooName->hide();
    ui->btn_validateZooName->hide();
    if(editMode){
        zooName->show();
        ui->btn_validateZooName->show();
        zooName->setFocus();
        zooName->setText(ui->lbl_zooName->text());
    } else {
        ui->lbl_zooName->show();
        ui->btn_updateZooName->show();

        if(zooName->text() != ""){
            Zoo::getInstance()->setName(zooName->text());
            ui->lbl_zooName->setText(Zoo::getInstance()->getName());
        }
    }

    qDebug() << Q_FUNC_INFO << Zoo::getInstance()->getName();
}

void MainWindow::updateDisplay(){
    updateStockDisplay();
    updateBudgetDisplay();
    updateMessageDisplay();
    updateHabitatDisplay();
}

void MainWindow::updateBudgetDisplay()
{
    ui->lbl_budget->setText(QString::number(Zoo::getInstance()->getMoney()));
}

QStringListModel* MainWindow::getLogsForListView() {
    QStringListModel *model = new QStringListModel();
    QStringList list;
    for (int index = Zoo::getInstance()->getLog()->getMessages().size()-1; index >= 0; --index) {
        list.append(Zoo::getInstance()->getLog()->getMessages().at(index)->getMessage());
    }
    model->setStringList(list);
    return model;
}

void MainWindow::updateMessageDisplay(){
    if (Zoo::getInstance()->getLog()->getMessages().size() != 0){
        ui->listViewLogs->setModel(getLogsForListView());
        switch (Zoo::getInstance()->getLog()->getMessages().last()->getErrorLevel()) {
            case ZooErrorLevel::ERROR:
                QMessageBox::information(this, "", Zoo::getInstance()->getLog()->getMessages().last()->getMessage());
                break;
            case ZooErrorLevel::WARNING:
                //QMessageBox::information(this, "", "Bonjour et bienvenue à<strong>tous les Zéros !</strong>");
                break;
            case ZooErrorLevel::INFO:
                //QMessageBox::information(this, "", "Bonjour et bienvenue à<strong>tous les Zéros !</strong>");
                break;
            case ZooErrorLevel::VERBOSE:
                //QMessageBox::information(this, "", "Bonjour et bienvenue à<strong>tous les Zéros !</strong>");
                break;
            case ZooErrorLevel::DEBUG:
                //QMessageBox::information(this, "", "Bonjour et bienvenue à<strong>tous les Zéros !</strong>");
                break;
        }
    }
}

void MainWindow::getHabitatsForListView() {

}

void MainWindow::updateHabitatDisplay(){
    int numberOfHabitat = Zoo::getInstance()->getHabitats()->getHabitatList().size();
    ui->tableViewHabitat->setRowCount(numberOfHabitat);
    ui->tableViewHabitat->setColumnCount(4);
    QStringList m_TableHeader;
    m_TableHeader<<"Type d'habitat"<<"Nom"<<"Capacité total"<<"Nombre d'animaux";
    ui->tableViewHabitat->setHorizontalHeaderLabels(m_TableHeader);
    for (int row = 0; row < numberOfHabitat; ++row) {
        ui->tableViewHabitat->setItem(row, 0, new QTableWidgetItem(Zoo::getInstance()->getHabitats()->getHabitatList().at(row)->getHabitatTypeToString()));
        ui->tableViewHabitat->setItem(row, 1, new QTableWidgetItem(Zoo::getInstance()->getHabitats()->getHabitatList().at(row)->getName()));
        ui->tableViewHabitat->setItem(row, 2, new QTableWidgetItem(QString::number(Zoo::getInstance()->getHabitats()->getHabitatList().at(row)->getCapacity())));
        ui->tableViewHabitat->setItem(row, 3, new QTableWidgetItem(QString::number(Zoo::getInstance()->getHabitats()->getHabitatList().at(row)->getAnimalNumber())));
    }
}

void MainWindow::updateStockDisplay()
{
    ui->labelQuantityStockMeat->setText(QString::number(Zoo::getInstance()->getStockList()["meat"]->getQuantity()));
    ui->labelQuantityStockSeed->setText(QString::number(Zoo::getInstance()->getStockList()["seed"]->getQuantity()));
}
void MainWindow::on_btn_validateZooName_clicked()
{
    setEditMode(false);
}

void MainWindow::on_btn_earn_clicked()
{
    Zoo *zoo = Zoo::getInstance();
    zoo->addMoney(50);
    updateDisplay();
}

void MainWindow::on_btn_spend_clicked()
{
    Zoo *zoo = Zoo::getInstance();
    zoo->removeMoney(30);
    updateDisplay();
}

void MainWindow::on_pushButtonAddMeat_clicked()
{
 Zoo *zoo = Zoo::getInstance();
 zoo->getStockList()["meat"]->addQuantity(50);
 updateDisplay();
}

void MainWindow::on_pushButtonRemoveMeat_clicked()
{
    Zoo *zoo = Zoo::getInstance();
    zoo->getStockList()["meat"]->removeQuantity(30);
    updateDisplay();

}

void MainWindow::on_pushButtonAddSeed_clicked()
{
    Zoo *zoo = Zoo::getInstance();
    zoo->getStockList()["seed"]->addQuantity(50);
    updateDisplay();
}

void MainWindow::on_pushButtonRemoveSeed_clicked()
{
    Zoo *zoo = Zoo::getInstance();
    zoo->getStockList()["seed"]->removeQuantity(30);
    updateDisplay();
}

void MainWindow::on_pushButtonAddHabitat_clicked() {
    Zoo::getInstance()->buyHabitat(AnimalType::AIGLE);
    updateDisplay();
}

void MainWindow::on_pushButtonSellHabitat_clicked()
{
    Zoo *zoo = Zoo::getInstance();
    Habitat *habitat = zoo->getHabitats()->getHabitatList().at(0);
    Zoo::getInstance()->sellHabitat(habitat);
    updateDisplay();
}

void MainWindow::on_pushButtonDestroyHabitat_clicked()
{
    Zoo *zoo = Zoo::getInstance();
    Habitat *habitat = zoo->getHabitats()->getHabitatList().at(0);
    Zoo::getInstance()->destroyHabitat(habitat);
    updateDisplay();
}
