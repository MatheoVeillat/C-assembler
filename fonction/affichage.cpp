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
    for(int i = 0; i < size; i++){
        cout<<tableau[i];
    }
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

void affichageTerminalRegistre(bool registre[sizeNombreRegistre][sizeRegistre], string memoire[memoireProgramme][sizeLigneDeCode], bool & verif){
    if(verif == true){
        system("cls");
        espace(199);
        cout<<"REGISTRE"<<endl;
        sautDeLigne(1);
        for(int i = 0, compteur = 0; i < sizeNombreRegistre ; i++){
            if(i < memoireProgramme + 12){
                if(i == 11){
                    cout<<"Memoire Programme ";
                }
                if(i >= 12){
                    /*espace(3); */
                    if(compteur < 10)
                        cout<<compteur<<"  ";
                    else 
                        cout<<compteur<<" ";
                    for(int j = 0; j < sizeLigneDeCode; j++){
                        cout<<memoire[i - 12][j];
                    }
                    compteur++;
                }
                if( i <= 9){
                    espace(198);
                    cout<<i<<"  ";
                }
                else if ( i <= 10){
                    espace(198);
                    cout<<i<<" ";
                }
                else {
                    espace(180);
                    cout<<i<<" ";
                }
            } 
            else {
                espace(198);
                cout<<i<<" ";
            }
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

void pauseNewAffichage(bool registre[sizeNombreRegistre][sizeRegistre], string memoire[memoireProgramme][sizeLigneDeCode], bool & verif){
    system("pause");
    affichageTerminalRegistre(registre, memoire,verif);   
}

void commande(){
    espace(50);
    cout<<"COMMANDE"<<endl;
    sautDeLigne(1);
    cout<<"CONVERTION"<<endl;
    cout<<"&[<numero registre>] ![<nombre decimal>] --> Convertie un nombre decimal dans un registre"<<endl;
    cout<<"&[<numero registre>] :[<nombre binaire>] --> Convertie un nombre binaire dans un registre"<<endl;
    sautDeLigne(1);
    cout<<"AFFICHAGE"<<endl;
    cout<<"&[<numero registre>] --> Affiche un registre"<<endl;
    cout<<"&[<numero registre>] ! --> Affiche un registre en decimal"<<endl;
    cout<<"&[<numero registre>] ! --> Affiche un registre en hexadecimal"<<endl;
    cout<<"help --> Affiche les commandes"<<endl;
    sautDeLigne(1);
    cout<<"CALCUL"<<endl;
    cout<<"&[<numero registre>] &[<numero registre>] 01 &[<numero registre>] --> Addition"<<endl;
    cout<<"&[<numero registre>] &[<numero registre>] 02 &[<numero registre>] --> Soustraction"<<endl;
    cout<<"&[<numero registre>] &[<numero registre>] 03 &[<numero registre>] --> Multiplication"<<endl;
    cout<<"&[<numero registre>] &[<numero registre>] 04 &[<numero registre>] --> Division"<<endl;
    cout<<"&[<numero registre>] &[<numero registre>] 05 &[<numero registre>] --> Reste de la Division"<<endl;
    sautDeLigne(1);
    cout<<"REINITIALISATION"<<endl;
    cout<<"*[<numero registre>] --> Reinitialise le registre"<<endl;
    cout<<"** --> Reinitialise les registres"<<endl;
    sautDeLigne(1);
    cout<<"ALEATOIRE"<<endl;
    cout<<"*[<numero registre>] --> mets le registre aleatoire"<<endl;
    cout<<"// --> Tout les registres aleatoire"<<endl;
    sautDeLigne(1);
    cout<<"MEMORY"<<endl;
    cout<<"'~' devant une commande --> enregistre la commande dans une memoire"<<endl;
    cout<<"~~ --> compile la commande"<<endl;
    cout<<"changement pour ces variables"<<endl;
    cout<<"&[<numero registre>] @[<nombre binaire>] --> Convertie un nombre binaire dans un registre"<<endl;
    cout<<"Convertion un nombre decimal dans un registre n'est pas disponible dans la memory"<<endl;
    sautDeLigne(1);
    cout<<"TERMINAL"<<endl;
    cout<<"/clear --> Clear le terminal"<<endl;
    cout<<"&/& --> Arret"<<endl;
    sautDeLigne(1);
}
