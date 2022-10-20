#include<iostream>

using namespace std;

void size(){
	int nombre;
	cout<<"Votre nombre"<<endl;
	cin>>nombre;
}

int main()
{
	int *size = new int;
	size = &nombre;
	size();
	return 0;
}