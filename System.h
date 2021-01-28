#include "Bus.h"
#include "Customer.h"
#include <vector>
#include <File.h>

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

};



/*
	string code;
	int seat;
	string origin;
	string destination;
	string hr_in;
	string hr_out;
	float price;
 */