#include<iostream>
#include<windows.h>
#include<math.h>
#include<string>
#include<conio.h>
#include<iomanip>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<fstream>

#include "h/header.h"

#include "fonction/affichage.cpp"
#include "fonction/verificateur.cpp"
#include "fonction/convertisseur.cpp"
#include "fonction/init.cpp"
#include "fonction/registre.cpp"
#include "fonction/fichier.cpp"

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define WALK_IN 13

/*enum Position{ LEFT, CENTRE, RIGHT };    */        // "CENTRE" because I'm British!

/*void print( Position pos, string s, int linelength ) 
{
   int spaces = 0;
   switch( pos )
   {
      case CENTRE: spaces = ( linelength - s.size() ) / 2; break;
      case RIGHT : spaces =   linelength - s.size()      ; break;
   }
   if ( spaces > 0 ) cout << string( spaces, ' ' );
   cout << s << '\n';
}*/

/*void afichTabBool(bool tab, int i, int j){
    for(int l = 0; l < i; l++ ){
        for(int c = 0, compteur = 0; c < i; c++, compteur++ ){
            if(compteur == 16){
            	cout<<"/"<<endl;
            	compteur = 0;
            } 
            cout<<tab;      
        }    
    }
}*/


int main()
{

   string stringNombre;
   decimalHexadecimal(stringNombre);
/*bool** initRegistre(){*/
/*	bool** registre = new bool*[100];
	for(int i = 0; i < 100; i++){
		registre[i] = new bool[16];
		for(int j = 0; j < 16; j++){
			registre[i][j] = registre[i][false];
		}
	}
	afichTabBool(registre, 100, 16);

	system("pause");*/
   return 0;
}
/*	return registre;
}*/



















/*   const int LINELENGTH = 237;

   string header( LINELENGTH, '=' );

   string bordure( LINELENGTH, '|');

   cout << header << '\n';
   print( LEFT  , "Left"  , LINELENGTH );
   print( RIGHT , "Right" , LINELENGTH );
   print( CENTRE, "Centre", LINELENGTH );
   cout << header << '\n';

    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

    std::cin.get();*/









