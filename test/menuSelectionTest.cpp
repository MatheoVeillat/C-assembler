#include<iostream>
#include<conio.h>
#include<string>

using namespace std;
 
//En fonction de la table ascii

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_X 120
#define KEY_C 13 //touche entre 

int affichage(int nombre){
	if(nombre == 0 || nombre == -1){
		nombre = 0;
		cout<<"--> Blue"<<endl;
		cout<<"    Red"<<endl;
		cout<<"    Orange"<<endl;
		cout<<"    Yellow"<<endl;
	}
	else if(nombre == 1){
		cout<<"    Blue"<<endl;
		cout<<"--> Red"<<endl;
		cout<<"    Orange"<<endl;
		cout<<"    Yellow"<<endl;
	}
	else if(nombre == 2){
		cout<<"    Blue"<<endl;
		cout<<"    Red"<<endl;
		cout<<"--> Orange"<<endl;
		cout<<"    Yellow"<<endl;
	}
	else if(nombre == 3 || nombre == 4){
		nombre = 3;
		cout<<"    Blue"<<endl;
		cout<<"    Red"<<endl;
		cout<<"    Orange"<<endl;
		cout<<"--> Yellow"<<endl;
	}
	return nombre;
}

int main(){
	int nombre = 0;
	char key = getch();
    int value = key;
	while(value != 404){
        switch(getch()){
        case KEY_UP:
        	nombre--;
        	system("cls");
            cout <<"GOES UP"<<endl;
            nombre = affichage(nombre);
            break;
        case KEY_DOWN:
        	nombre++;
        	system("cls");
            cout <<"GOES DOWN"<<endl;
            nombre = affichage(nombre);
            break;
        case KEY_C:
        	value = 404;
        }
    }
    return 0;
}