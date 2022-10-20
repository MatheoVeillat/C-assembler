#include<iostream>
#include<string>

using namespace std;

bool verificateurRegistre(char stringNombre[], int & nombreRetenu){ 
	nombreRetenu = 0;
	for(int i = 0, nombreActuelle = 0; i != 2;i++){
		if(stringNombre[i] != '1' && stringNombre[i] != '2' && stringNombre[i] != '3' && stringNombre[i] != '4' && stringNombre[i] != '5' && stringNombre[i] != '6' && stringNombre[i] != '7' && stringNombre[i] != '8' && stringNombre[i] != '9' && stringNombre[i] != '0'){
			return false;
		}
		else {
			nombreActuelle = int(stringNombre[i]) - 48;
			nombreRetenu = nombreRetenu * 10 + nombreActuelle;
		} 
	}
	return true;
}

void stringChar(string tableauString, char tableau[]){

}


int main()
{	
	int nombre = 0; 
	string saisie;
	char stringNombre[2]; 
	getline(cin,saisie);
	stringNombre[0] = saisie[0];
	stringNombre[1] = saisie[1];
	if(verificateurRegistre(stringNombre, nombre) == true) cout<<"ça marche et le nombre retenu c est "<<nombre<<endl;
	return 0;
}