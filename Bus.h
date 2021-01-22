#include <string>

class Bus{

	public:
		Bus();
		Bus(std::string Code, int Seat, std::string Origin, std::string Destination, std::string Hr_in, std::string Hr_out, float Price);
		//Bus(const Bus &b);
		//~Bus();
		void printAll();

		//Setters 
		void setCode(std::string Code);
		void setSeat(int Seat);
		void setOrigin(std::string Origin);
		void setDestination(std::string Destination);
		void setHr_in(std::string Hr_in);
		void setHr_out(std::string hr_out);
		void setPrice(float Price);

		//Getter
		std::string getCode();
		int getSeat();
		std::string getOrigin();
		std::string getDestination();
		std::string getHr_in();
		std::string getHr_out();
		float getPrice();

	private:
		std::string code;
		int seat;
		std::string origin;
		std::string destination;
		std::string hr_in;
		std::string hr_out;
		float price;

};