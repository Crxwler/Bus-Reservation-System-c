#include <stdio.h>
#include <vector>
#include <string>
#include "Bus.h"
#include "Customer.h"
#include <iostream>

/*
	string code;
	int seat;
	string origin;
	string destination;
	string hr_in;
	string hr_out;
	float price;
	std::vector<Bus> b;
	std::vector<Customer> c;
 */


void menu(){
	printf("1. Insert bus schedule\n");
	printf("2. Delete bus schedule\n");
	printf("3. Update bus schedule\n");
	printf("4. Search bus schedule\n");
	printf("5. Customer seat booking\n");
	printf("6. Customer details\n");
	printf("7. Customer seat cancel\n");
	printf("0. Exit\n");
}

void System::insertBus(std::string code, int seat,std::string origin, std::string destination, std::string hr_in, std::string hr_out, float price){
	Bus temp;
	//Bus temp(code,seat,origin,destination,hr_in,hr_out,price);
	//Bus temp;
	//temp.Bus(code,seat,origin,destination,hr_in,hr_out,price);
	temp.setCode(code);
	temp.setSeat(seat);
	temp.setOrigin(origin);
	temp.setDestination(destination);
	temp.setHr_in(hr_in);
	temp.setHr_out(hr_out);
	temp.setPrice(price);
	b.push_back(temp);
}
void System::deleteBus(int id){
	b.erase(b.begin()+id);
}
bool System::updateBus(std::string code){
	flag=0;
	for (int i = 0; i < b.size(); ++i){
		if(flag) break;
		if(b[i].getCode() == code){
			flag=1;
			b[i].setCode(code);
			return true;
		}
	}
	return false;
}

bool System::searchBus(std::string origin){
	flag=1;
	str="";
	do {
		printf("Enter your origin\n");
		fflush(stdin);
		getline(std::cin,str);
		for (int i = 0; i < b.size(); ++i){
			if(b[i].getOrigin() == str) {
				b[i].printAll();
			}
		}

		printf("try again?\n");
		printf("1. Yes\n");
		printf("0. No\n");
		scanf("%d",&flag);
	} while ( flag );
}
void System::bookingSeat(std::string code, std::string name, std::string cc){
	Customer temp2;
	do{	
		flag=0;
		printf("Enter code of schedule\n");
		fflush(stdin);
		getline(std::cin,str);
		for (int i = 0; i < b.size(); ++i){
			if(flag) break;
			if(b[i].getCode() == str){
				flag=1;
				printf("Enter full name:\n");
				fflush(stdin);
				getline(std::cin,Name);
				printf("Enter credit card number:\n");
				fflush(stdin);
				getline(std::cin,CC);
				temp2.setName(Name);
				temp2.setCC(CC);
				temp2.setCode(b[i].getCode());
				c.push_back(temp2);
			}
		}
		if(!flag)
			printf("Enter a valid code!\n");


	} while (flag==0);
}
void System::bookingDetails(){
	for (int i = 0; i < b.size(); ++i){
		printf("List of Customers\n");
		printf("ID Name\tCode\tCredit Card\n");
		printf("%d. ", i+1);
		b[i].printAll();
	}
}
void System::cancelSeat(int id){
	b.erase(b.begin()+id);
}
void System::printCustomer(){
	for (int i = 0; i < b.size(); ++i){
		printf("List of Customers\n");
		printf("ID Name\tCode Bus\tCredit Card\n");
		printf("%d. ", i+1);
		b[i].printAll();
	}
}
void System::printBus(){
	for (int i = 0; i < b.size(); ++i){
		printf("List of Schedule\n");
		printf("ID Code\tSeat\tOrigin\tDestination\tHr in\t Hr Out\tPrice \n");
		printf("%d. ", i+1);
		b[i].printAll();
	}
}