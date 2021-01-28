#include "Bus.h"
#include "Customer.h"
#include <vector>


class File{
	public:
		File();
		File(std::vector<Bus> *b, std::vector<Customer> *c);
		//~File();
		void create(std::vector<Bus> *b, std::vector<Customer> *c);
		void save(std::vector<Bus> *b, std::vector<Customer> *c);
	private:

};