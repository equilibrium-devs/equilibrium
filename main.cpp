#include "atom.h"

int main( int argc, char** argv )
{
    atom* myatom = new atom;
    std::cout << *myatom << std::endl;
    delete myatom;

    myatom = new atom( "C" );
    myatom->report();
    delete myatom;
}

