#include <iostream>
#include <math.h>
#include <string>

void tabStringaEntier(std::string & tabString, int tabBinaire[]){
	for(int i = 0; i < tabString.length(); i++){
		tabBinaire[i] = int(tabString[i]) - 48;
	}
}

int binaireDecimal(int tabBinaire[], int tailleTableau){
	int nombreDecimal = 0;
	for(int i = tailleTableau - 1;i >= 0;i--){
		nombreDecimal = tabBinaire[i] * pow(2,tailleTableau - i- 1) + nombreDecimal;
	}
	return nombreDecimal;
}

int main()
{
	std::string tabString;
	std::cout<<"Taper votre nombre en binaire"<<std::endl;
	std::getline(std::cin,tabString);
	int tabBinaire[tabString.length()], tailleTableau = 0;
	tailleTableau = tabString.length();
	tabStringaEntier(tabString, tabBinaire);
	std::cout<<binaireDecimal(tabBinaire, tailleTableau)<<std::endl;
	return 0;
}
