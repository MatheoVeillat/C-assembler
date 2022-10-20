#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <math.h>

const int sizeNombreRegistre = 3;
const int sizeRegistre = 63;

using namespace std;

void initRegistre(bool (&registre)[sizeNombreRegistre][sizeRegistre]){
    for(int i = 0; i < sizeNombreRegistre; i++){
        for(int j = 0; j < sizeRegistre; j++){
            registre[i][j] = 0;

        }
    }
}

void initTableauBool(bool *tableauOriginal){
	for(int i = 0;i<sizeRegistre; i++){
		tableauOriginal[i] = 0;
	}
}

void reinilialiserRegistre(bool (&registre)[sizeNombreRegistre][sizeRegistre], int position){
	for(int i = 0; i < sizeRegistre; i++){
		registre[position][i] = 0;
	}
}

void changerValeurRegistre(bool (&registre)[sizeNombreRegistre][sizeRegistre], bool nouvelleValeur[sizeRegistre], int position){
	for(int i = 0; i < sizeRegistre; i++){
		registre[position][i] = nouvelleValeur[i];
	}
}

void afficherTabBool(bool registre[sizeNombreRegistre][sizeRegistre]){
    for(int i = 0; i < sizeNombreRegistre; i++){
        for(int j = 0; j < sizeRegistre; j++){
            cout<<registre[i][j];
        }
        cout<<endl;
    }
}

bool *inverserTableauBinaireBool(bool *tableauOriginal, int position){
	int j = 0, temp = 0;
	while(j < sizeRegistre/2){
		temp = tableauOriginal[j];
		tableauOriginal[j] = tableauOriginal[sizeRegistre - 1 - j];
		tableauOriginal[sizeRegistre - 1 - j] = temp;
		j++;
	}
	return tableauOriginal;
}

long long  unsigned int binaireDecimalBool(bool registre[sizeNombreRegistre][sizeRegistre], int registreDemande){
	long long unsigned int nombreDecimal = 0;
	for(int i = sizeRegistre - 1;i >= 0;i--){
		nombreDecimal =  registre[registreDemande][i]* pow(2,sizeRegistre - i - 1) + nombreDecimal;
	}
	cout<<"nombre "<<nombreDecimal<<endl;
	return nombreDecimal;
}

void decimalBinaireBool(bool (&registre)[sizeNombreRegistre][sizeRegistre], long long unsigned int resultat, int position){
	bool *tabBinaire = new bool[sizeRegistre];
	initTableauBool(tabBinaire); 
	for(int i = 0; resultat !=0 ; i++){
		tabBinaire[i] = resultat%2;
		resultat = resultat/2;
	}
	tabBinaire = inverserTableauBinaire(tabBinaire, position);
	changerValeurRegistre(registre, tabBinaire, position);
}


void addDeux(bool (&registre)[sizeNombreRegistre][sizeRegistre], int premierRegistre, int deuxiemeRegistre, int position){
	long long unsigned int dPremierRegistre = binaireDecimalBool(registre, premierRegistre), dDeuxiemeRegistre = binaireDecimalBool(registre, deuxiemeRegistre), resultat;
	bool nouvelleValeur[sizeRegistre]; 
	resultat = dPremierRegistre + dDeuxiemeRegistre;
	if(resultat >= pow(2,sizeRegistre) - 1){
		for(int y = 0; y < sizeRegistre ; y++){
			nouvelleValeur[y] = 1;
			changerValeurRegistre(registre, nouvelleValeur, position);
		}
	}
	else 
		decimalBinaireBool(registre, resultat ,position);
	
}

void sous(bool (&registre)[sizeNombreRegistre][sizeRegistre], int premierRegistre, int deuxiemeRegistre, int position){
	long long unsigned int dPremierRegistre = binaireDecimalBool(registre, premierRegistre), dDeuxiemeRegistre = binaireDecimalBool(registre, deuxiemeRegistre), resultat;
	bool nouvelleValeur[sizeRegistre]; 
	resultat = dPremierRegistre - dDeuxiemeRegistre;
	if(resultat <= 0){
		for(int y = 0; y < sizeRegistre ; y++){
			nouvelleValeur[y] = 0;
			changerValeurRegistre(registre, nouvelleValeur, position);			
		}
	}
	else 
		decimalBinaireBool(registre, resultat ,position);
}

//Test a effectue 

void multi(bool (&registre)[sizeNombreRegistre][sizeRegistre], int premierRegistre, int deuxiemeRegistre, int position){
	long long unsigned int dPremierRegistre = binaireDecimalBool(registre, premierRegistre), dDeuxiemeRegistre = binaireDecimalBool(registre, deuxiemeRegistre), resultat;
	bool nouvelleValeur[sizeRegistre]; 
	resultat = dPremierRegistre * dDeuxiemeRegistre;
	cout<<"nombre "<<resultat<<endl;
	if(resultat >= pow(2,sizeRegistre) - 1 ){
		for(int y = 0; y < sizeRegistre ; y++){
			nouvelleValeur[y] = 1;
			changerValeurRegistre(registre, nouvelleValeur, position);
		}
	}
	else 
		decimalBinaireBool(registre, resultat ,position);
}

void randomRegistre(bool (&registre)[sizeNombreRegistre][sizeRegistre], int position){
	bool nouvelleValeur[sizeRegistre];
	int n; 
	for(int i = 0; i < sizeRegistre; i++){
		n = rand()%2; 
		nouvelleValeur[i] = n;
	}
	changerValeurRegistre(registre, nouvelleValeur, position);
}	

void randomTableau(bool (&registre)[sizeNombreRegistre][sizeRegistre]){
	bool nouvelleValeur[sizeRegistre];
	int n; 
	for(int i = 0; i < sizeNombreRegistre; i++)
		for(int y = 0; y < sizeRegistre; y++){
			n = rand()%2; 
			registre[i][y] = n;
	}
}

int main()
{
	srand(time(NULL));

	bool registre[sizeNombreRegistre][sizeRegistre];
	initRegistre(registre);

    /*registre[5][3] = {1};*/

  	randomTableau(registre);
  	afficherTabBool(registre);

  	cout<<endl;

	multi(registre, 0, 1, 2);

  	afficherTabBool(registre);
  	/*changerValeurRegistre(registre, 8);*/
	return 0;
}