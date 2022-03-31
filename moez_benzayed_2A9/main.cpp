#include <iostream>
#include<string>
#include"vendeur.h"
#include"responsable.h"
#include<vector>

using namespace std;

int main()
{




responsable ET1(1234,"adam","aa","1990");
responsable ET2(1233,"anas","aa","1989",);
responsable ET3(1235,"ilyes","aa","1989");
responsable ET4(1243,"anasssss","aa","1989");

responsable R;
if (R.ajouter(ET1))
{
    cout<<"c bn"<< endl;
}
else
  {
     cout<<"existe" <<endl;
  }



cout <<"***  avec ET1 ***"<< endl;
cout <<endl;

R.afficher();
cout<<endl;

R.ajouter(ET2);
cout <<"***  avec ET2 ***"<< endl;
cout <<endl;

R.afficher();
cout<<endl;

R.ajouter(ET3);
cout <<"***avec ET3 ***"<< endl;
cout <<endl;

R.afficher();
cout<<endl;

if(R.recherche(ET1.get_ref())!=-1)
{
    cout<<"existe"<<endl;
}
else cout <<"nexiste pas"<<endl;

if(R.recherche(1236)!=-1)
{
    cout<<"existe"<<endl;
}
else cout <<"nexiste pas"<<endl;

cout <<endl;
R.supprimer(ET3.get_ref());
cout<<"***apres supp ET3***"<<endl;
cout<<endl;

R.afficher();
cout<<endl;

cout<<"donner une classe"<<endl;
cin>>c;
R.ajouter(ET4);
R.afficher(R);

