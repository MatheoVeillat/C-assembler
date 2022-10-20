//--> Attention Bug Saisie 

int verificateur(string stringNombre){ //Retourne une chaine de caractere a un nombre en verifiant 
	/*string stringNombre;*/
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

void verificateurBinaire( string stringNombre){ //Retourne une chaine de caractere a un nombre en verifiant 
	/*string stringNombre;*/
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
	if(nombreRetenu > sizeNombreRegistre && limitationRegistre == true) return false;
	else return true;
}

void verificateurBinaireRegistre( string stringNombre){ //Modifier pour verifier si l entre du tableau est juste  
	/*string stringNombre;*/
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
