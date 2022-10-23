int *inverserTableauBinaireInt(int *tableauOriginal, int size){
	int j = 0, temp = 0;
	while(j < size/2){
		temp = tableauOriginal[j];
		tableauOriginal[j] = tableauOriginal[size - 1 - j];
		tableauOriginal[size - 1 - j] = temp;
		j++;
	}
	return tableauOriginal;
}

void inverserTableauBinaireBool(bool tableauOriginal[]){
	int j = 0, temp = 0;
	while(j < sizeRegistre/2){
		temp = tableauOriginal[j];
		tableauOriginal[j] = tableauOriginal[sizeRegistre - 1 - j];
		tableauOriginal[sizeRegistre - 1 - j] = temp;
		j++;
	}
}

void inverserTableauChar(char tableauOriginal[]){
	int j = 0;
	char temp;
	while(j < sizeRegistre/2){
		temp = tableauOriginal[j];
		tableauOriginal[j] = tableauOriginal[sizeRegistre - 1 - j];
		tableauOriginal[sizeRegistre - 1 - j] = temp;
		j++;
	}
}

//--> Convertisseur decimal, binaire qui mets la valeur dans un tableau de multiple de 4 et qui retourne un entier 

int *decimalBinaireInt(std::string & stringNombre, int & size){ //--> Casser 
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
	tabBinaire = inverserTableauBinaireInt(tabBinaire, size);
	return tabBinaire;
}

void decimalBinaireBool(bool (&registre)[sizeNombreRegistre][sizeRegistre], long long unsigned int resultat, int position){
	bool *tabBinaire = new bool[sizeRegistre];
	initTableauBool(tabBinaire); 
	for(int i = 0; resultat !=0 ; i++){
		tabBinaire[i] = resultat%2;
		resultat = resultat/2;
	}
	inverserTableauBinaireBool(tabBinaire);
	changerValeurRegistre(registre, tabBinaire, position);
}

int binaireDecimal(std::string & tabString, int tabBinaire[]){ //--> Casser 
	int nombreDecimal = 0;
    verificateurBinaire(tabString);
	tabBinaire = tabStringaEntier(tabString, tabBinaire);
	for(int i = tabString.length() - 1;i >= 0;i--){
		nombreDecimal = tabBinaire[i] * pow(2,tabString.length() - i- 1) + nombreDecimal;
	}
	return nombreDecimal;
}

long long unsigned int binaireDecimalBool(bool registre[sizeNombreRegistre][sizeRegistre], int registreDemande){
	long long unsigned int nombreDecimal = 0;
	for(int i = sizeRegistre - 1;i >= 0;i--){
		nombreDecimal =  registre[registreDemande][i]* pow(2,sizeRegistre - i - 1) + nombreDecimal;
	}
	return nombreDecimal;
}


string *decimalHexadecimal(std::string & stringNombre){ //--> Casser 
	int size = 0, *tabBinaire = new int;
	string *tableauRetenu = new string[4]; 
	tableauRetenu = initTableauString(tableauRetenu, 4);
	tabBinaire = decimalBinaireInt(stringNombre, size);
	string *tableauHexadecimal = new string[size/4];
	char symbl[16] = {'0', '1', '2','3','4','5','6','7','8','9','A', 'B', 'C','D','E','F'};
	for(int i = 0, compteur = 3, j  = 0; i < size; i = i + 4, j++){
		tableauHexadecimal[j] = symbl[8 * tabBinaire[compteur - 3 + i] + 4 * tabBinaire[compteur - 2 + i]+ 2 * tabBinaire[compteur - 1 + i]+ tabBinaire[compteur + i] ];
	} 
	return tableauHexadecimal;
}

/*string *decimalHexadecimalRegistre(bool registre[sizeNombreRegistre][sizeRegistre],  int position){ //--> Casser 
	int size = 0, *tabBinaire = new int;
	string *tableauRetenu = new string[4]; 
	tableauRetenu = initTableauString(tableauRetenu, 4);
	tabBinaire = decimalBinaireInt(stringNombre, size);
	string *tableauHexadecimal = new string[size/4];
	char symbl[16] = {'0', '1', '2','3','4','5','6','7','8','9','A', 'B', 'C','D','E','F'};
	for(int i = 0, compteur = 3, j  = 0; i < sizeRegistre; i = i + 4, j++){
		tableauHexadecimal[j] = symbl[8 * tabBinaire[compteur - 3 + i] + 4 * tabBinaire[compteur - 2 + i]+ 2 * tabBinaire[compteur - 1 + i]+ tabBinaire[compteur + i] ];
	} 
	return tableauHexadecimal;
}*/


void add(bool (&registre)[sizeNombreRegistre][sizeRegistre], int premierRegistre, int deuxiemeRegistre, int position){
	bool nouvelleValeur[sizeRegistre];
	int retenue = 0;
	for(int i = sizeRegistre; i > - 1 ; i--){
		if(registre[premierRegistre][i] + registre[deuxiemeRegistre][i] == 1 && retenue == 0 || registre[premierRegistre][i] + registre[deuxiemeRegistre][i] == 2 && retenue == 1 && i != 0)
			nouvelleValeur[i] = 1;
		else if(registre[premierRegistre][i] + registre[deuxiemeRegistre][i] == 2 && i != 0){
			retenue =  1;
			nouvelleValeur[i] = 0;
		}
		else if(registre[premierRegistre][i] + registre[deuxiemeRegistre][i] == 0 && retenue == 1){
			nouvelleValeur[i] = 1;
			retenue = 0;
		}
		else if(i == 0 && retenue == 0 && registre[premierRegistre][i] != 1 || registre[deuxiemeRegistre][i] != 1 && i == 0 && retenue == 0)
			nouvelleValeur[i] = 0;
		else if(i == 0 && retenue >= 1 || registre[premierRegistre][i] == 1 && registre[deuxiemeRegistre][i] == 1 && i == 0){
			for(int y = 0; y < sizeRegistre ;y++)
				nouvelleValeur[y] = 1;
		}
		else nouvelleValeur[i] = 0;	
	}
	changerValeurRegistre(registre, nouvelleValeur, position);
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

void multi(bool (&registre)[sizeNombreRegistre][sizeRegistre], int premierRegistre, int deuxiemeRegistre, int position){
	long long unsigned int dPremierRegistre = binaireDecimalBool(registre, premierRegistre), dDeuxiemeRegistre = binaireDecimalBool(registre, deuxiemeRegistre), resultat;
	bool nouvelleValeur[sizeRegistre]; 
	resultat = dPremierRegistre * dDeuxiemeRegistre;
	if(resultat >= pow(2,sizeRegistre) - 1 ){
		for(int y = 0; y < sizeRegistre ; y++){
			nouvelleValeur[y] = 1;
			changerValeurRegistre(registre, nouvelleValeur, position);
		}
	}
	else 
		decimalBinaireBool(registre, resultat ,position);
}

void recuperateur(string saisie, char retenuUn[], char retenuDeux[], char retenuTrois[]){
	for(int i = 1; i < saisie.length(); i++){	
		if(i == 1 || i == 2 )
			retenuUn[i - 1] = saisie[i];
		else if(i == 5 || i == 6)
			retenuDeux[i - 5] = saisie[i];
		else if(i == 12 || i == 13)
			retenuTrois[i - 12] = saisie[i];
	}
}

void recuperateurNombre(string saisie, char retenuChiffre[]){
	for(int y = 0; y <= sizeRegistre; y++){
		if(y + 5 > saisie.length())
			retenuChiffre[y] = ' ';
		else
			retenuChiffre[y] = saisie[y + 5];
	}
}

void entrerBinaire(bool (&registre)[sizeNombreRegistre][sizeRegistre], string saisie, char retenuChiffre[], int position){ 
	/*inverseEspaceNombre(saisie, retenuChiffre);*/
	/*if(verificateurEntrerBinaire(retenuChiffre, sizeRegistre)){*/
	bool nouvelleValeur[sizeRegistre];
	initTableauBool(nouvelleValeur);
		for(int i = 0; i < sizeRegistre; i++){
			if(retenuChiffre[i] == '0')
				nouvelleValeur[i] = 0;
			else if(retenuChiffre[i] == '1')
				nouvelleValeur[i] = 1;
		}
	inverserTableauBinaireBool(nouvelleValeur);
	changerValeurRegistre(registre, nouvelleValeur, position);
	/*}*/		
}