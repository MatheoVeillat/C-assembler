#include "include.h"

int main()
{
   ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

   bool registre[sizeNombreRegistre][sizeRegistre];
   string memoire[memoireProgramme][sizeLigneDeCode];
   initRegistre(registre);
   terminal(registre);
   
   return 0;
}





















