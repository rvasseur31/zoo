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
    ui->lbl_zooName->setText(zoo->getName());
    setEditMode(false);

    ui->lineEdit_zooName->move(ui->lbl_zooName->pos());
    ui->btn_validateZooName->move(ui->btn_updateZooName->pos());
    zoo->testMe();
    updateBudgetDisplay();
    updateStockDisplay();
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
}

void MainWindow::updateBudgetDisplay()
{
    ui->lbl_budget->setText(QString::number(Zoo::getInstance()->getMoney()));
}

void MainWindow::updateMessageDisplay(){
    if (Zoo::getInstance()->getLog()->getMessages().size() != 0){
        ui->labelMessageLog->setText(Zoo::getInstance()->getLog()->getLastMessage());
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
 updateStockDisplay();
}

void MainWindow::on_pushButtonRemoveMeat_clicked()
{
    Zoo *zoo = Zoo::getInstance();
    zoo->getStockList()["meat"]->removeQuantity(30);
    updateStockDisplay();

}

void MainWindow::on_pushButtonAddSeed_clicked()
{
    Zoo *zoo = Zoo::getInstance();
    zoo->getStockList()["seed"]->addQuantity(50);
    updateStockDisplay();
}

void MainWindow::on_pushButtonRemoveSeed_clicked()
{
    Zoo *zoo = Zoo::getInstance();
    zoo->getStockList()["seed"]->removeQuantity(30);
    updateStockDisplay();
}
