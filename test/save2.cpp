#include <iostream>
#include <fstream>
#include <string>
using namespace std;
 
int main() {

    bool** registre = new bool*[100];
  for(int i = 0; i < 100; i++){
    registre[i] = new bool[16];
    for(int j = 0; j < 16; j++){
      registre[i][j] = registre[i][false];
    }
  }

    fstream fichier;
    string ligne;
    fichier.open("etd.txt", ios::out);
    if (!fichier) {
        cout << "Ce fichier n'existe pas";
    }
    else {
         
      // fournir une chaine de caractère
      cout << "Saisir une chaine de caracteres : ";
      getline(cin,ligne);
 
      // écrire la ligne lue dans le fichier
      for(int i = 0; i < 16; i++){
        fichier << registre[i]<<endl;
      } 
      
 
        fichier.close(); 
    }
    return 0;
}