#include <string>

class Customer{
	public:
		Customer();
		Customer(std::string Name, std::string Code);
		Customer(std::string Name, std::string Code, std::string CC);
		void printAll();
		//~Customer();
		void setName(std::string Name);
		void setCode(std::string Code);
		void setCC(std::string CC);
		std::string getName();
		std::string getCC();
		std::string getCode();

	private:
		std::string name;
		std::string cc;
		std::string code;
};


