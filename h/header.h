using namespace std;

const int sizeNombreRegistre = 50;
const int sizeLigneDeCode = 15;
const int sizeRegistre = 32;
const int memoireProgramme = 20;

//Affichage 
void sautDeLigne(int size);

void espace(int size);

void affichageTableauInt(int tableau[], int size);

void affichageTableauString(string tableau);

void affichageTableauChar(char tableau[], int size);

void afficherTabBool(bool registre[sizeNombreRegistre][sizeRegistre]);

void affichageTerminalRegistre(bool registre[sizeNombreRegistre][sizeRegistre], string memoire[memoireProgramme][sizeLigneDeCode],bool & verif);

void affichageRegistre(bool (&registre)[sizeNombreRegistre][sizeRegistre], int position);

void pauseNewAffichage(bool registre[sizeNombreRegistre][sizeRegistre], string memoire[memoireProgramme][sizeLigneDeCode], bool & verif);

void commande();

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

void recuperateur(string saisie, char retenuUn[], char retenuDeux[], char retenuTrois[], int decalage);

void recuperateurNombre(string saisie, char retenuChiffre[]);

void entrerBinaire(bool (&registre)[sizeNombreRegistre][sizeRegistre], string saisie, char retenuChiffre[], int position);

void entrerDecimal(bool (&registre)[sizeNombreRegistre][sizeRegistre], string saisie, char retenuChiffre[], int position);

void divisionRegistre(bool (&registre)[sizeNombreRegistre][sizeRegistre], int premierRegistre, int deuxiemeRegistre, int position);

void divisionRegistreReste(bool (&registre)[sizeNombreRegistre][sizeRegistre], int premierRegistre, int deuxiemeRegistre, int position);

//Verificateur
int verificateur(string stringNombre);

void verificateurBinaire(string stringNombre);

bool verificateurRegistre(string stringNombre[], int & nombreRetenu, int size, bool limitationRegistre);

bool verificateurEntrerBinaire(char charNombre[], int size);

bool verificateurNombreTerminal(char stringNombre[], long long unsigned int & intNombre);

bool verificateurCalculateurRegistre(string saisie, char retenuUn[], char retenuDeux[], char retenuTrois[], int & nombreRetenueUn, int & nombreRetenueDeux, int & nombreRetenueTrois, int decalage);

bool verificateurInitRegistre(string saisie, char retenuUn[], int & nombreRetenueDeux, int decalage);

bool verificateurInitToutLesRegistres(string saisie, int decalage);

bool verificateurEntrerRegistre(string saisie, char retenuUn[], int & nombreRetenueUn, int decalage);

bool verificateurProgrammeRegistre(string saisie, char retenuUn[], char retenuDeux[], char retenuTrois[], int & nombreRetenueUn, int & nombreRetenueDeux, int & nombreRetenueTrois, int decalage);

//Init 
int *initTableauInt(int tableau[], int size); 

string *initTableauString(string tableau[], int size);

int *tabStringaEntier(std::string & tabString, int *tabBinaire);

void initRegistre(bool (&registre)[sizeNombreRegistre][sizeRegistre]);

void initMemoireProgramme(string (&memoire)[memoireProgramme][sizeLigneDeCode]); 

void initTableauBool(bool *tableauOriginal);

void initTableauChar(char tableauOriginal[]);

//Registre --> Aucun sous programme dans le fichier  
void reinilialiserRegistre(bool (&registre)[sizeNombreRegistre][sizeRegistre], int position);

void changerValeurRegistre(bool (&registre)[sizeNombreRegistre][sizeRegistre], bool nouvelleValeur[sizeRegistre], int position);

void changerValeurMemoire(string memoire[sizeNombreRegistre][sizeRegistre], string saisie, int position);

void randomRegistre(bool (&registre)[sizeNombreRegistre][sizeRegistre], int position);

void randomTableau(bool (&registre)[sizeNombreRegistre][sizeRegistre]);

void compilateur(bool registre[sizeNombreRegistre][sizeRegistre], string memoire[memoireProgramme][sizeLigneDeCode]);