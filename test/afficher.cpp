enum Position{ LEFT, CENTRE, RIGHT };            // "CENTRE" because I'm British!

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

void afichTabBool(bool tab, int i, int j){
    for(int l = 0; l < i; l++ ){
        for(int c = 0, compteur = 0; c < i; c++, compteur++ ){
            if(compteur == 16){
            	cout<<"/"<<endl;
            	compteur = 0;
            } 
            cout<<tab;      
        }    
    }
}


int main()
{


/*bool** initRegistre(){*/
	bool** registre = new bool*[100];
	for(int i = 0; i < 100; i++){
		registre[i] = new bool[16];
		for(int j = 0; j < 16; j++){
			registre[i][j] = registre[i][false];
		}
	}
	afichTabBool(registre, 100, 16);

	system("pause");


/*	return registre;
}*/