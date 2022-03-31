#include "client.h"
#include <QtDebug>
#include <QString>
#include <QSqlQuery>
#include<QObject>
#include<QSqlQueryModel>
#include<QTableView>
#include <QFloat16>
#include<QtWidgets>
#include<QtDesigner/QDesignerActionEditorInterface>
#include<mainwindow.h>
client::client()
{
 id_client=0;
 nom="";
 prenom="";
 num_tel=0;
 email="";
 adresse="";



}
client::client(int id_client,QString nom,QString prenom,int num_tel,QString email ,QString adresse)
{
    this->id_client=id_client;
    this->nom=nom;
    this->prenom=prenom;
    this->num_tel=num_tel;
    this->email=email;
    this->adresse=adresse;

}

int client::getID(){return id_client;}
QString client::getNom(){return nom;}
QString client::getPrenom(){return prenom;}
int client::getnum_tel(){return num_tel;}
QString client::getEmail(){return email;}
QString client::getadresse(){return adresse;}

void client::setID(int id_client){this->id_client=id_client;}
void client::setNom(QString nom){this->nom=nom;}
void client::setPrenom(QString prenom){this->prenom=prenom;}
void client::setnum_tel(int num_tel){this->num_tel=num_tel;}
void client::setEmail(QString email){this->email=email;}
void client::setadresse(QString adresse){this->adresse=adresse;}


bool client::ajouter(int id_client,QString nom,QString prenom,int num_tel,QString email ,QString adresse)
{

    QSqlQuery query;
       QString res = QString::number(id_client);

    query.prepare("INSERT INTO client(id_client,nom,prenom,num_tel,email,adresse) "
                  "VALUES (:id_client,:nom,:prenom,:num_tel,:email,:adresse)");
    query.bindValue(":id_client",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":num_tel",num_tel);
    query.bindValue(":email",email);
    query.bindValue(":adresse",adresse);
    return query.exec();

}
QSqlQueryModel* client::afficher()
{

QSqlQueryModel* model=new QSqlQueryModel();
model->setQuery("SELECT* FROM client");
model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("numero"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("email"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("Adresse"));
return model;
}
bool client::modifier(int id_client,QString nom,QString prenom,int num_tel,QString email ,QString adresse)
{
 QSqlQuery query;
    QString res= QString::number(id_client);

    query.prepare("UPDATE client SET nom=:nom,prenom=:prenom,num_tel=:num_tel,email=:email,adresse=:adresse WHERE id_client=:id_client");
    query.bindValue(":id_client",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":num_tel",num_tel);
    query.bindValue(":email",email);
    query.bindValue(":adresse",adresse);
    return    query.exec();

}
bool client::supprimer(int id_client)
{ QSqlQuery query;

    query.prepare("DELETE FROM client WHERE id_client=:id_client");
    query.bindValue(":id_client",id_client);

    return query.exec();
}



QSqlQueryModel * client::rechercher(QString search)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString qry="select * from client where id_client like '%"+search+"%' or nom like '%"+search+"%' or adresse like '%"+search+"%'";

    model->setQuery(qry);
    return model;
}




QSqlQueryModel *client::tri_idP()
 {
     QSqlQueryModel * model=new QSqlQueryModel();

     model->setQuery("select * from  client ORDER BY id_client ");

     model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
     model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom "));
     model->setHeaderData(2, Qt::Horizontal,QObject::tr("Prenom"));
     model->setHeaderData(3, Qt::Horizontal,QObject::tr("numero"));
     model->setHeaderData(4, Qt::Horizontal,QObject::tr("email"));
     model->setHeaderData(5, Qt::Horizontal,QObject::tr("Adresse"));
return model;
 }

 QSqlQueryModel *client::tri_place()
 {
     QSqlQueryModel * model=new QSqlQueryModel();

     model->setQuery("select * from  client ORDER BY adresse ");

     model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
     model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom "));
     model->setHeaderData(2, Qt::Horizontal,QObject::tr("Prenom"));
     model->setHeaderData(3, Qt::Horizontal,QObject::tr("numero"));
     model->setHeaderData(4, Qt::Horizontal,QObject::tr("email"));
     model->setHeaderData(5, Qt::Horizontal,QObject::tr("Adresse"));
return model;
 }

 QSqlQueryModel *client::tri_nomP()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("select * from  client ORDER BY nom ");

     model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
     model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom "));
     model->setHeaderData(2, Qt::Horizontal,QObject::tr("Prenom"));
     model->setHeaderData(3, Qt::Horizontal,QObject::tr("numero"));
     model->setHeaderData(4, Qt::Horizontal,QObject::tr("email"));
     model->setHeaderData(5, Qt::Horizontal,QObject::tr("Adresse"));

return model;
 }
