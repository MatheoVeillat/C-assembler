#include <iostream>
#include <conio.h>
#include <string>
 
using namespace std;
 
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_X 120

int main(){
    
    char playerName;
    int marche = 0;
    cout << "Enter Player Name: ";
    cin >> playerName;
    char key = getch();
    int value = key;
    while(value != KEY_X){
        switch(getch()){
        case KEY_UP:
            cout << playerName << " GOES UP"<<endl;
            marche = 5 + 5;
            cout<<marche<<endl;
            break;
        case KEY_DOWN:
            cout << playerName << " GOES DOWN\n\n";
            break;
        case KEY_LEFT:
            cout << playerName << " GOES LEFT\n\n";
            break;
        case KEY_RIGHT:
            cout << playerName << " GOES RIGHT\n\n";
            break;
        }
    }
    system("pause");
    return 0;
}