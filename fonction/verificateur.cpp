int verificateur(string stringNombre){
	char choix;
	int intNombre = 0;
	cout<<"Taper votre nombre"<<endl;
	getline(std::cin,stringNombre);
	for(int i = 0, nombreActuelle = 0, compteur = 0; compteur != stringNombre.length();i++){
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

void verificateurBinaire(string stringNombre){ 
	char choix;
	int intNombre = 0;
	cout<<"Taper votre nombre"<<endl;
	getline(std::cin,stringNombre);
	for(int i = 0, nombreActuelle = 0, compteur = 0; compteur != stringNombre.length();i++){
		choix = stringNombre[i];
		if(choix != '1' && choix != '0' ){
			cout<<"Erreur taper votre nouveau nombre"<<endl;
			getline(std::cin,stringNombre);
			i = - 1, compteur = 0, intNombre = 0;
		}
		else compteur = compteur + 1;
	}
}

bool verificateurRegistre(char stringNombre[], int & nombreRetenu, int size, bool limitationRegistre){
	nombreRetenu = 0;
	for(int i = 0, nombreActuelle = 0; i != size; i++){
		if(stringNombre[i] != '1' && stringNombre[i] != '2' && stringNombre[i] != '3' && stringNombre[i] != '4' && stringNombre[i] != '5' && stringNombre[i] != '6' && stringNombre[i] != '7' && stringNombre[i] != '8' && stringNombre[i] != '9' && stringNombre[i] != '0'){
			return false;
		}
		else {
			nombreActuelle = int(stringNombre[i]) - 48;
			nombreRetenu = nombreRetenu * 10 + nombreActuelle;
		} 
	}
	if(nombreRetenu > sizeNombreRegistre && limitationRegistre == true) 
		return false;
	else return true;
}

bool verificateurEntrerBinaire(char charNombre[], int size){  //delete 
	int intNombre = 0;
	for(int i = 0, nombreActuelle = 0; i != size; i++){
		if(charNombre[i] != '1' && charNombre[i] != '0')
			return false;
	}
	return true;
}

bool verificateurNombreTerminal(char stringNombre[], long long unsigned int & intNombre){ 
	for(int i = 0, nombreActuelle = 0, compteur = 0; stringNombre[compteur] != '/' ;i++){
		if(stringNombre[i] != '/' && stringNombre[i] != '1' && stringNombre[i] != '2' && stringNombre[i] != '3' && stringNombre[i] != '4' && stringNombre[i] != '5' && stringNombre[i] != '6' && stringNombre[i] != '7' && stringNombre[i] != '8' && stringNombre[i] != '9' && stringNombre[i] != '0')
		{
			return false;	
		}	
		else {
			if(stringNombre[i] != '/'){
				nombreActuelle = int(stringNombre[i]) - 48;
				intNombre = intNombre * 10 + nombreActuelle;
				compteur++;
			}
		} 
	}
	return true;
}

bool verificateurCalculateurRegistre(string saisie, char retenuUn[], char retenuDeux[], char retenuTrois[], int & nombreRetenueUn, int & nombreRetenueDeux, int & nombreRetenueTrois, int decalage){
	if(saisie[decalage] == '&' && saisie[3 + decalage] == ' ' && saisie[4 + decalage] == '&' && saisie[7 + decalage] == ' ' && saisie[8 + decalage] == '0' && saisie[9 + decalage] == '1' && saisie[10 + decalage] == ' ' && saisie[11 + decalage] == '&' && saisie.length() == 14 + decalage
	|| saisie[decalage] == '&' && saisie[3 + decalage] == ' ' && saisie[4 + decalage] == '&' && saisie[7 + decalage] == ' ' && saisie[8 + decalage] == '0' && saisie[9 + decalage] == '2' && saisie[10 + decalage] == ' ' && saisie[11 + decalage] == '&' && saisie.length() == 14 + decalage
	|| saisie[decalage] == '&' && saisie[3 + decalage] == ' ' && saisie[4 + decalage] == '&' && saisie[7 + decalage] == ' ' && saisie[8 + decalage] == '0' && saisie[9 + decalage] == '3' && saisie[10 + decalage] == ' ' && saisie[11 + decalage] == '&' && saisie.length() == 14 + decalage
	|| saisie[decalage] == '&' && saisie[3 + decalage] == ' ' && saisie[4 + decalage] == '&' && saisie[7 + decalage] == ' ' && saisie[8 + decalage] == '0' && saisie[9 + decalage] == '4' && saisie[10 + decalage] == ' ' && saisie[11 + decalage] == '&' && saisie.length() == 14 + decalage
	|| saisie[decalage] == '&' && saisie[3 + decalage] == ' ' && saisie[4 + decalage] == '&' && saisie[7 + decalage] == ' ' && saisie[8 + decalage] == '0' && saisie[9 + decalage] == '5' && saisie[10 + decalage] == ' ' && saisie[11 + decalage] == '&' && saisie.length() == 14 + decalage){
		if(verificateurRegistre(retenuUn, nombreRetenueUn, 2, true) && verificateurRegistre(retenuDeux, nombreRetenueDeux, 2, true) && verificateurRegistre(retenuTrois, nombreRetenueTrois, 2, true))
			return true;
		else return false;	
	}
	else return false;
}


bool verificateurInitRegistre(string saisie, char retenuUn[], int & nombreRetenueUn, int decalage){
	if(saisie[decalage] == '*' && saisie[1 + decalage] != '*' && saisie.length() == 3 + decalage){
		if(verificateurRegistre(retenuUn, nombreRetenueUn, 2, true))
			return true;
		else return false;
	}
	else return false; 	
}

bool verificateurInitToutLesRegistres(string saisie, int decalage){
	if(saisie[decalage] == '*' && saisie[1 + decalage] == '*' && saisie.length() == 2 + decalage
	|| saisie[decalage] == '~' && saisie[1 + decalage] == '~' && saisie.length() == 2 + decalage)
		return true;
	else return false;
}

bool verificateurEntrerRegistre(string saisie, char retenuUn[], int & nombreRetenueUn, int decalage){ 
	if(saisie[decalage] == '&' && saisie[3 + decalage] == ' ' && saisie[4 + decalage] == ':'
	|| saisie[decalage] == '&' && saisie[3 + decalage] == ' ' && saisie[4 + decalage] == '!' && saisie.length() == 5 + decalage
	|| saisie[decalage] == '&' && saisie[3 + decalage] == ' ' && saisie[4 + decalage] == '!'
	|| saisie[decalage] == '&' && saisie.length() == 3 + decalage){
		if(verificateurRegistre(retenuUn, nombreRetenueUn, 2, true))
			return true;
		else return false;
	}
	else return false;
}

bool verificateurProgrammeRegistre(string saisie, char retenuUn[], char retenuDeux[], char retenuTrois[], int & nombreRetenueUn, int & nombreRetenueDeux, int & nombreRetenueTrois){
	recuperateur(saisie, retenuUn, retenuDeux, retenuTrois, 1);
	if(saisie[0] == '~' && verificateurCalculateurRegistre(saisie, retenuUn, retenuDeux, retenuTrois, nombreRetenueUn, nombreRetenueDeux, nombreRetenueTrois, 1)
	|| verificateurInitRegistre(saisie, retenuUn, nombreRetenueUn, 1) 
	|| verificateurEntrerRegistre(saisie, retenuUn, nombreRetenueUn, 1)
	|| verificateurInitToutLesRegistres(saisie, 1)){
		return true;
	}
	else return false;
}
