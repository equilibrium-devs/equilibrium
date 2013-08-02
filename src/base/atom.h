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
    atom( const std::string& = "" );
    ~atom();

    int getNumber();
    std::string getName();
    std::string getSymbol();
    double getMass();

    void report();

    friend std::ostream& operator<<( std::ostream&, const atom& );
};

#endif

