#include<iostream>

using namespace std;

void testCompteur(){
	int nombre;
	cout<<"Taper votre nombre"<<endl;
	cin>>nombre;
	nombre = nombre + 4 - nombre % 4;

	cout<<" Le nombre est "<<nombre<<endl;
}






/*	else if(nombre %4 != 0 && nombre %2 == 0){
		nombre = nombre + 2;
		cout<<" test2 "<<nombre<<endl;;
	}*/

int main()
{
	testCompteur();
	return 0;
}