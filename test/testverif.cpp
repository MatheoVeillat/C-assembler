#include<iostream>
#include<string>
#include <math.h>

using namespace std;

void verificateur(std::string & stringNombre, int intNombre){
	char choix;
	int compteur = 0, nombreActuelle = 0;
	cout<<"Taper votre nombre"<<endl;
	getline(std::cin,stringNombre);
	for(int i = 0; compteur != stringNombre.length();i++){
		choix = stringNombre[i];
		if(choix != '1' && choix != '2' && choix != '3' && choix != '4' && choix != '5' && choix != '6' && choix != '7' && choix != '8' && choix != '9' && choix != '0'){
			cout<<"Erreur taper votre nouveau nombre"<<endl;
			getline(std::cin,stringNombre);
			i = - 1, compteur = 0, intNombre = 0;
		}
		else {
			nombreActuelle = int(stringNombre[i]) - 48;
			intNombre = intNombre * 10 + nombreActuelle;
			compteur = compteur + 1;
		} 
	}
}

int main()
{
	int nombre = 0;
	string mot;
	verificateur(mot, nombre);
	return 0;
}