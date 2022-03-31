#ifndef CLIENT_H
#define CLIENT_H

#include<QString>
#include<QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDebug>
#include <QTableView>
#include <QFloat16>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>

class client
{
public:
    client();
    client(int,QString,QString,int,QString,QString);
int getID();
QString getNom();
QString getPrenom();
int getnum_tel();
QString getEmail();
QString getadresse();

void setID(int);
void setNom(QString);
void setPrenom(QString);
void setnum_tel(int);
void setEmail(QString);
void setadresse(QString);

bool ajouter(int ,QString ,QString ,int ,QString,QString);
 QSqlQueryModel* afficher();
 bool modifier(int ,QString ,QString ,int ,QString ,QString );
bool supprimer(int);
QSqlQueryModel* rechercher(QString search);

QSqlQueryModel * tri_idP();
QSqlQueryModel * tri_place();
QSqlQueryModel * tri_nomP();
private:
    int id_client;
    QString nom;
    QString prenom;
   int num_tel;
   QString email;
  QString  adresse;
};

#endif // CLIENT_H
