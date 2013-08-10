#include "atom.h"
#include "molecule.h"

int main( int argc, char** argv )
{
    // Two ways to create an atom
    atom undefinedAtom;
    std::cout << undefinedAtom << std::endl;

    std::cout << std::endl;

    atom carbon( "C" );
    carbon.report();

    std::cout << std::endl;

    // Three ways to create a molecule
    molecule undefinedMolecule;
    std::cout << undefinedMolecule << std::endl;

    std::cout << std::endl;

    molecule ethane( "C2H6" );
    ethane.report();

    std::cout << std::endl;

    molecule ethanol;
    ethanol.addElement( "C", 2 );
    ethanol.addElement( "H", 5 );
    ethanol.addElement( "O" );
    ethanol.addElement( "H" );
    ethanol.report();
}

