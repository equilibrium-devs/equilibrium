#include "atom.h"

atom::atom( const std::string& inSymbol ) : number( -1 ), name( "Undefined" ), symbol( "X" ), mass( 0.0 )
// Temporary constructor for setting up a CHNO system quickly
{
    if ( inSymbol == "H" ) {
        number = 1;
        name = "Hydrogen";
        symbol = "H";
        mass = 1.00794;
        return;
    }

    if ( inSymbol == "C" ) {
        number = 6;
        name = "Carbon";
        symbol = "C";
        mass = 12.0107;
        return;
    }

    if ( inSymbol == "N" ) {
        number = 7;
        name = "Nitrogen";
        symbol = "N";
        mass = 14.0067;
        return;
    }

    if ( inSymbol == "O" ) {
        number = 8;
        name = "Oxygen";
        symbol = "O";
        mass = 15.9994;
        return;
    }
}

atom::~atom()
{}

int atom::getNumber() const
{
    return number;
}

std::string atom::getName() const
{
    return name;
}

std::string atom::getSymbol() const
{
    return symbol;
}

double atom::getMass() const
{
    return mass;
}

void atom::report() const
{
    std::cout << "Element Name: " << name << std::endl;
    std::cout << "Element Symbol: " << symbol << std::endl;
    std::cout << "Element Number: " << number << std::endl;
    std::cout << "Element Mass: " << mass << std::endl;
}

std::ostream& operator<<( std::ostream& output, const atom& element )
{
    output << element.name << " (" << element.symbol << ", " << element.number << ", " << element.mass << ")";
    return output;
}

