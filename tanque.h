#pragma once
#include "soldado.h"
#include <string>
using std::string;
 
class Tanque : public Tropas{
    double vida;
    double ataque;
  public:
    Tanque(string, string, double=0.0, double=0);
    Tanque(const Tanque&);
    virtual ~Tanque();
    virtual string toString()const;
    double ataq()const;
    void setVida(double);
    double getVida();
    
};