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