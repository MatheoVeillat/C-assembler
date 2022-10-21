#include<iostream>
#include<windows.h>
#include<math.h>
#include<string>
#include<conio.h>

const int width = 1000; // 100 caractères de long
const int height = 10;

/*void setSize(short x, short y, HWND consoleWindow){
	SetWindowPos(consoleWindow, 0, 0, , 1000, 0, SWP_NOSIZE | SWP_NOZORDER );
}*/

int main(){
        ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

    std::cout << "Hello world from full screen app!" << std::endl; 
    std::cin.get();
/*	HWND consoleWindow = GetConsoleWindow();

	setSize(width, height, consoleWindow);
	system("pause");*/
}

/*int main(int argc, char *argv[]) 
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 150;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1580;

    printf("columns: %d\n", columns);
    printf("rows: %d\n", rows);
    system("pause");
    return 0;
}*/

/*HWND WINAPI GetConsoleWindowNT(void)
{
    //declare function pointer type
    typedef HWND WINAPI(*GetConsoleWindowT)(void);
    //declare one such function pointer
    GetConsoleWindowT GetConsoleWindow;
    //get a handle on kernel32.dll
    HMODULE hk32Lib = GetModuleHandle(TEXT("KERNEL32.DLL"));
    //assign procedure address to function pointer
    GetConsoleWindow = (GetConsoleWindowT)GetProcAddress(hk32Lib,TEXT("GetConsoleWindow"));
    //check if the function pointer is valid
    //since the function is undocumented
    if(GetConsoleWindow == NULL){
        return NULL;
    }
    //call the undocumented function
    return GetConsoleWindow();
}

void SetBackgroundColor(int BackC)
{
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     WORD wColor = ((BackC & 0x0F) << 4) + (csbi.wAttributes & 0x0F);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

int main()
{
    HWND hWnd=GetConsoleWindowNT();
/*    MoveWindow(hWnd,0,0,800,200,TRUE);*/
   /* int i=0;*/
  /*  for(i=0; i<256; i++){
        SetBackgroundColor(i);
        printf("Test Text Background Color for value i: %d\n",i);
    }*/
/*
    SetBackgroundColor(72);
    Sleep(1);
    system("pause");
}*/