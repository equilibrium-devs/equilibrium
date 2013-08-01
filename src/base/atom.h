#ifndef ATOM_H
#define ATOM_H

#include <string>
#include <iostream>

class atom
{
    int number;
    std::string name;
    std::string symbol;
    double mass;

    public:
    atom();
    ~atom();

    // Temporary function to fill in properties
    void setProperties( const int&, const std::string&, const std::string&, const double& );

    double getMass();
    std::string getSymbol();
    std::string getName();

    friend std::ostream& operator<<( std::ostream&, const atom& );
};

#endif

