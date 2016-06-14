#include "tropas.h"
#include "avion.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;
 
Avion::Avion(string name, string id, double vida, double ataque):Tropas(name, id),vida(vida), ataque(ataque){

}
Avion::Avion(const Avion& s):Tropas(s), vida(s.vida), ataque(s.ataque){

}
Avion::~Avion(){
}
string Avion::toString()const{
    stringstream ss;
    ss << Tropas::toString() << " Avion: "  <<" Vida: "<<vida <<" Ataque: " << ataque;
    return ss.str();
}

double Avion::ataq()const{
	double ataque1 =ataque*0.70;
	return ataque1;
}

void Avion::setVida(double a){
	vida = a;
}

double Avion::getVida(){
	return vida;
}