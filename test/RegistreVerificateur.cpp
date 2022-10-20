#include<iostream>
#include<string>

const int sizeNombreRegistre = 3;
const int sizeRegistre = 63;

using namespace std;

/*Memo 

&1 &4 01 &9 --> Additioner
&1 &4 02 &9 --> Soustraire 
&1 &4 03 &9 --> Multiplier

*1 --> réinitialise le registre 
** --> réinitialise tout les registres 

&*& --> Sauvegarde 

&/& --> Arreter 

*/


void terminal(){
	string saisie;
	cout<<"&/&"<<endl;
	while(saisie[0] != '&' && saisie[1] != '/' && saisie[2] != '&'){
		getline(cin,saisie);
		if(saisie[0] != '*' && saisie[1] != '1')
		else cout<<"ERROR"<<endl;
		
	}
}

int main()
{
	terminal();
	return 0;
}