#include <stdio.h>
#include <iostream>
#include "Bus.h"
#include <string>

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
void Bus::printAll(){
	std::cout<<code<<"\t"<<seat<<"\t"<<origin<<"\t"<<destination<<"\t"<<hr_in<<"\t"<<hr_out<<"\t"<< price;
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

