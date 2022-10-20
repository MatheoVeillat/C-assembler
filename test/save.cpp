#include<iostream>
#include<windows.h>
#include<math.h>
#include<string>
#include<conio.h>
#include<iomanip>
#include<fstream>


using namespace std;

void afficheTabBool(bool tab, int i, int j){
    for(int l = 0; l < i; l++ ){
        for(int c = 0, compteur = 0; c < i; c++, compteur++ ){
            if(compteur == 16){
            	cout<<"/"<<endl;
            	compteur = 0;
            } 
            cout<<tab;      
        }    
    }
}

bool *initRegistre(){
	bool** registre = new bool*[100];
	for(int i = 0; i < 100; i++){
		registre[i] = new bool[16];
		for(int j = 0; j < 16; j++){
			registre[i][j] = registre[i][false];
		}
	}
	return *registre;
}

/*void reinitialiserRegistre(bool & *registre){
	int choixRegistre = 0;
	do {
		cout<<"Choix du registre"<<endl;
		cin>>choixRegistre;
	while(5 != choixRegistre){
	for(int i = 0; i < 16; i++){   /*--> Attention au 16, il a pas été tester */
		/*registre[choixRegistre][i] = 0;*/
/*	}
}*/

void fichierCree(){
	ostringstream oss;
	fstream fichier;
	string ancien = oss.str();
	cin>>ancien;
	cout<<"Quel noms pour le fichier"<<endl;
    fichier.open(ancien.c_str(), ios::out);
    if (!fichier)  cout << "Fichier non cree!";
    else {
        cout << "Fichier cree avec succes!";
        fichier.close();
    }
}

void fichierSupprimer(){
	string supprimer;
    cout<<"Entrer le noms du fichier qui va etre supprimer";
     getline(cin,supprimer);
     if (remove(supprimer.c_str( )) !=0) cout<<"Fichier existant"<<endl;
     else cout<<supprimer<<"Le fichier a bien ete supprimer"<<endl;
}

void renommer(){
    ostringstream oss;
    string ancien = oss.str(), nouveau = oss.str();
    cout<<"Quel fichier voulez-vous renommer ?"<<endl;
    cin>>ancien;
    cout<<"Par quel noms ?"<<endl;
    cin>>nouveau;
	rename(ancien.c_str(), nouveau.c_str());
}

/*void ecrireleBinairedanslefichier(){

}*/

/*--> On demande de mettre le type ?*/ 
/*--> Si l utilisateur rentre 2 fois le meme noms de fichier, on est d accord qu on s en blc si il supprime l ancien fichier*/
// --> Si le fichier est pas vraiment trop ranger




/*void sauvegarderRegistre(bool *registre, string name){
	fichier.open("name.txt");
	for(int l = 0; l < i; l++ ){
        for(int c = 0, compteur = 0; c < i; c++, compteur++ ){
            if(compteur == 16){
            	cout<<"/"<<endl;
            	compteur = 0;
            } 
            fichier << registre[i][j]<<endl;      
        }
        fichier<<endl; 
    }
}*/
/*
int main(){
*/
	/*fichierCree();*/
/*	myfile.open ("example.txt");

	int i = 100, j = 16;
	fstream fichier;
    fichier.open("etd.txt", ios::out);
    if (!fichier)  cout << "Fichier non cree!";
    else {
        cout << "Fichier cree avec succes!";
        fichier.close();
    }
     fichier<<"1";  
	while (!fichier.eof())
        {*/
/*            fichier >>ligne;  // lire une ligne
            cout << ligne << endl;   // afficher la ligne lue*/
/*		    for(int l = 0; l < i; l++ ){
		        for(int c = 0, compteur = 0; c < i; c++, compteur++ ){
		            if(compteur == 16){
		            	cout<<"/"<<endl;
		            	compteur = 0;
		            } 
		            /*cout<<tab;*/
		            /*fichier<<"1"; */     
		        /*}*/    
	/*	    }

        }*/
      // fer*/mer le fichier
      /*  fichier.close(); */
int main()
{
	fichierCree();
    return 0;
}
