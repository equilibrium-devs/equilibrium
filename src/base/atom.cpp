#include "atom.h"

atom::atom() : number( 1 ), name( "Hydrogen" ), symbol( "H" ), mass( 1.00794 )
{}

atom::~atom()
{}

void atom::setProperties( const int& inNumber, const std::string& inName, const std::string& inSymbol, const double& inMass )
{
    number = inNumber;
    name = inName;
    symbol = inSymbol;
    mass = inMass;
}

double atom::getMass()
{
    return mass;
}

std::string atom::getSymbol()
{
    return symbol;
}

std::string atom::getName()
{
    return name;
}

std::ostream& operator<<( std::ostream& output, const atom& element )
{
    output << element.name << " (" << element.symbol << ", " << element.number << ", " << element.mass << ")";
    return output;
}

