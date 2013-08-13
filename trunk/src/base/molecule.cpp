#include <algorithm>
#include <sstream>
#include <memory>
#include <cctype>

#include "molecule.h"

molecule::molecule()
{}

molecule::molecule( const std::string& inFormula )
{
    // Free up memory used by atoms
    std::for_each( elements.begin(), elements.end(), std::default_delete<atom>() );
    elements.clear();

    // FIXME: Should handle groups: e.g. Ca(CO3)2 = Ca + C + 3O + C + 3O
    std::string Symbol = "";
    std::string countString = "";
    for ( auto& partSymbol : inFormula ) {
        // If lower-case, symbol is still being read
        if ( islower( partSymbol ) ) {
            Symbol += partSymbol;
            continue;
        }
        // If number, keep reading count
        if ( isdigit( partSymbol ) ) {
            countString += partSymbol;
            continue;
        }
        // If first time, start reading symbol
        if ( Symbol.empty() ) {
            Symbol = partSymbol;
            continue;
        }
        // Finished reading previous symbol and count
        auto count = 0;
        std::stringstream( countString ) >> count;
        if ( not count ) count = 1;
        addAtom( Symbol, count );
        // Start fresh
        Symbol = partSymbol;
        countString = "";
    }
    // Add the last symbol and count
    auto count = 0;
    std::stringstream( countString ) >> count;
    if ( not count ) count = 1;
    addAtom( Symbol, count );
}

molecule::~molecule()
{
    // Free up memory used by atoms
    std::for_each( elements.begin(), elements.end(), std::default_delete<atom>() );
}

void molecule::addAtom( const std::string& inSymbol )
{
    elements.push_back( new atom( inSymbol ) );
}

void molecule::addAtom( const std::string& inSymbol, const unsigned& inCount )
{
    for ( unsigned count = 0; count < inCount; ++count ) {
        elements.push_back( new atom( inSymbol ) );
    }
}

std::string molecule::getFormula() const
{
    std::stringstream ss;
    int count = 1;
    std::string prevSymbol = "";
    for ( auto element : elements ) {
        // Count number, if same as previous
        if ( element->getSymbol() == prevSymbol ) {
            ++count;
            continue;
        }
        // Write symbol, number (if more than one)
        ss << prevSymbol;
        if ( count > 1 ) ss << count;
        prevSymbol = element->getSymbol();
        count = 1;
    }
    // Write the last symbol and count
    ss << prevSymbol;
    if ( count > 1 ) ss << count;
    return ( ss.str().empty() )? "Undefined" : ss.str();
}

double molecule::getMass() const
{
    auto mass = 0.0;
    std::for_each( elements.begin(), elements.end(),
        [ &mass ]( atom* element )
        {
            mass += element->getMass();
        } );
    return mass;
}

void molecule::report()
{
    std::cout << "Species Formula: " << getFormula() << std::endl;
    std::cout << "Species Mass: " << getMass() << std::endl;
}

std::ostream& operator<<( std::ostream& output, const molecule& species )
{
    output << species.getFormula() << "(" << species.getMass() << ")";
    return output;
}

