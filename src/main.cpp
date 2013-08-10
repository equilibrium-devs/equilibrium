#include "atom.h"
#include "molecule.h"
#include "mixture.h"

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
    std::cout << ethane << std::endl;

    std::cout << std::endl;

    molecule ethanol;
    ethanol.add( "C", 2 );
    ethanol.add( "H", 5 );
    ethanol.add( "O" );
    ethanol.add( "H" );
    ethanol.report();

    std::cout << std::endl;

    mixture undefinedMixture;
    undefinedMixture.report();

    std::cout << std::endl;

    mixture reactants;
    reactants.add( "O2", 0.21);
    reactants.add( "N2", 0.79 );
    reactants.add( "CH4", 0.2 );
    reactants.report();

    std::cout << std::endl;

    mixture products( "CO2", 0.4 );
    products.add( "H2O", 0.5);

    std::cout << products << std::endl;
}

