using namespace std;

const int sizeNombreRegistre = 50;
const int sizeRegistre = 32;

//Affichage 
void sautDeLigne(int size);

void espace(int size);

void affichageTableauInt(int tableau[], int size);

void affichageTableauString(string tableau);

void affichageTableauChar(char tableau[], int size);

void afficherTabBool(bool registre[sizeNombreRegistre][sizeRegistre]);

void affichageTerminalRegistre(bool registre[sizeNombreRegistre][sizeRegistre], bool & verif);

void affichageRegistre(bool (&registre)[sizeNombreRegistre][sizeRegistre], int position);

void pauseNewAffichage(bool registre[sizeNombreRegistre][sizeRegistre], bool & verif);

void commande();

void affichageClavierTdeux(int & nombre, string phraseDebut,string motUn, string motDeux, HANDLE console);

//Convertisseur
int *inverserTableauBinaireInt(int *tableauOriginal, int size);

void inverserTableauBinaireBool(bool tableauOriginal[]);

void inverserTableauChar(char tableauOriginal);

int *decimalBinaireInt(std::string & stringNombre, int & size);

void decimalBinaireBool(bool (&registre)[sizeNombreRegistre][sizeRegistre], long long unsigned int resultat, int position);

int binaireDecimal(std::string & tabString, int tabBinaire[]);

long long unsigned int binaireDecimalBool(bool registre[sizeNombreRegistre][sizeRegistre], int registreDemande);

string *decimalHexadecimal(std::string & stringNombre);

string *decimalHexadecimalRegistre(bool registre[sizeNombreRegistre][sizeRegistre], int position);

void add(bool (&registre)[sizeNombreRegistre][sizeRegistre], int premierRegistre, int deuxiemeRegistre, int position);

void addDeux(bool (&registre)[sizeNombreRegistre][sizeRegistre], int premierRegistre, int deuxiemeRegistre, int position);

void sous(bool (&registre)[sizeNombreRegistre][sizeRegistre], int premierRegistre, int deuxiemeRegistre, int position);

void multi(bool (&registre)[sizeNombreRegistre][sizeRegistre], int premierRegistre, int deuxiemeRegistre, int position);

void recuperateur(string saisie, char retenuUn[], char retenuDeux[], char retenuTrois[]);

void recuperateurNombre(string saisie, char retenuChiffre[]);

void entrerBinaire(bool (&registre)[sizeNombreRegistre][sizeRegistre], string saisie, char retenuChiffre[], int position);

//Verificateur
int verificateur(string stringNombre);

void verificateurBinaire(string stringNombre);

bool verificateurRegistre(string stringNombre[], int & nombreRetenu, int size, bool limitationRegistre);

bool verificateurEntrerBinaire(char charNombre[], int size);

//Init 
int *initTableauInt(int tableau[], int size); 

string *initTableauString(string tableau[], int size);

int *tabStringaEntier(std::string & tabString, int *tabBinaire);

void initRegistre(bool (&registre)[sizeNombreRegistre][sizeRegistre]);

void initTableauBool(bool *tableauOriginal);

void initTableauChar(char tableauOriginal[]);
//Registre --> Aucun sous programme dans le fichier  
void reinilialiserRegistre(bool (&registre)[sizeNombreRegistre][sizeRegistre], int position);

void changerValeurRegistre(bool (&registre)[sizeNombreRegistre][sizeRegistre], bool nouvelleValeur[sizeRegistre], int position);

void randomRegistre(bool (&registre)[sizeNombreRegistre][sizeRegistre], int position);

void randomTableau(bool (&registre)[sizeNombreRegistre][sizeRegistre]);

// Fichier 
void fichierCree();

void fichierSupprimer();

void renommer();