#include "tropas.h"
#include "soldado.h"
#include "avion.h"
#include "tanque.h"
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <ncurses.h>
#include <typeinfo>
using std::string;
using std::stringstream;
using std::vector;
using namespace std;




void menu();
void simulacion();
void guardarSoldado(vector <Soldado*> soldado);
void guardarAvion(vector <Avion*> avion);
void guardarTanque(vector <Tanque*> tanque);
void abrirSoldado(vector <Soldado*> soldado);
void abrirAvion(vector <Avion*> avion);
void abrirTanque(vector <Tanque*> tanque);
double abrirArchivo(double ganador);
void guardarArchivo(double ganador);




int main(int argc, char const *argv[]){


	simulacion();
		

	return 0;
}

void guardarSoldado(vector <Soldado*> soldado){


	ofstream output("soldado.bin", ios::binary);
	for(int i =0 ; i<soldado.size();i++){
		Soldado p(soldado[i]->getName(),soldado[i]->getId(),100,100);
		output.write(reinterpret_cast<char*>(&p), sizeof(p));
		
	}
	output.close();
	
}

void guardarAvion(vector <Avion*> avion){


	ofstream output("avion.bin", ios::binary);
	for(int i =0 ; i<avion.size();i++){
		Avion p(avion[i]->getName(),avion[i]->getId(),500,100);
		output.write(reinterpret_cast<char*>(&p), sizeof(p));
		
	}
	output.close();
	
}
void guardarTanque(vector <Tanque*> tanque){


	ofstream output("Tanque.bin", ios::binary);
	for(int i =0 ; i<tanque.size();i++){
		Tanque p(tanque[i]->getName(),tanque[i]->getId(),800,100);
		output.write(reinterpret_cast<char*>(&p), sizeof(p));
		
	}
	output.close();
	
}

void abrirSoldado(vector <Soldado*> soldado){


	ifstream input("soldado.bin", ios::binary);
	Soldado p("","",0,0);
	while (input.read(reinterpret_cast<char*>(&p), sizeof(p))){
		soldado.push_back(new Soldado (p.getName(),p.getId(),100,100));
		
	}
	input.close();
}

void abrirAvion(vector <Avion*> avion){

	ifstream input("avion.bin", ios::binary);
	Avion p("","",0,0);
	while (input.read(reinterpret_cast<char*>(&p), sizeof(p))){
		avion.push_back(new Avion (p.getName(),p.getId(),500,100));
		
	}
	input.close();
	
	
}
void abrirTanque(vector <Tanque*> tanque){


	ifstream input("Tanque.bin", ios::binary);
	Tanque p("","",0,0);
	while (input.read(reinterpret_cast<char*>(&p), sizeof(p))){
		tanque.push_back(new Tanque (p.getName(),p.getId(),800,100));
		
	}
	input.close();
	
	
}

void guardarArchivo(double ganador){
	FILE *guardarpartida;

	guardarpartida = fopen("guardarpartida.bin","w");

	fwrite(&ganador,sizeof(double),1,guardarpartida);

	fclose(guardarpartida);

	}

double abrirArchivo(double ganador){
	FILE  *guardarpartida;

	guardarpartida = fopen("guardarpartida.bin","r");

	fread(&ganador,sizeof(double),1,guardarpartida);
			
	fclose(guardarpartida);

return ganador;

}



void menu(){
	int x=0,y=0;
	clear();
	initscr();
	getmaxyx(stdscr, x, y);
	attron(COLOR_PAIR(2));
	move((x/2)-7,(y/2)-16);
	printw("Menu");
	move((x/2)-6,(y/2)-16);
	printw("1.- jugar");
	move((x/2)-5,( y/2)-16);
	printw("2.- Escoger tropas");
	move((x/2)-4,( y/2)-16);
	printw("3.- Agregar tropas ");
	move((x/2)-3,( y/2)-16);
	printw("4.- cargar quien gano la ultima partida");
	move((x/2)-2,( y/2)-16);
	printw("5.- Salir");
	move((x/2)-1,( y/2)-16);
	printw("Ingrese una opcion: ");
	attroff(COLOR_PAIR(1));

}

void simulacion(){

	vector <Tropas*> tropas;
	vector <Tropas*> jugador1;
	vector <Tropas*> jugador2;
	vector <Soldado*> soldado;
	vector <Avion*> avion;
	vector <Tanque*> tanque;


	clear();
	initscr();
	refresh();
	char opcion;
	int x=0,y=0;
	int cont =1;
	bool jugando =true;
	int contador =0;
	char op ;
	int jugado =1;
	while(jugando){

		menu();
		opcion = getch();
		attroff(COLOR_PAIR(1));
		

		if(opcion=='1'){
			if((!jugador1.empty())&&(!jugador2.empty())){
				clear();
				initscr();
				int pos1= jugador1.size();
				char opcion3;
				char opcion4;
				move(0,0);
				bool ciclo=true;
				int op3=0,op4=0;
				bool centinela =true;
				bool playing=true;
				while(playing){
					if(jugado==1){
						initscr();
						clear();
						pos1= jugador1.size();
						while(centinela){
							clear();
							initscr();
							printw("Jugadror 1 escoga a quien va a mandar a atacar");
							for (int i=0; i<jugador1.size(); i++){
								move (i+1,0);
								printw(jugador1[i]->toString().c_str());
							}


							move(jugador1.size()+2,0);
							printw("Ingrese su opcion: ");
							opcion3=getch();
							op3 = opcion3-48;
							if((op3<=2)&&(op3>=0)){
								centinela =false;
							}else{
								clear();
								initscr();
								move(0,0);
								printw("Error");
								getch();

							}
						}
						centinela=true;

						while(centinela){
							printw("Jugadror 1 escoga a quien va a mandar a atacar");
							for (int i=0; i<jugador1.size(); i++){
								move (i+1,0);
								printw(jugador1[i]->toString().c_str());
							}

							move(pos1+2,0);
							printw("Escoga a cual tropa desea atacar ");

							for (int i=0; i<jugador2.size(); i++){
								move (pos1+5+i,0);
								printw(jugador2[i]->toString().c_str());
							}

							move(jugador1.size()+3+ jugador2.size()+2,0);
							printw("Ingrese su opcion: ");
							opcion4= getch();
						
							op4 = opcion4-48;
							if((op4<=2)&&(op4>=0)){
								centinela =false;
							}else{
								clear();
								initscr();
								move(0,0);
								printw("Error");
								getch();

							}



						}
						

						double vidajg2 =jugador2[op4]->getVida();
						double ataquejg1 = jugador1[op3]->ataq();
						double vidatemp = 0;
						vidatemp = vidajg2 - ataquejg1;
						jugador2[op4]->setVida(vidatemp);
						if(vidatemp<=0){
							move(jugador1.size()+3+ jugador2.size()+2,0);
							printw("mato la tropa del jugador2: ");
							move(jugador1.size()+3+ jugador2.size()+3,0);
							printw(jugador2[op4]->toString().c_str());		
							jugador2.erase(jugador2.begin() + op4);
						}
						jugado=2;
						if(jugador2.empty()){
							playing=false;
							clear();
							initscr();
							printw("Felicidades jugador 1 Gano!!! :) ");
							getch();
							guardarArchivo(1);
						}
					}
///////////////////////////////////////////////////////////////////////////////////////////////// jugador 2

					if(jugado==2){
						clear();
						initscr();
						pos1= jugador2.size();
						while(centinela){
							clear();
							initscr();
							printw("Jugadror 2 escoga a quien va a mandar a atacar");
							for (int i=0; i<jugador2.size(); i++){
								move (i+1,0);
								printw(jugador2[i]->toString().c_str());
							}


							move(jugador2.size()+2,0);
							printw("Ingrese su opcion: ");
							opcion3=getch();
							op3 = opcion3-48;
							if((op3<=2)&&(op3>=0)){
								centinela =false;
							}else{
								clear();
								initscr();
								move(0,0);
								printw("Error");
								getch();

							}
						}
						centinela=true;

						while(centinela){
							printw("Jugadror 2 escoga a quien va a mandar a atacar");
							for (int i=0; i<jugador2.size(); i++){
								move (i+1,0);
								printw(jugador2[i]->toString().c_str());
							}

							move(pos1+2,0);
							printw("Escoga a cual tropa desea atacar ");

							for (int i=0; i<jugador1.size(); i++){
								move (pos1+5+i,0);
								printw(jugador1[i]->toString().c_str());
							}

							move(jugador1.size()+3+ jugador2.size()+2,0);
							printw("Ingrese su opcion: ");
							opcion4= getch();
						
							op4 = opcion4-48;
							if((op4<=2)&&(op4>=0)){
								centinela =false;
							}else{
								clear();
								initscr();
								move(0,0);
								printw("Error");
								getch();

							}



						}
						

						double vidajg2 =jugador1[op4]->getVida();
						double ataquejg1 = jugador2[op3]->ataq();
						double vidatemp = 0;
						vidatemp = vidajg2 - ataquejg1;
						jugador1[op4]->setVida(vidatemp);
						if(vidatemp<=0){
							move(jugador1.size()+3+ jugador2.size()+2,0);
							printw("mato la tropa del jugador2: ");
							move(jugador1.size()+3+ jugador2.size()+3,0);
							printw(jugador1[op4]->toString().c_str());		
							jugador1.erase(jugador1.begin() + op4);
						}
						
						if(jugador1.empty()){
							playing=false;
							clear();
							initscr();
							printw("Felicidades jugador 2 Gano!!! :) ");
							guardarArchivo(2);
						}


						jugado=1;
					}

				}
				getch();
			}

		}
		if(opcion=='2'){
			if((!tropas.empty())&&(4<=tropas.size())){
				for(int j=0;j<2;j++){
					clear();
					initscr();
					int cont =tropas.size()+1;
					for (int i=0; i<tropas.size(); i++){
						move (i,0);
					 	printw(tropas[i]->toString().c_str());

					}
					move(cont,0);
					printw("Ingrese las tropas que va a utilizar Jugador 1: ");
					int pos= 0; //nameTemp[0] -48;
					
				
					move(cont+1,0);
					printw("ingrese la posicion: ");
					op=getch();
					pos = op-48;
					if((pos>=0)&&(pos<=9)){
						jugador1.push_back(tropas.at(pos));
						tropas.erase(tropas.begin() + pos);
					}
					getch();
				}
			

				for(int j=0;j<2;j++){
					clear();
					initscr();
					int cont =tropas.size()+1;
					for (int i=0; i<tropas.size(); i++){
						move (i,0);
					 	printw(tropas[i]->toString().c_str());

					}
					move(cont,0);
					printw("Ingrese las tropas que va a utilizar Jugador 2: ");
					int pos= 0; //nameTemp[0] -48;
					
				
					move(cont+1,0);
					printw("ingrese la posicion: ");
					op=getch();
					pos = op-48;
					if((pos>=0)&&(pos<=9)){
						jugador2.push_back(tropas.at(pos));
						tropas.erase(tropas.begin() + pos);
					}
					getch();
					
				}
			}

		}
		if(opcion=='3'){
			char opcion2;
			char continuar ='s';
			while(continuar =='s'){
				clear();
				initscr();
				move (1,0);
				printw("1. Desea agregar un soldado");
				move (2,0);
				printw("2. Desea agregar un avion");
				move (3,0);
				printw("3. Desea agregar un tanque");
				move (4,0);
				printw("4. Imprimir campamento");
				move (5,0);
				printw("Ingrese su opcion :)");
				opcion2 = getch();
				if(opcion2=='1'){
					clear();
					initscr();
					char name[30];
					char id[30]; 
					double vida =100;
					double ataque=100;
					
					move (1,0);
					printw("1. Ingrese el nombre del soldado : ");
					getstr(name);
					string name2(name);
					move (2,0);
					printw("2. Ingrese el id del soldado:  ");
					getstr(id);
					string id2(id);

					if(contador<9){
						tropas.push_back(new Soldado(name2,id2,vida,ataque));
						soldado.push_back(new Soldado(name2,id2,vida,ataque));
						//guardarSoldado(soldado);
					}
					move (3,0);
					printw("Se ingreso exitosamente el soldado");
					contador++;
					getch();

				}

				if(opcion2=='2'){
					clear();
					initscr();
					char name[30];
					char id[30]; 
					double vida =500;
					double ataque=100;
					
					move (1,0);
					printw("1. Ingrese el nombre del avion : ");
					getstr(name);
					string name2(name);
					move (2,0);
					printw("2. Ingrese el id del avion:  ");
					getstr(id);
					string id2(id);

					if(contador<9){
						tropas.push_back(new Avion(name2,id2,vida,ataque));
						avion.push_back(new Avion(name2,id2,vida,ataque));
						//guardarAvion(avion);

					}

					move (3,0);
					printw("Se ingreso exitosamente el avion");
					contador++;
					getch();


				}

				if(opcion2=='3'){
					clear();
					initscr();
					char name[30];
					char id[30]; 
					double vida =800;
					double ataque=100;
					
					move (1,0);
					printw("1. Ingrese el nombre del tanque : ");
					getstr(name);
					string name2(name);
					move (2,0);
					printw("2. Ingrese el id del tanque: ");
					getstr(id);
					string id2(id);

					if(contador<9){
						tropas.push_back(new Tanque(name2,id2,vida,ataque));
						tanque.push_back(new Tanque(name2,id2,vida,ataque));
						//guardarTanque(tanque);
					}
					move (3,0);
					printw("Se ingreso exitosamente el tanque");
					contador++;
					getch();



				}

				if(opcion2=='4'){
					clear();
					initscr();

					 for (int i=0; i<tropas.size(); i++){
					 	move (i,0);
				 		printw(tropas[i]->toString().c_str());

					}
					getch();
				}

				clear();
				initscr();
				move(0,0);
				printw("desea continuar agregando mas tropas [s/n]: ");
				continuar = getch();
				
			}


		}
		if(opcion=='4'){
			clear();
			initscr();
			if (abrirArchivo(1)==1){
				move(0,0);
				printw("jugador 1 gano");
			}else{
				printw("jugador 2 gano");
			}
			getch();
			
			
		}

		if(opcion=='5'){
			jugando = false;
		}

	}




	clear();
	refresh();
	endwin();


}



