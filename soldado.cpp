#include "tropas.h"
#include "soldado.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;
 
Soldado::Soldado(string name, string id, double vida, double ataque):Tropas(name, id ),vida(vida), ataque(ataque){

}
Soldado::Soldado(const Soldado& s):Tropas(s),vida(s.vida), ataque(s.ataque){

}
Soldado::~Soldado(){
}
string Soldado::toString()const{
    stringstream ss;
    ss << Tropas::toString() << " Soldado: "  << " Vida: " <<vida << " Ataque: " << ataque;
    return ss.str();
}

double Soldado::ataq()const{
	double ataque1 =ataque*0.45;
	return ataque1;
}

void Soldado::setVida(double a){
	vida=a;
}

double Soldado::getVida(){
	return vida;
}
double Soldado::getAtaque(){
	return ataque;
}
