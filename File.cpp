
File::File() { 
	// File pointer 
	fstream fin; 

	// Open an existing file 
	fin.open("reportcard.csv", ios::in); 
	
	vector<string> row; 
	string line, word, temp; 

	while (fin >> temp) { 

		row.clear(); 

		getline(fin, line); 

		stringstream s(line); 
		while (getline(s, word, ', ')) { 
			row.push_back(word); 
		} 
		for (int i = 0; i < row.size(); ++i){
			/* code */
		}
		} 
	} 
} 


void File::create(std::vector<Bus> *b, std::vector<Customer> *c){ 
	fstream fout; 
	fout.open("Bus.csv", ios::out | ios::app); 

	for (int i = 0; i < b.size(); i++) { 
		fout << b[i].getCode() << ", "
			<< b[i].getSeat() << ", "
			<< b[i].getOrigin() << ", "
			<< b[i].getDestination() << ", "
			<< b[i].getHr_in() << ", "
			<< b[i].getHr_out() << ", "
			<< b[i].getPrice()
			<< "\n"; 
	} 
	fout.close();
	fout = NULL;

	fout.open("Customer.csv", ios::out | ios::app); 
	for (int i = 0; i < c.size(); i++) { 
		fout << c[i].getName() << ", "
			<< c[i].getCC() << ", "
			<< c[i].getCode() 
			<< "\n"; 
	} 
	fout.close();
} 

void File::save(std::vector<Bus> *b, std::vector<Customer> *c) { 
	fstream fin, fout; 
	fin.open("Bus.csv", ios::in); 
	fout.open("BusTemp.csv", ios::out); 

	for (int i = 0; i < b.size(); i++) { 
		fout << b[i].getCode() << ", "
			<< b[i].getSeat() << ", "
			<< b[i].getOrigin() << ", "
			<< b[i].getDestination() << ", "
			<< b[i].getHr_in() << ", "
			<< b[i].getHr_out() << ", "
			<< b[i].getPrice()
			<< "\n"; 
	} 
	fin.close(); 
	fout.close(); 
	remove("Bus.csv"); 
	rename("BusTemp.csv", "Bus.csv");
	fin = NULL;
	fout = NULL;
	
	fin.open("Customer.csv", ios::in);
	fout.open("CustomerTemp.csv", ios::out)
	for (int i = 0; i < c.size(); i++) { 
		fout << c[i].getName() << ", "
			<< c[i].getCC() << ", "
			<< c[i].getCode() 
			<< "\n"; 
	} 
	fin.close();
	fout.close();
	remove("Customer.csv");
	rename("CustomerTemp.csv", "Customer.csv")

} 
