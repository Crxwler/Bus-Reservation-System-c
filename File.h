#ifndef Bus_H
#define Bus_H
#include "Bus.h"
#endif // Bus_H
#ifndef Customer_H
#define Customer_H
#include "Customer.h"
#endif // Customer_H


//#include "Bus.h"
//#include "Customer.h"
#include <vector>
#include <fstream>
#include <string>


class File{
	public:
		File();
		void getText(std::vector<Bus> &b, std::vector<Customer> &c);
		//~File();
		void create(std::vector<Bus> b, std::vector<Customer> c);
		void save(std::vector<Bus> b, std::vector<Customer> c);
	private:
		bool flag;

};