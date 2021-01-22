class Bus{

	public:
		Bus(char *, int , char *, char*, char*, char *, float);

		~Bus();
		void insertSchedule(char *, int , char *, char*, char*, char *, float);
		void printAll();

		//Setters 
		void setCode(char *);
		void setSeat(int);
		void setOrigin(char *);
		void setDestination(char *);
		void setHr_in(char *);
		void setHr_out(char *);
		void setPrice(float);

		//Getter
		char * getCode();
		int getSeat();
		char * getOrigin();
		char * getDestination();
		char * getHr_in();
		char * getHr_out();
		float getPrice();

	private:
		char * code;
		int seat;
		char * origin;
		char * destination;
		char * hr_in;
		char * hr_out;
		float price;

};