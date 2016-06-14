#include "tropas.h"
#include "tanque.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;
 
Tanque::Tanque(string name, string id,double vida, double ataque):Tropas(name, id), vida(vida),ataque(ataque){

}
Tanque::Tanque(const Tanque& s):Tropas(s),vida(s.vida), ataque(s.ataque){

}
Tanque::~Tanque(){
	
}
string Tanque::toString()const{
    stringstream ss;
    ss << Tropas::toString() << " Tanque: " <<" Vida "<<vida << " Ataque " << ataque;
    return ss.str();
}

double Tanque::ataq()const{
	double ataque1 =ataque*0.80;
	return ataque1;
}

void Tanque::setVida(double a){
	vida = a;
}

double Tanque::getVida(){
	return vida;
}
