#pragma once
#include "soldado.h"
#include <string>
using std::string;
 
class Soldado : public Tropas{
    double ataque;
    double vida;
  public:
    
    Soldado(string, string, double=0.0, double=0.0);
    Soldado(const Soldado&);
    virtual ~Soldado();
    virtual string toString()const;
    double ataq()const;
    void setVida(double);
    double getVida();
    double getAtaque();
    
};