#include "atom.h"

int main( int argc, char** argv )
{
    atom myatom;
    std::cout << myatom << std::endl;

    myatom.setProperties( 2, "Helium", "He", 4.002602 );
    std::cout << myatom << std::endl;
    myatom.setProperties( 3, "Lithium", "Li", 6.941 );
    std::cout << myatom << std::endl;
}

