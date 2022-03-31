#include "responsable.h"

responsable::responsable()
{
    nb_equipe=0;
    prime=0;
}

responsable::responsable(int r,string n,string pren,float s,int nb,float pr):vendeur(r,n,pren,s)
{
nb_equipe=nb;
prime=pr;
}
