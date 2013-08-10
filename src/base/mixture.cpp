#include <algorithm>
#include <memory>

#include "mixture.h"

mixture::mixture()
{}

mixture::mixture( const std::string& inFormula, const double& inMoles )
{
    species.push_back( new molecule( inFormula ) );
    moles.push_back( inMoles );
}

mixture::~mixture()
{
    std::for_each( species.begin(), species.end(), std::default_delete<molecule>() );
}

void mixture::add( const std::string& inFormula, const double& inMoles )
{
    species.push_back( new molecule( inFormula ) );
    moles.push_back( inMoles );
}

double mixture::getMass() const
{
    auto totalMass = 0.0;
    auto totalMoles = 0.0;
    auto position = species.begin();
    std::for_each( species.begin(), species.end(),
        [ & ]( molecule* specie )
        {
            totalMass += moles.at( position - species.begin() ) * specie->getMass();
            totalMoles += moles.at( position - species.begin() );
            ++position;
        } );
    auto mass = ( totalMoles )? totalMass / totalMoles : 0;
    return mass;
}

void mixture::report()
{
    std::cout << "Mixture contains " << species.size() << " species." << std::endl;
    auto position = species.begin();
    std::for_each( species.begin(), species.end(),
        [ & ]( molecule* specie )
        {
            std::cout << position - species.begin() + 1 << ". " << specie->getFormula() << '\t' << moles.at( position - species.begin() ) << std::endl;
            ++position;
        } );
    std::cout << "Mixture mass: " << getMass() << std::endl;
}

std::ostream& operator<<( std::ostream& output, const mixture& reactants )
{
    auto position = reactants.species.begin();
    for( auto specie : reactants.species ) {
        output << specie->getFormula() << "(" << reactants.moles.at( position - reactants.species.begin() ) << ")";
        ++position;
        if ( position != reactants.species.end() ) output << ", ";
    }
    return output;
}

