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

    int getNumber() const;
    std::string getName() const;
    std::string getSymbol() const;
    double getMass() const;

    void report() const;

    friend std::ostream& operator<<( std::ostream&, const atom& );
};

#endif

