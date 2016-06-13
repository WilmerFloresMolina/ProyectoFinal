#pragma once
#include <string>
using std::string;
 
class Tropas{
    string name;
    string id;
   // double vida;
  public:
    Tropas(string, string);
    Tropas(const Tropas&);
    virtual ~Tropas();
    virtual string toString()const;
    virtual double ataq()const;
    virtual double getVida();
    string getName();
    string getId();
    virtual void setVida(double);

};