#ifndef VENDEUR_H
#define VENDEUR_H
#include<application.h>

class vendeur
{
    public:
        vendeur();
vendeur(int,string,string,float);

    private:
        int refer;
        string nom;
        string prenom;
        float salair;
};

#endif // VENDEUR_H
