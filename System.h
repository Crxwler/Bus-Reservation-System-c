#ifndef Bus_H
#define Bus_H
#include "Bus.h"
#endif // Bus_H

#ifndef Customer_H
#define Customer_H
#include "Customer.h"
#endif // Customer_H


#ifndef File_h
#define File_h
#include "File.h"
#endif // File_h

#include <vector>

class System{
	public:
		System();
		//~System();
		void menu();
		void insertBus();
		void deleteBus();
		void updateBus();
		void searchBus();
		void bookingSeat();
		void bookingDetails();
		void cancelSeat();
		void printCustomer();
		void printBus();

	private:
		std::vector<Bus> b;
		std::vector<Customer> c;
		int seat;
		float price;
		std::string code, origin, destination, hr_in,hr_out;
		std::string Name,CC;
		int flag;
		int id;
		std::string str;
		Bus temp;
		Customer temp2;
		File save;

};