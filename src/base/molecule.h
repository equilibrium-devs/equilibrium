#ifndef MOLECULE_H
#define MOLECULE_H

#include <iostream>
#include <vector>
#include <string>

#include "atom.h"

class molecule
{
    std::vector<atom*> elements;

    public:
    molecule();
    molecule( const std::string& );
    ~molecule();

    void add( const std::string&, const unsigned& = 1 );
    std::string getFormula() const;
    double getMass() const;

    void report();

    friend std::ostream& operator<<( std::ostream&, const molecule& );
};

#endif

