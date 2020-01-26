#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int currentHabitatSelected;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int getCurrentHabitatSelected() const;
    void setCurrentHabitatSelected(int value);

private slots:
    void on_btn_updateZooName_clicked();

    void on_lineEdit_zooName_returnPressed();

    void on_btn_validateZooName_clicked();

    void on_btn_earn_clicked();

    void on_btn_spend_clicked();

    void on_pushButtonAddMeat_clicked();

    void on_pushButtonRemoveMeat_clicked();

    void on_pushButtonAddSeed_clicked();

    void on_pushButtonRemoveSeed_clicked();

    void on_pushButtonAddHabitat_clicked();

    void on_pushButtonSellHabitat_clicked();

    void on_pushButtonDestroyHabitat_clicked();

    void on_tableViewHabitat_cellDoubleClicked(int row);

private:
    Ui::MainWindow *ui;
    void setEditMode(bool editMode);
    void updateBudgetDisplay();
    void updateStockDisplay();
    void updateDisplay();
    void updateMessageDisplay();
    QStringListModel *getLogsForListView();
    void getHabitatsForListView();
    void updateHabitatDisplay();
};
#endif // MAINWINDOW_H
