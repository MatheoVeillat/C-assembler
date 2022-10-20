#include <windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    while (1)
    {
        char g = getch();
        int x, y;
        POINT xypos;
        cout<<"test"<<endl;
        if (g == 'S' || g == 's')
        {
            cout<<"Enter the new position:"<<endl;
            cin>>x>>y;
            SetCursorPos(x, y);
        }
        else if (g == 'g' || g == 'G')
        {
            GetCursorPos(&xypos);
            cout<<"X:"<<xypos.x<<"\tY:"<<xypos.y<<endl;
        }
        else if(SetCursorPos(x, y) == SetCursorPos(0, 0)){
            cout<<"Sa marche"<<endl;
        }
    }
}
