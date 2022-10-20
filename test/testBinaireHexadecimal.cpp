#include <iostream>
#include <math.h>
#include<windows.h>

using namespace std;

int verificateur(std::string & stringNombre){ //Retourne une chaine de caractere a un nombre en verifiant 
	char choix;
	int compteur = 0, nombreActuelle = 0, intNombre = 0;
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
	return intNombre;
}

int *initTableauInt(int tableau[], int size){
	for(int i = 0;i<size;i++){
		tableau[i] = 0;
	}
	return tableau;
}

string *initTableauString(string tableau[], int size){
	for(int i = 0;i<size;i++){
		tableau[i] = "0";
	}
	return tableau;
}

void afficherTableau(int tableau[], int size){
	for(int i = 0;i < size; i++){
		cout<<tableau[i];
	}
	cout<<endl;
}

int *inverserTableauBinaire(int *tableauOriginal, int size){
	int j = 0, temp = 0;
	while(j < size/2){
		temp = tableauOriginal[j];
		tableauOriginal[j] = tableauOriginal[size - 1 - j];
		tableauOriginal[size - 1 - j] = temp;
		j++;
	}
	return tableauOriginal;
}

int *decimalBinaire(std::string & stringNombre, int & size){
	int nombreInitTableau = 1, i = 0, impossibleDiviser = verificateur(stringNombre);
	int nouveauNombre = impossibleDiviser, nouvelleBoucle = impossibleDiviser; 
	while(impossibleDiviser !=0 ){        
		nouveauNombre = impossibleDiviser%2;
		impossibleDiviser = impossibleDiviser/2;
		size++;
	}
	size = size + 4 - size % 4;
	int *tabBinaire = new int[size];
	tabBinaire = initTableauInt(tabBinaire, size);
	while(nouvelleBoucle !=0 ){
		tabBinaire[i] = nouvelleBoucle%2;
		i++;
		nouvelleBoucle = nouvelleBoucle/2;
	}
	tabBinaire = inverserTableauBinaire(tabBinaire, size);
	afficherTableau(tabBinaire, size);
	return tabBinaire;
}

string *decimalHexadecimal(std::string & stringNombre){
	int size = 0, *tabBinaire = new int;
	string *tableauRetenu = new string[4]; 
	tableauRetenu = initTableauString(tableauRetenu, 4);
	tabBinaire = decimalBinaire(stringNombre, size);
	string *tableauHexadecimal = new string[size/4];
	char symbl[16] = {'0', '1', '2','3','4','5','6','7','8','9','A', 'B', 'C','D','E','F'};
	for(int i = 0, compteur = 3, j  = 0; i < size; i = i + 4, j++){
		tableauHexadecimal[j] = symbl[8 * tabBinaire[compteur - 3 + i] + 4 * tabBinaire[compteur - 2 + i]+ 2 * tabBinaire[compteur - 1 + i]+ tabBinaire[compteur + i] ];

		//ancien tab bien moche, mais qui marche :
/*		tableauRetenu[compteur - 3 ] = to_string(tabBinaire[compteur - 3 + i]);
		tableauRetenu[compteur - 2 ] = to_string(tabBinaire[compteur - 2 + i]);
		tableauRetenu[compteur - 1 ] = to_string(tabBinaire[compteur - 1 + i]);
		tableauRetenu[compteur ] = to_string(tabBinaire[compteur + i]);
			if(tableauRetenu[compteur - 3] == "0" && tableauRetenu[compteur - 2] == "0" && tableauRetenu[compteur - 1] == "0" && tableauRetenu[compteur] == "0") tableauHexadecimal[j] = "0";
			else if(tableauRetenu[compteur - 3] == "0" && tableauRetenu[compteur - 2] == "0" && tableauRetenu[compteur - 1] == "0" && tableauRetenu[compteur] == "1") tableauHexadecimal[j] = "1";
			else if(tableauRetenu[compteur - 3] == "0" && tableauRetenu[compteur - 2] == "0" && tableauRetenu[compteur - 1] == "1" && tableauRetenu[compteur] == "0") tableauHexadecimal[j] = "2";
			else if(tableauRetenu[compteur - 3] == "0" && tableauRetenu[compteur - 2] == "0" && tableauRetenu[compteur - 1] == "1" && tableauRetenu[compteur] == "1") tableauHexadecimal[j] = "3";
			else if(tableauRetenu[compteur - 3] == "0" && tableauRetenu[compteur - 2] == "1" && tableauRetenu[compteur - 1] == "0" && tableauRetenu[compteur] == "0") tableauHexadecimal[j] = "4";
			else if(tableauRetenu[compteur - 3] == "0" && tableauRetenu[compteur - 2] == "1" && tableauRetenu[compteur - 1] == "0" && tableauRetenu[compteur] == "1") tableauHexadecimal[j] = "5";
			else if(tableauRetenu[compteur - 3] == "0" && tableauRetenu[compteur - 2] == "1" && tableauRetenu[compteur - 1] == "1" && tableauRetenu[compteur] == "0") tableauHexadecimal[j] = "6";
			else if(tableauRetenu[compteur - 3] == "0" && tableauRetenu[compteur - 2] == "1" && tableauRetenu[compteur - 1] == "1" && tableauRetenu[compteur] == "1") tableauHexadecimal[j] = "7";
			else if(tableauRetenu[compteur - 3] == "1" && tableauRetenu[compteur - 2] == "0" && tableauRetenu[compteur - 1] == "0" && tableauRetenu[compteur] == "0") tableauHexadecimal[j] = "8";
			else if(tableauRetenu[compteur - 3] == "1" && tableauRetenu[compteur - 2] == "0" && tableauRetenu[compteur - 1] == "0" && tableauRetenu[compteur] == "1") tableauHexadecimal[j] = "9";
			else if(tableauRetenu[compteur - 3] == "1" && tableauRetenu[compteur - 2] == "0" && tableauRetenu[compteur - 1] == "1" && tableauRetenu[compteur] == "0") tableauHexadecimal[j] = "A";
			else if(tableauRetenu[compteur - 3] == "1" && tableauRetenu[compteur - 2] == "0" && tableauRetenu[compteur - 1] == "1" && tableauRetenu[compteur] == "1") tableauHexadecimal[j] = "B";
			else if(tableauRetenu[compteur - 3] == "1" && tableauRetenu[compteur - 2] == "1" && tableauRetenu[compteur - 1] == "0" && tableauRetenu[compteur] == "0") tableauHexadecimal[j] = "C";
			else if(tableauRetenu[compteur - 3] == "1" && tableauRetenu[compteur - 2] == "1" && tableauRetenu[compteur - 1] == "0" && tableauRetenu[compteur] == "1") tableauHexadecimal[j] = "D";
			else if(tableauRetenu[compteur - 3] == "1" && tableauRetenu[compteur - 2] == "1" && tableauRetenu[compteur - 1] == "1" && tableauRetenu[compteur] == "0") tableauHexadecimal[j] = "E";
			else tableauHexadecimal[j] = "F";*/
	}

	for(int x = 0;x<size/4;x++){
		cout<<"Tableau de x : "<<tableauHexadecimal[x]<<endl;
	}
	return tableauHexadecimal;
}

/*    int newTableau[(sizeof(tabBinaire)/sizeof(*tabBinaire))/4];
    for(int i = 0;i < (sizeof(tabBinaire)/sizeof(*tabBinaire));i + 3){
    	hexadecimal = 

    }*;

	return tableauHexadecimal;
}


//(sizeof(a)/sizeof(*a))  --> Pour avoir la tailel d'un tableau
//Erreur vient de là 

/*int *inverserTableauBinaire(int *tableau, int size){
	for(int i = 0;i<size;i++){
		if(tableau[i] == 1)tableau[i] = 0;
		else tableau[i] = 1;	
	}
	cout<<"Tableau 3"<<endl;
	afficherTableau(tableau, size);
	return tableau;
}*/

int main(){
	string stringNombre;
	decimalHexadecimal(stringNombre);
}




