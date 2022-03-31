#include "application.h"
#include"vendeur.h"
#include"responsable.h"
 int application::recherche(int refer )
{

   for(int i=0;i<tab.size();i++)
    {
    if(tab[i].get_ref()==refer)
    {
        return i;
    }
    }
    return -1;
}


bool application::ajouter(responsable R)
{
if(recherche(R.get_ref())==-1)
{
    tab.push_back(R);
    return true;

}
return false;
}

void application::afficher()
{
    cout<<nom<<endl;
    cout<<prenom<<endl;
    cout<<refer<<endl;
    cout<<salair<<endl;
    cout<<nb_equipe<<endl;
    cout<<prime<<endl;
}
void application::calculerSalair()
{
     salair=nb_equipe*prime;
    cout<<"le salair est:"<<salair<<endl;
}
void application::supprimer(int refer)
{int ind=recherche(refer);
    if(nb_equipe==0)
    {
         tab.erase(tab.begin()+ind);
         return true;
    }
    else return false;
}
