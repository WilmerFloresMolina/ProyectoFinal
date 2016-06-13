#include "tropas.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;
 
Tropas::Tropas(string name, string id):name(name), id(id){

	
}
Tropas::Tropas(const Tropas& p):name(p.name), id(p.id){
	
}
Tropas::~Tropas(){

}
string Tropas::toString()const{
    stringstream ss;
    ss << "Tropa: " << " Nombre: " << name <<  " ID: " << id;
    return ss.str();
}

double Tropas::ataq()const{
	return -1;
}

double Tropas::getVida(){
	return 0;
}
string Tropas::getName(){
	return name;
}
string Tropas::getId(){
	return id;
}
void Tropas::setVida(double a){
}
