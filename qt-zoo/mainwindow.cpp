#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "zoo.h"
#include <QDebug>
#include <QMessageBox>
#include <QStringListModel>
#include <QVector>

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
    //zoo->testMe();
    updateBudgetDisplay();
}

MainWindow::~MainWindow()
{
    delete ui;
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
    // https://useaxentix.com
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

void MainWindow::updateBudgetDisplay()
{
    ui->lbl_budget->setText(QString::number(Zoo::getInstance()->getMoney()));
}

void MainWindow::updateDisplay()
{
    updateBudgetDisplay();
    updateMessageDisplay();
}

void MainWindow::updateMessageDisplay()
{
    QStringListModel *model;
    model = new QStringListModel(this);
    QStringList List;
    for (int i = 0; i < Zoo::getInstance()->getMessages()->getMessages().length(); i++) {
        List.append(QString("Error level ")
                    .append(Zoo::getInstance()->getMessages()->getMessages().at(i)->getErrorLevel())
                    .append(" From : "+Zoo::getInstance()->getMessages()->getMessages().at(i)->getEmittorName()
                            +" Message : "+Zoo::getInstance()->getMessages()->getMessages().at(i)->getMessage()));
    }
    model->setStringList(List);
    ui->listView_messages->setModel(model);


    //ui->textEdit_messages->append(Zoo::getInstance()->getMessages()->getLastUnreadMessageAsHtml());




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
//    if(Zoo::getInstance()->getMoney()>=30)
//    {
        Zoo *zoo = Zoo::getInstance();
        zoo->removeMoney(30);
        updateDisplay();
//    }
//    else
//    {
//        QMessageBox::warning(
//            this,
//            tr("Erreur"),
//            tr("Pas assez d'argent") );
//    }
}



void MainWindow::on_pushButton_buyHabitat_clicked()
{
    bool res = Zoo::getInstance()->buyHabitat();
}

void MainWindow::on_pushButton_showMessages_clicked()
{
    if (showMessages){
        ui->listView_messages->hide();
        ui->lbl_messages->hide();
    } else {
        ui->listView_messages->show();
        ui->lbl_messages->show();
    }
}
