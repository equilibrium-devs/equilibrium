#ifndef MIXTURE_H
#define MIXTURE_H

#include <iostream>
#include <vector>
#include <string>

#include "molecule.h"

class mixture
{
    std::vector<molecule*> species;
    std::vector<double> moles;

    public:
    mixture();
    mixture( const std::string&, const double& = 1.0 );
    ~mixture();

    void add( const std::string&, const double& = 1.0 );
    double getMass() const;

    void report();

    friend std::ostream& operator<<( std::ostream&, const mixture& );
};

#endif

