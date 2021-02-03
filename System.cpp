#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include "System.h"

System::System(){
	save.getText(b, c);
}

void System::menu(){
	int op=-1;
	do {
		printf("Welcome to Bus ticket System\n");
		printf("\tMenu\n");
		printf("1. Insert bus schedule\n");
		printf("2. Delete bus schedule\n");
		printf("3. Update bus schedule\n");
		printf("4. Search bus schedule\n");
		printf("5. Customer seat booking\n");
		printf("6. Customer details\n");
		printf("7. Customer seat cancel\n");
		printf("0. Exit\n");
		scanf("%d",&op);
		switch(op){
			case 0:
				break;
			case 1:
				insertBus();
				break;
			case 2:
				printBus();
				deleteBus();
				break;
			case 3:
				printBus();
				updateBus();
				break;
			case 4:
				searchBus();
				break;
			case 5:
				printBus();
				bookingSeat();
				break;
			case 6:
				bookingDetails();
				break;
			case 7:
				printCustomer();
				cancelSeat();
				break;
			default:
				printf("Please insert a correct option number(0-7)\n");

		}
	} while (op != 0 );
	save.save(b,c);
}

void System::insertBus(){
	printf("Bus Schedule\n");
	printf("Enter code: \n");
	std::cin >> code;
	printf("Enter number of seats: \n");
	scanf(" %d",&seat);
	printf("Enter origin: \n");
	std::fflush(stdin);
	std::getline(std::cin,origin);
	//std::getline(std::cin,origin);
	//std::cin >> origin;
	printf("Enter destination: \n");
	//std::cin >> destination;
	std::fflush(stdin);
	std::getline(std::cin,destination);
	printf("Enter in time: \n");
	std::cin >> hr_in;
	printf("Enter out time: \n");
	std::cin >> hr_out;
	printf("Enter price of ticket: \n");
	scanf(" %f",&price);
	temp.setCode(code);
	temp.setSeat(seat);
	temp.setOrigin(origin);
	temp.setDestination(destination);
	temp.setHr_in(hr_in);
	temp.setHr_out(hr_out);
	temp.setPrice(price);
	b.push_back(temp);
}
void System::deleteBus(){
	printf("Enter ID to delete schedule\n");
	std::cin >> id;
	b.erase(b.begin()+id);
}
void System::updateBus(){
	flag=0;
	str="";
	do{	
		printf("Which schedule want to update?\n");
		printf("Enter code\n");
		std::cin >> str;
		for (int i = 0; i < b.size(); ++i){
			if(flag) break;
			if(b[i].getCode() == str){
				flag=1;
				b[i].setCode(str);
			}
		}
		if(!flag)
			printf("Enter a valid code!\n");

	} while (flag==0);
}

void System::searchBus(){
	flag=1;
	str="";
	do {
		printf("Enter your origin\n");
		std::cin >> str;
		for (int i = 0; i < b.size(); ++i){
			if(b[i].getOrigin() == str) {
				printf("ID Code\tSeat\tOrigin\tDestination\tHr in\t Hr Out\tPrice \n");
				printf("%d. ", i+1);
				b[i].printAll();
			}
		}

		printf("try again?\n");
		printf("1. Yes\n");
		printf("0. No\n");
		scanf("%d",&flag);
	} while ( flag );
}
void System::bookingSeat(){
	do{	
		flag=0;
		printf("Enter code of schedule\n");
		std::cin >> str;
		for (int i = 0; i < b.size(); ++i){
			if(flag) break;
			if(b[i].getCode() == str){
				flag=1;
				printf("Enter full name:\n");
				//std::cin >> Name;
				std::fflush(stdin);
				std::getline(std::cin,Name);
				//std::getline(std::cin,Name);
				printf("Enter credit card number:\n");
				std::cin >> CC;
				temp2.setName(Name);
				temp2.setCC(CC);
				temp2.setCode(b[i].getCode());
				b[i].setSeat(b[i].getSeat()-1);
				c.push_back(temp2);
			}
		}
		if(!flag)
			printf("Enter a valid code!\n");
	} while (flag==0);
	
}
void System::bookingDetails(){
	printf("List of Customers\n");
	printf("ID Name\tCode\tCredit Card\n");
	for (int i = 0; i < c.size(); ++i){
		printf("%d. ", i+1);
		c[i].printAll();
	}

}
void System::cancelSeat(){
	printf("Enter ID to delete Customer\n");
	std::cin >> id;
	c[id].getCode();
	c.erase(c.begin()+id);
}
void System::printCustomer(){
	printf("List of Customers\n");
	printf("ID Name\tCode Bus\tCredit Card\n");
	for (int i = 0; i < c.size(); ++i){
		printf("%d. ", i+1);
		c[i].printAll();
	}
}
void System::printBus(){
	printf("List of Schedule\n");
	printf("ID Code\tSeat\tOrigin\tDestination\tHr in\t Hr Out\tPrice \n");
	for (int i = 0; i < b.size(); ++i){
		printf("%d. ", i+1);
		b[i].printAll();
	}
}