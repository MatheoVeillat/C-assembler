void fichierCree(){
    ostringstream oss;
    fstream fichier;
    string name = oss.str();
    cin>>name;
    cout<<"Quel noms pour le fichier"<<endl;
    fichier.open(name.c_str(), ios::out);
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
     if (remove(supprimer.c_str( )) !=0) cout<<"Fichier n'existe pas"<<endl;
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