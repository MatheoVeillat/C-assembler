#include<iostream>
#include<windows.h>
#include<string>
#include<iomanip>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<fstream>

#include "h/header.h"

#include "fonction/convertisseur.cpp"
#include "fonction/affichage.cpp"
#include "fonction/verificateur.cpp"
#include "fonction/init.cpp"
#include "fonction/registre.cpp"
#include "fonction/fichier.cpp"


/*Memo

A faire 

entre un , hexadecimal, binaire 
afficher decimal, hexadecimal 



&nombreDecimal 

&*& --> Sauvegarde 



de nimporte quelle base a nimp quel base 

*/

void terminal(bool (&registre)[sizeNombreRegistre][sizeRegistre]){
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	char retenuUn[2], retenuDeux[2], retenuTrois[2], retenuChiffre[sizeRegistre]; 
	int nombreRetenueUn = 0, nombreRetenueDeux = 0, nombreRetenueTrois = 0, compteur = 0;
	bool verif = true;
	string memoire[memoireProgramme][sizeLigneDeCode], saisie;
    initMemoireProgramme(memoire);
	initTableauChar(retenuChiffre);
	while(saisie[0] != '&' || saisie[1] != '/' || saisie[2] != '&' || saisie.length() != 3){ 
		affichageTerminalRegistre(registre, memoire, verif);
		getline(cin,saisie);
		recuperateur(saisie, retenuUn, retenuDeux, retenuTrois, 0);

		if(verificateurCalculateurRegistre(saisie, retenuUn, retenuDeux, retenuTrois, nombreRetenueUn, nombreRetenueDeux, nombreRetenueTrois, 0) && saisie[9] == '1'){ 
			add(registre, nombreRetenueUn, nombreRetenueDeux, nombreRetenueTrois);
			cout<<"Succes addition "<<endl;
			pauseNewAffichage(registre, memoire, verif = true);
		}
		else if(verificateurCalculateurRegistre(saisie, retenuUn, retenuDeux, retenuTrois, nombreRetenueUn, nombreRetenueDeux, nombreRetenueTrois, 0) && saisie[9] == '2'){
			sous(registre, nombreRetenueUn, nombreRetenueDeux, nombreRetenueTrois);
			cout<<"Succes soustraction "<<endl;
			pauseNewAffichage(registre, memoire, verif = true);
		}
		else if(verificateurCalculateurRegistre(saisie, retenuUn, retenuDeux, retenuTrois, nombreRetenueUn, nombreRetenueDeux, nombreRetenueTrois, 0) && saisie[9] == '3'){
			multi(registre, nombreRetenueUn, nombreRetenueDeux, nombreRetenueTrois);
			cout<<"Succes multiplication"<<endl;
			pauseNewAffichage(registre, memoire, verif = true);
		}
		else if(verificateurCalculateurRegistre(saisie, retenuUn, retenuDeux, retenuTrois, nombreRetenueUn, nombreRetenueDeux, nombreRetenueTrois, 0) && saisie[9] == '4'){
			divisionRegistre(registre, nombreRetenueUn, nombreRetenueDeux, nombreRetenueTrois);
			cout<<"Succes division"<<endl;
			pauseNewAffichage(registre, memoire, verif = true);
		}
		else if(verificateurCalculateurRegistre(saisie, retenuUn, retenuDeux, retenuTrois, nombreRetenueUn, nombreRetenueDeux, nombreRetenueTrois, 0) && saisie[9] == '5'){
			divisionRegistreReste(registre, nombreRetenueUn, nombreRetenueDeux, nombreRetenueTrois);
			cout<<"Succes obtention du reste "<<endl;
			pauseNewAffichage(registre, memoire, verif = true);
		}
		else if(verificateurInitRegistre(saisie, retenuUn, nombreRetenueUn, 0)){
			reinilialiserRegistre(registre, nombreRetenueUn);
			cout<<"Le registre "<<nombreRetenueUn<<" est reinilialiser"<<endl;
			pauseNewAffichage(registre, memoire, verif = true);
		}  
		else if(verificateurInitToutLesRegistres(saisie, 0)){ 
			initRegistre(registre); 
			cout<<" Reussi init"<<endl;
			pauseNewAffichage(registre, memoire, verif = true);
		}
		else if(verificateurEntrerRegistre(saisie, retenuUn, nombreRetenueUn, 0) && saisie[4] == ':'){
			entrerBinaire(registre, saisie, retenuChiffre, nombreRetenueUn);
			pauseNewAffichage(registre, memoire, verif = true);
		}
		else if(verificateurEntrerRegistre(saisie, retenuUn, nombreRetenueUn, 0) && saisie[4] == '!' && saisie.length() == 5){
			cout<<"Le registre "<<nombreRetenueUn<<" possede le nombre decimal "<<binaireDecimalBool(registre, nombreRetenueUn)<<endl;
			pauseNewAffichage(registre, memoire, verif = true);
		}
		else if(verificateurEntrerRegistre(saisie, retenuUn, nombreRetenueUn, 0) && saisie[4] == '!'){ 
			entrerDecimal(registre, saisie, retenuChiffre, nombreRetenueUn);
			pauseNewAffichage(registre, memoire, verif = true);
		}
		else if(verificateurEntrerRegistre(saisie, retenuUn, nombreRetenueUn, 0) && saisie.length() == 3){ 
			affichageRegistre(registre, nombreRetenueUn);
			pauseNewAffichage(registre, memoire, verif = true);
		}
		else if(verificateurProgrammeRegistre(saisie, retenuUn, retenuDeux, retenuTrois, nombreRetenueUn, nombreRetenueDeux, nombreRetenueTrois)){
			cout<<"deja "<<endl;
			changerValeurMemoire(memoire, saisie, compteur);
			compteur++;
		}
/*		else if(saisie[0] == '|' && saisie.length() == 3){
			if(verificateurRegistre(retenuUn, nombreRetenueUn, 2, true))
				cout<<"test"<<endl;
				cout<<"Le registre "<<nombreRetenueUn<<" possede le nombre hexadecimal "<<decimalHexadecimalRegistre(registre, nombreRetenueUn)<<endl;
		}*/
		else if(saisie == "help"){
			system("cls");
			commande();
			pauseNewAffichage(registre, memoire, verif = true);
		} 
		else if(saisie == "/clear"){
			system("cls");
			pauseNewAffichage(registre, memoire, verif = true);
		} 
		else cout<<"ERROR"<<endl;
		sautDeLigne(1);
	}
}

int main()
{
	bool registre[sizeNombreRegistre][sizeRegistre];
	string memoire[memoireProgramme][sizeLigneDeCode];
	initRegistre(registre);
	terminal(registre);
	return 0;
}

/*affichageTableauString(saisie);*/