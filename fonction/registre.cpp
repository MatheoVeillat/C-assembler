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

void changerValeurMemoire(string memoire[memoireProgramme][sizeLigneDeCode], string saisie, int position){
	for(int i = 0; i < memoireProgramme; i++){
		memoire[position][i] = saisie[i];
		if(saisie.length() <= i ){
			memoire[position][i] = " ";
		}
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

void compilateur(bool registre[sizeNombreRegistre][sizeRegistre], string memoire[memoireProgramme][sizeLigneDeCode]){
	char retenuUn[2], retenuDeux[2], retenuTrois[2], retenuChiffre[sizeRegistre]; 
	int nombreRetenueUn = 0, nombreRetenueDeux = 0, nombreRetenueTrois = 0, compteur = 0;
	string saisie;
	initTableauChar(retenuChiffre);
	for(int i = 0; i < memoireProgramme; i++){ 
		getline(memoire[i]);
		recuperateur(saisie, retenuUn, retenuDeux, retenuTrois, 0);
		if(verificateurCalculateurRegistre(saisie, retenuUn, retenuDeux, retenuTrois, nombreRetenueUn, nombreRetenueDeux, nombreRetenueTrois, 0) && saisie[9] == '1')
			add(registre, nombreRetenueUn, nombreRetenueDeux, nombreRetenueTrois);
		else if(verificateurCalculateurRegistre(saisie, retenuUn, retenuDeux, retenuTrois, nombreRetenueUn, nombreRetenueDeux, nombreRetenueTrois, 0) && saisie[9] == '2')
			sous(registre, nombreRetenueUn, nombreRetenueDeux, nombreRetenueTrois);
		else if(verificateurCalculateurRegistre(saisie, retenuUn, retenuDeux, retenuTrois, nombreRetenueUn, nombreRetenueDeux, nombreRetenueTrois, 0) && saisie[9] == '3')
			multi(registre, nombreRetenueUn, nombreRetenueDeux, nombreRetenueTrois);
		else if(verificateurCalculateurRegistre(saisie, retenuUn, retenuDeux, retenuTrois, nombreRetenueUn, nombreRetenueDeux, nombreRetenueTrois, 0) && saisie[9] == '4')
			divisionRegistre(registre, nombreRetenueUn, nombreRetenueDeux, nombreRetenueTrois);
		else if(verificateurCalculateurRegistre(saisie, retenuUn, retenuDeux, retenuTrois, nombreRetenueUn, nombreRetenueDeux, nombreRetenueTrois, 0) && saisie[9] == '5')
			divisionRegistreReste(registre, nombreRetenueUn, nombreRetenueDeux, nombreRetenueTrois);
		else if(verificateurInitRegistre(saisie, retenuUn, nombreRetenueUn, 0))
			reinilialiserRegistre(registre, nombreRetenueUn);
		else if(verificateurEntrerRegistre(saisie, retenuUn, nombreRetenueUn, 0) && saisie[4] == ':'){
			entrerBinaire(registre, saisie, retenuChiffre, nombreRetenueUn);
		else if(verificateurEntrerRegistre(saisie, retenuUn, nombreRetenueUn, 0) && saisie[4] == '!' && saisie.length() == 5){
			cout<<"Le registre "<<nombreRetenueUn<<" possede le nombre decimal "<<binaireDecimalBool(registre, nombreRetenueUn)<<endl;
		}
		else if(verificateurEntrerRegistre(saisie, retenuUn, nombreRetenueUn, 0) && saisie[4] == '!')
			entrerDecimal(registre, saisie, retenuChiffre, nombreRetenueUn);
		else if(verificateurEntrerRegistre(saisie, retenuUn, nombreRetenueUn, 0) && saisie.length() == 3) 
			affichageRegistre(registre, nombreRetenueUn);
/*		else if(saisie[0] == '|' && saisie.length() == 3){
			if(verificateurRegistre(retenuUn, nombreRetenueUn, 2, true))
				cout<<"test"<<endl;
				cout<<"Le registre "<<nombreRetenueUn<<" possede le nombre hexadecimal "<<decimalHexadecimalRegistre(registre, nombreRetenueUn)<<endl;
		}*/
/*		else if(verificateurInitToutLesRegistres(saisie, 0)){
			cout<<"Yessss"<<endl;
			pauseNewAffichage(registre, memoire, verif = true);
		} */
		else cout<<"ERROR"<<endl;
		sautDeLigne(1);
	}
	initMemoireProgramme(memoire);
}

