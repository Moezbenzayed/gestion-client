#ifndef APPLICATION_H
#define APPLICATION_H
#include"vendeur.h"
#include"responsable.h"
#include<iostream>
#include<string>
using namespace std;
 vector<vendeur>tab;
class application
{
    public:
        application();
bool ajouter(responsable);
int recherche(refer );
void afficher();
void calculerSalair();
void supprimer(refer);
};

#endif // APPLICATION_H
