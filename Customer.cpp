#include <stdio.h>
#include <string>
#include "Customer.h"
#include <iostream>

/*
	string name;
	string cc;
	string code:

 */


Customer::Customer(){
	setName("Null");
	setCode("Null");
	setCC("Null");
}

Customer::Customer(std::string Name, std::string CC){
	setName(Name);
	setCC(CC);	
}
Customer::Customer(std::string Name, std::string Code, std::string CC){
	setName(Name);
	setCode(Code);
	setCC(CC);	
}

void Customer::printAll(){
	//printf("Name\tCode\tCredit Card\n");
	std::cout<<name<<"\t"<<code<<"\t"<<cc;
	printf("\n");
}

void Customer::setName(std::string Name){
	name = Name;
}
void Customer::setCode(std::string Code){
	code = Code;
}
void Customer::setCC(std::string CC){
	cc = CC;
}
std::string Customer::getName(){
	return name;
}
std::string Customer::getCC(){
	return cc;
}
std::string Customer::getCode(){
	return code;
}