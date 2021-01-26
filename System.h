#include "Bus.h"
#include "Customer.h"


class System{
	public:
		System();
		//~System();
		void menu();
		void insertBus(std::string code, int seat,std::string origin, std::string destination, std::string hr_in, std::string hr_out, float price);
		bool deleteBus(int id);
		bool updateBus(std::string code);
		bool searchBus(std::string origin);
		void bookingSeat(std::string code, std::string name, std::string cc);
		void details();
		void cancelSeat();
		void printCustomer();
		void printBus();

	private:
		std::vector<Bus> b;
		std::vector<Customer> c;

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