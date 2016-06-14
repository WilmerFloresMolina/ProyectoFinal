#pragma once
#include "soldado.h"
#include <string>
using std::string;
 
class Avion : public Tropas{
    double vida;
    double ataque;
  public:
    Avion(string, string, double=0.0, double=0);
    Avion(const Avion&);
    virtual ~Avion();
    virtual string toString()const;
    double ataq()const;
    void setVida(double);
    double getVida();
    
};