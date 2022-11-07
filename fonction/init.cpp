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

int *tabStringaEntier(std::string & tabString, int *tabBinaire){
	for(int i = 0; i < tabString.length(); i++){
		tabBinaire[i] = int(tabString[i]) - 48;
	}
	return tabBinaire;
}

void initRegistre(bool (&registre)[sizeNombreRegistre][sizeRegistre]){
    for(int i = 0; i < sizeNombreRegistre; i++){
        for(int j = 0; j < sizeRegistre; j++){
            registre[i][j] = 0;

        }
    }
}

void initMemoireProgramme(string (&memoire)[memoireProgramme][sizeLigneDeCode]){
	for(int i = 0; i < memoireProgramme; i++){
		for(int j = 0; j < sizeLigneDeCode; j++){
			memoire[i][j] = "/";
		}
	}
}

void initTableauBool(bool tableauOriginal[]){
	for(int i = 0;i<sizeRegistre; i++){
		tableauOriginal[i] = 0;
	}
}

void initTableauChar(char tableauOriginal[]){
	for(int i = 0;i <= sizeRegistre ; i++){
		cout<<i<<endl;
		tableauOriginal[i] = '0';
	}
}