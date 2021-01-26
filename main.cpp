//#include <stdio.h>
//#include <vector>
//#include <string>
//#include "Bus.h"
//#include "Customer.h"
//#include <iostream>
#include "System.h"
//windows local path C:\Users\ToroMax\Desktop\Cursos\5\FPOO\Unidad-1\Code\Bus

int main(int argc, char const *argv[]){
	int op=-1;
	int seat;
	float price;
	std::string code, origin, destination, hr_in,hr_out;
	std::string Name,CC;
	int flag;
	int id;
	std::string str;
	System run;
	do {
		run.menu();
		scanf("%d",&op);
		switch(op){
			case 0:
				break;
			case 1:
				printf("Bus Schedule\n");
				printf("Enter code: \n");
				fflush(stdin);
				getline(std::cin,code);
				//scanf(" %d",&code);
				printf("Enter number of seats: \n");
				scanf(" %d",&seat);
				printf("Enter origin: \n");
				fflush(stdin);
				getline(std::cin,origin);
				//scanf(" %s",&origin);
				printf("Enter destination: \n");
				fflush(stdin);
				getline(std::cin,destination);
				//scanf(" %s",&destination);
				printf("Enter in time: \n");
				fflush(stdin);
				getline(std::cin,hr_in);
				//scanf(" %s",&hr_in);
				printf("Enter out time: \n");
				fflush(stdin);
				getline(std::cin,hr_out);
				//scanf(" %s",&hr_out);
				printf("Enter price of ticket: \n");
				scanf(" %f",&price);
				run.insertBus(code, origin, destination, hr_in, hr_out, price);

				break;
			case 2: //Boolean ?
				printBus();
				printf("Enter ID to delete schedule\n");
				scanf("%d",&id);
				run.deleteBus(id);
				break;
			case 3://Boolean ?
				run.printBus();
				flag=0;
				str="";
				printf("Which schedule want to update?\n");
				printf("Enter code\n");
				fflush(stdin);
				getline(std::cin,str);
				if(!run.updateBus(str))
					printf("Enter a valid code!\n Try Again!\n");
				else
					printf("Update successful\n");

				break;
			case 4:
				flag=1;
				str="";
				do {
					printf("Enter your origin\n");
					fflush(stdin);
					getline(std::cin,str);
					if(!run.searchBus(str)) {
						/* code */
						printf("try again?\n");
						printf("1. Yes\n");
						printf("0. No\n");
						scanf("%d",&flag);
					}
				} while ( flag );
				
				break;
			case 5:
				printBus();
				printf("Enter code of schedule\n");
				fflush(stdin);
				getline(std::cin,str);
				
				bookingSeat(std::string code, std::string name, std::string cc);
				break;
			case 6:
				printCustomer();
				break;
			case 7:
				printCustomer();
				cancelSeat();
				break;
			default:
				printf("Please insert a correct option number(0-7)\n");
		}
	} while (op != 0 );
	return 0;
}

