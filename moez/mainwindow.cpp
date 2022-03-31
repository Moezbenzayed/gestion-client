#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"client.h"
#include <QMessageBox>
#include <QSqlTableModel>
#include <QString>
#include <QDebug>
#include <QSqlRecord>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->id->setValidator(new QIntValidator(0,9999999,this));
    ui->tel->setValidator(new QIntValidator(0,9999999,this));
ui->tab_client->setModel(C.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_clicked()
{
    QMessageBox msgBox;
   int id_client=ui->id->text().toInt();
   QString nom=ui->nom_2->text();
   QString prenom=ui->prenom->text();
   int num_tel=ui->tel->text().toInt();
   QString email=ui->email->text();
   QString adresse=ui->adresse->text();

   client C(id_client,nom,prenom,num_tel,email,adresse);
bool test=C.ajouter(id_client,nom,prenom,num_tel,email,adresse);

   if(test){

     msgBox.setText("Ajout avec Succes");
    ui->tab_client->setModel(C.afficher());
    ui->id->text().clear();
 ui->nom_2->text().clear();
    ui->prenom->text().clear();
   ui->tel->text().clear();
   ui->email->text().clear();
  ui->adresse->text().clear();
   }
       else
           msgBox.setText("Echec de l'ajout");
  msgBox.exec();
}


void MainWindow::on_modifier_clicked()
{
    QMessageBox msgBox;
   int id_client=ui->id->text().toInt();
   QString nom=ui->nom_2->text();
   QString prenom=ui->prenom->text();
   int num_tel=ui->tel->text().toInt();
   QString email=ui->email->text();
   QString adresse=ui->adresse->text();

bool test;
test=C.modifier(id_client,nom,prenom,num_tel,email,adresse);


       if(test){
           ui->tab_client->setModel(C.afficher());


           msgBox.setText("modification avec Succes");
        }
           else
               msgBox.setText("Echec de la modification");
      msgBox.exec();
}


void MainWindow::on_supprimer_clicked()
{

    bool test;
      client C;
   C.setID(ui->id_supp->text().toInt());
     test=C.supprimer(C.getID());
     QMessageBox msgBox;
     if(test){

         ui->tab_client->setModel(C.afficher());

         QMessageBox::information(nullptr, QObject::tr("CLient supprimer"),
                                  QObject::tr("CLient supprimer\n"
                                              "Click Ok to exit."), QMessageBox::Ok);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("CLient supprimer"),
                               QObject::tr("Erreur !.\n"
                                           "Click Ok to exit."), QMessageBox::Ok);


}

void MainWindow::on_rechercher_textChanged(const QString &arg1)
{
   client C;
   ui->tab_client->setModel(C.rechercher(ui->rechercher->text()));
}

void MainWindow::on_tri_currentIndexChanged(int index)
{
    if(index==1)
                      ui->tab_client->setModel(C.tri_idP());
            else if(index==2)
                      ui->tab_client->setModel(C.tri_place());
            else if(index==3)
                      ui->tab_client->setModel(C.tri_nomP());
}
