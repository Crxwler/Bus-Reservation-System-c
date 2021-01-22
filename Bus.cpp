#include <stdio.h>
#include "Bus.h"

/*
	char * code;
	int seat;
	char * origin;
	char * destination;
	char * hr_in;
	char * hr_out;
	float price;
 */
void Bus::Bus(char * Code, int Seat, char * Origin, char* Destination, char* Hr_in, char * Hr_out, float Price){
	setCode(Code);
	setSeat(Seat);
	setOrigin(Origin);
	setDestination(Destination);
	setHr_in(Hr_in);
	setHr_out(Hr_out);
	setPrice(Price);
}
~Bus(){
	delete code;
	delete seat;
	delete origin;
	delete destination;
	delete hr_in;
	delete hr_out;
	delete price;
}
void Bus::printAll(){
	printf("Codigo\tAsientos\tOrigen\tDestino\tHora llegada\t Hora Salida\tPrecio \n");
	printf("%s \t%d \t%s \t%s \t%s \t%s  \t%.2f \n", code, seat,  origin, destination, hr_in, hr_out, price);
}

//Setter
void Bus::setCode(char * Code){
	code = Code;
}
void Bus::setSeat(int Seat){
	seat = Seat;
}
void Bus::setOrigin(char *Origin){
	origin = Origin;
}
void Bus::setDestination(char * Destination){
	destination = Destination;
}
void Bus::setHr_in(char * Hr_in){
	hr_in = Hr_in;
}	
void Bus::setHr_out(char * Hr_out){
	hr_out = Hr_out;
}
void Bus::setPrice(float Price){
	price = Price;
}

//Getter
char * Bus::getCode(){
	return code;
}
int Bus::getSeat(){
	return seat;
}
char * Bus::getOrigin(){
	return origin;
}
char * Bus::getDestination(){
	return destination;
}
char * Bus::getHr_in(){
	return hr_in;
}
char * Bus::getHr_out(){
	return hr_out;
}
float Bus::getPrice(){
	return price;
}




