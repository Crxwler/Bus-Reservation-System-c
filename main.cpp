#include <stdio.h>
#include "Bus.h"
#include "Customer.h"
void menu();

int main(int argc, char const *argv[]){
	menu();
	return 0;
}

void menu(){
	int op=-1;
	do {
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

				break;
			case 2:

				break;
			case 3:

				break;
			case 4:

				break;
			case 5:

				break;
			case 6:

				break;
			case 7:
				break;
			default:
				printf("Please insert a correct option number(0-7)\n");

		}
	} while (op != 0 );
}