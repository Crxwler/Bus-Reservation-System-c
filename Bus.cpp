#include <stdio.h>
#include <iostream>
#include "Bus.h"
#include <string>

/*
	string code;
	int seat;
	string origin;
	string destination;
	string hr_in;
	string hr_out;
	float price;
 */
Bus::Bus(){
	setCode("Null");
	setSeat(0);
	setOrigin("Null");
	setDestination("Null");
	setHr_in("Null");
	setHr_out("Null");
	setPrice(0.0);
}
Bus::Bus(std::string Code, int Seat, std::string Origin, std::string Destination, std::string Hr_in, std::string Hr_out, float Price){
	setCode(Code);
	setSeat(Seat);
	setOrigin(Origin);
	setDestination(Destination);
	setHr_in(Hr_in);
	setHr_out(Hr_out);
	setPrice(Price);
}
/*Bus::Bus(const Bus &b){
	setCode(b.getCode());
	setSeat(b.getSeat());
	setOrigin(b.getOrigin());
	setDestination(b.getDestination());
	setHr_in(b.getHr_in());
	setHr_out(b.getHr_out());
	setPrice(b.getPrice());
}
*/
/*
~Bus(){
	
	delete code;
	delete seat;
	delete origin;
	delete destination;
	delete hr_in;
	delete hr_out;
	delete price;
	
}*/
void Bus::printAll(){
	//printf("Codigo\tAsientos\tOrigen\tDestino\tHora llegada\t Hora Salida\tPrecio \n");
	std::cout<<code<<"\t"<<seat<<"\t"<<origin<<"\t"<<destination<<"\t"<<hr_in<<"\t"<<hr_out<<"\t"<< price;
	//printf("  %s \t%d \t%s \t%s \t%s \t%s  \t%.2f \n", code, seat,  origin, destination, hr_in, hr_out, price);
	printf("\n");
}

//Setter
void Bus::setCode(std::string Code){
	code = Code;
}
void Bus::setSeat(int Seat){
	seat = Seat;
}
void Bus::setOrigin(std::string Origin){
	origin = Origin;
}
void Bus::setDestination(std::string Destination){
	destination = Destination;
}
void Bus::setHr_in(std::string Hr_in){
	hr_in = Hr_in;
}	
void Bus::setHr_out(std::string Hr_out){
	hr_out = Hr_out;
}
void Bus::setPrice(float Price){
	price = Price;
}

//Getter
std::string Bus::getCode(){
	return code;
}
int Bus::getSeat(){
	return seat;
}
std::string Bus::getOrigin(){
	return origin;
}
std::string Bus::getDestination(){
	return destination;
}
std::string Bus::getHr_in(){
	return hr_in;
}
std::string Bus::getHr_out(){
	return hr_out;
}
float Bus::getPrice(){
	return price;
}




