void sautDeLigne(int size){
    for(int i = 0; i < size; i++){
        cout<<endl;
    }
}

void espace(int size){
    for(int i = 0; i < size; i++){
        cout<<" ";
    }
}

void affichageTableauInt(int tableau[], int size){
    for(int i = 0; i < size; i++){
        cout<<tableau[i];
    }
    cout<<endl;
}

void affichageTableauString(string tableau){
    for(int i = 0; i < tableau.length(); i++){
        cout<<tableau[i];
    }
    cout<<endl;
}

void affichageTableauChar(char tableau[], int size){
    int compteur = 0;
    for(int i = 0; i <= size; i++){
        compteur = i;
        cout<<tableau[i];
    }
    cout<<" Le compteur "<<compteur<<endl;
    cout<<endl;
}

void afficherTabBool(bool registre[sizeNombreRegistre][sizeRegistre]){
    for(int i = 0; i < sizeNombreRegistre; i++){
        for(int j = 0; j < sizeRegistre; j++){
            cout<<registre[i][j];
        }
        cout<<endl;
    }
}

void affichageTerminalRegistre(bool registre[sizeNombreRegistre][sizeRegistre], bool & verif){
    if(verif == true){
        system("cls");
        for(int i = 0; i < sizeNombreRegistre; i++){
            espace(200);
            for(int j = 0; j < sizeRegistre; j++){
                cout<<registre[i][j];
            }
            cout<<endl;
        }
        verif = false;
    }
}

void affichageRegistre(bool (&registre)[sizeNombreRegistre][sizeRegistre], int position){
    for(int i = 0; i < sizeRegistre; i++){
        cout<<registre[position][i];
    }
    cout<<endl;
}

void pauseNewAffichage(bool registre[sizeNombreRegistre][sizeRegistre], bool & verif){
    system("pause");
    affichageTerminalRegistre(registre, verif);   
}

void commande(){
    cout<<"COMMANDE"<<endl;
    sautDeLigne(1);
    cout<<"&[<numero registre>] !00 --> Convertie un nombre decimal dans un registre"<<endl;
    sautDeLigne(1);
    cout<<"&[<numero registre>] --> Affiche un registre"<<endl;
    cout<<"&[<numero registre>] ! --> Affiche un registre en decimal"<<endl;
    cout<<"ls --> Affiche les commandes"<<endl;
    sautDeLigne(1);
    cout<<"&[<numero registre>] &[<numero registre>] 01 &[<numero registre>] --> Addition"<<endl;
    cout<<"&[<numero registre>] &[<numero registre>] 02 &[<numero registre>] --> Soustraction"<<endl;
    cout<<"&[<numero registre>] &[<numero registre>] 03 &[<numero registre>] --> Multiplication"<<endl;
    sautDeLigne(1);
    cout<<"*[<numero registre>] --> Reinitialise le registre"<<endl;
    cout<<"** --> Reinitialise les registres"<<endl;
    sautDeLigne(1);
    cout<<"/clear --> Clear le terminal"<<endl;
    cout<<"&/& --> Arret"<<endl;
}

void affichageClavierTdeux(int & nombre, string phraseDebut,string motUn, string motDeux, HANDLE console){
    if(nombre == 0 || nombre == -1){
        nombre = 0;
        SetConsoleTextAttribute(console, 9);
        cout<<phraseDebut<<endl;
        SetConsoleTextAttribute(console, 10);
        cout<<"--> "<<motUn<<endl;
        SetConsoleTextAttribute(console, 11);
        cout<<"    "<<motDeux<<endl;
        SetConsoleTextAttribute(console, 12);
        cout<<"    Retour"<<endl;
    }
    else if(nombre == 1){
        SetConsoleTextAttribute(console, 9);
        cout<<phraseDebut<<endl;
        SetConsoleTextAttribute(console, 10);
        cout<<"    "<<motUn<<endl;
        SetConsoleTextAttribute(console, 11);
        cout<<"--> "<<motDeux<<endl;
        SetConsoleTextAttribute(console, 12);
        cout<<"    Retour"<<endl;

    }
    else if(nombre == 2 || nombre == 3){
    	nombre = 2;
        SetConsoleTextAttribute(console, 9);
        cout<<phraseDebut<<endl;
        SetConsoleTextAttribute(console, 10);
        cout<<"    "<<motUn<<endl;
        SetConsoleTextAttribute(console, 11);
        cout<<"    "<<motDeux<<endl;
        SetConsoleTextAttribute(console, 12);
        cout<<"--> Retour"<<endl;
    }
    SetConsoleTextAttribute(console, 15);
}