#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	int nombre = 0;

	HANDLE console; 
	console = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(console, 11);
	cout<<"Bite"<<endl;
	SetConsoleTextAttribute(console, 10);
	cout<<"Vagin"<<endl;
	cin>>nombre;
	return 0;
}