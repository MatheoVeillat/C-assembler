#include <iostream>
#include <stdint.h>
int main(int argc,char* argv[])
{   
    int size_type size() const noexcept;   
    typedef __int16 int16_t;
    int16_t x=12000;
    std::cout<<"Size of integer number= "<<sizeof(x)<<" Bytes\n";

    system("pause");
    return 0;
}