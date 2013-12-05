#include "../src/base/atom.h"
#include "../src/base/molecule.h"

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
    ethanol.addAtom( "C", 2 );
    ethanol.addAtom( "H", 5 );
    ethanol.addAtom( "O" );
    ethanol.addAtom( "H" );
    ethanol.report();
}

