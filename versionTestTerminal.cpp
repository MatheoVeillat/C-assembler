#include<iostream>
#include<windows.h>
#include<string>
#include<conio.h>
#include<iomanip>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<fstream>

#include "h/header.h"

#include "fonction/affichage.cpp"
#include "fonction/verificateur.cpp"
#include "fonction/convertisseur.cpp"
#include "fonction/init.cpp"
#include "fonction/registre.cpp"
#include "fonction/fichier.cpp"


/*Memo

A faire 

entre un , hexadecimal, binaire 
afficher decimal, hexadecimal 



&nombreDecimal 

&*& --> Sauvegarde 

-8m

de nimporte quelle base a nimp quel base 

FAIT

&10 *99 --> Convertie un nombre decimal dans un registre

&10 --> Affiche un registre 

&01 &44 01 &09 --> Additioner
&01 &04 02 &09 --> Soustraire 
&01 &04 03 &54 --> Multiplier

&/& --> Arreter 
ls --> Liste les commandes 
/clear --> Clear

*01 --> réinitialise le registre / Pas finie 
** --> réinitialise tout les registres

*/

void terminal(bool (&registre)[sizeNombreRegistre][sizeRegistre]){
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	string saisie; 
	char retenuUn[2], retenuDeux[2], retenuTrois[2], retenuChiffre[sizeRegistre]; 
	int nombreRetenueUn = 0, nombreRetenueDeux = 0, nombreRetenueTrois = 0;
	bool verif = true;
	initTableauChar(retenuChiffre);
	while(saisie[0] != '&' || saisie[1] != '/' || saisie[2] != '&' || saisie.length() != 3){ /*&/& --> Arreter */
		affichageTerminalRegistre(registre, verif);
		getline(cin,saisie);
		recuperateur(saisie, retenuUn, retenuDeux, retenuTrois);
		if(saisie[0] == '&' && saisie[3] == ' ' && saisie[4] == '&' && saisie[7] == ' ' && saisie[8] == '0' && saisie[9] == '1' && saisie[10] == ' ' && saisie[11] == '&' && saisie.length() == 14){ //Espace non vérifié
			if(verificateurRegistre(retenuUn, nombreRetenueUn, 2, true) && verificateurRegistre(retenuDeux, nombreRetenueDeux, 2, true) && verificateurRegistre(retenuTrois, nombreRetenueTrois, 2, true)){
				add(registre, nombreRetenueUn, nombreRetenueDeux, nombreRetenueTrois);
				cout<<"Succes addition "<<endl;
				pauseNewAffichage(registre, verif = true);
			}
		}
		else if(saisie[0] == '&' && saisie[3] == ' ' && saisie[4] == ':'){
			recuperateurNombre(saisie, retenuChiffre);
			if(verificateurRegistre(retenuUn, nombreRetenueUn, 2, true)){
				entrerBinaire(registre, saisie, retenuChiffre, nombreRetenueUn);
				cout<<"Succes saisie "<<endl;
				pauseNewAffichage(registre, verif = true);
			}
		}
		else if(saisie[0] == '&' && saisie[3] == ' ' && saisie[4] == '&' && saisie[7] == ' ' && saisie[8] == '0' && saisie[9] == '2' && saisie[10] == ' ' && saisie[11] == '&' && saisie.length() == 14){
			if(verificateurRegistre(retenuUn, nombreRetenueUn, 2, true) && verificateurRegistre(retenuDeux, nombreRetenueDeux, 2, true) && verificateurRegistre(retenuTrois, nombreRetenueTrois, 2, true)){
				sous(registre, nombreRetenueUn, nombreRetenueDeux, nombreRetenueTrois);
				cout<<"Succes soustraction "<<endl;
				pauseNewAffichage(registre, verif = true);
			}			
		}
		else if(saisie[0] == '&' && saisie[3] == ' ' && saisie[4] == '&' && saisie[7] == ' ' && saisie[8] == '0' && saisie[9] == '3' && saisie[10] == ' ' && saisie[11] == '&' && saisie.length() == 14){
			if(verificateurRegistre(retenuUn, nombreRetenueUn, 2, true) && verificateurRegistre(retenuDeux, nombreRetenueDeux, 2, true) && verificateurRegistre(retenuTrois, nombreRetenueTrois, 2, true)){
				multi(registre, nombreRetenueUn, nombreRetenueDeux, nombreRetenueTrois);
				cout<<"Succes multiplication"<<endl;
				pauseNewAffichage(registre, verif = true);
			}
		}
		else if(saisie[0] == '*' && saisie[1] != '*' && saisie.length() == 3){ 
			if(verificateurRegistre(retenuUn, nombreRetenueUn, 2, true)){
				reinilialiserRegistre(registre, nombreRetenueUn);
				cout<<"Le registre "<<nombreRetenueUn<<" est reinilialiser"<<endl;
				pauseNewAffichage(registre, verif = true);
			}
		}
		else if(saisie[0] == '*' && saisie[1] == '*' && saisie.length() == 2) { 
			initRegistre(registre); /* ** --> réinitialise tout les registres */
			cout<<" Reussi init"<<endl;
			pauseNewAffichage(registre, verif = true);
		}
		else if(saisie[0] == '&' && saisie[3] == ' ' && saisie[4] == '!' && saisie.length() == 7){ //Manque la possibilité d augmenté &55 *10
			if(verificateurRegistre(retenuUn, nombreRetenueUn, 2, true) && verificateurRegistre(retenuDeux, nombreRetenueDeux, 2, false)){
				decimalBinaireBool(registre, nombreRetenueDeux, nombreRetenueUn);
				cout<<"La valeur decimal "<<nombreRetenueDeux<<" a ete convertie dans le registre "<<nombreRetenueUn<<endl;
				pauseNewAffichage(registre, verif = true);
			}
		}
		else if(saisie[0] == '&' && saisie.length() == 3){ // &55
			if(verificateurRegistre(retenuUn, nombreRetenueUn, 2, true)){
				affichageRegistre(registre, nombreRetenueUn);
				pauseNewAffichage(registre, verif = true);
			}
		}
/*		else if(saisie[0] == '|' && saisie.length() == 3){
			if(verificateurRegistre(retenuUn, nombreRetenueUn, 2, true))
				cout<<"test"<<endl;
				cout<<"Le registre "<<nombreRetenueUn<<" possede le nombre hexadecimal "<<decimalHexadecimalRegistre(registre, nombreRetenueUn)<<endl;
		}*/
		else if(saisie[0] == '&' && saisie[3] == ' ' && saisie[4] == '!' && saisie.length() == 5){
			if(verificateurRegistre(retenuUn, nombreRetenueUn, 2, true)){
				cout<<"Le registre "<<nombreRetenueUn<<" possede le nombre decimal "<<binaireDecimalBool(registre, nombreRetenueUn)<<endl;
				pauseNewAffichage(registre, verif = true);
			}
		}
		else if(saisie == "help"){
			system("cls");
			commande();
			pauseNewAffichage(registre, verif = true);
		} 
		else if(saisie == "/clear"){
			system("cls");
			affichageTerminalRegistre(registre, verif = true);
		} 
		else cout<<"ERROR"<<endl;
		sautDeLigne(1);
	}
}

int main()
{
	bool registre[sizeNombreRegistre][sizeRegistre];
	initRegistre(registre);
	terminal(registre);
	return 0;
}

/*affichageTableauString(saisie);*/