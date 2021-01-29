#include "File.h"
#include <fstream>
#include <string>
#include <sstream>

File::File(){

	printf("Verifico Archivo\n");
	std::fstream fin;
	fin.open("Bus.csv", std::ios::in);
	if(fin.is_open()) {
		flag = true;
		printf("Verdaddero\n");
	}else{
		//printf("File not found, No schedule\n");
		flag = false;
		printf("Falso\n");
	}
}
//getData from csv to vector 
void File::getText(std::vector<Bus> &b, std::vector<Customer> &c) { 
	//File();
	printf("Si obtiene datos\n");
	std::fstream fin; 
	fin.open("Bus.csv", std::ios::out | std::ios::app);  
	
	std::vector<std::string> row; 
	std::string line, word, temp; 
	Bus Temp;
	while (fin >> temp && flag) { 

		row.clear(); 

		getline(fin, line); 

		std::stringstream s(line); 
		while (std::getline(s, word, ',')) { 
            row.push_back(word); 
        } 
		for (int i = 0; i < row.size(); ++i){
			Temp.setCode(row[i]);
			Temp.setSeat(std::stoi(row[i]));
			Temp.setOrigin(row[i]);
			Temp.setDestination(row[i]);
			Temp.setHr_in(row[i]);
			Temp.setHr_out(row[i]);
			Temp.setPrice(std::stod(row[i]));
			b.push_back(Temp);		
		}
		
	} 
} 


void File::create(std::vector<Bus> b, std::vector<Customer> c){ 
	std::fstream fout; 
	fout.open("Bus.csv", std::ios::out | std::ios::app);
	if(!flag) {
		printf("Lo creoo\n");
		for (int i = 0; i < b.size(); i++) { 
			fout << b[i].getCode() << ","
				<< b[i].getSeat() << ","
				<< b[i].getOrigin() << ","
				<< b[i].getDestination() << ","
				<< b[i].getHr_in() << ","
				<< b[i].getHr_out() << ","
				<< b[i].getPrice()
				<< "\n"; 
		} 
		fout.close();
		fout = NULL;

		fout.open("Customer.csv", std::ios::out | std::ios::app); 
		for (int i = 0; i < c.size(); i++) { 
			fout << c[i].getName() << ","
				<< c[i].getCC() << ","
				<< c[i].getCode() 
				<< "\n"; 
		} 
		fout.close();
	}
} 

void File::save(std::vector<Bus> b, std::vector<Customer> c) { 
	printf("Lo guardooo!!\n");
	std::fstream fin, fout; 
	fin.open("Bus.csv", std::ios::in); 
	fout.open("BusTemp.csv", std::ios::out); 

	for (int i = 0; i < b.size(); i++) { 
		fout << b[i].getCode() << ","
			<< b[i].getSeat() << ","
			<< b[i].getOrigin() << ","
			<< b[i].getDestination() << ","
			<< b[i].getHr_in() << ","
			<< b[i].getHr_out() << ","
			<< b[i].getPrice()
			<< "\n"; 
			printf("lo esta guardando %d\n", b[i].getCode());
	} 
	fin.close(); 
	fout.close(); 
	remove("Bus.csv"); 
	rename("BusTemp.csv", "Bus.csv");
	fin = NULL;
	fout = NULL;
	
	fin.open("Customer.csv", std::ios::in);
	fout.open("CustomerTemp.csv", std::ios::out);
	for (int i = 0; i < c.size(); i++) { 
		fout << c[i].getName() << ", "
			<< c[i].getCC() << ", "
			<< c[i].getCode() 
			<< "\n"; 
	} 
	fin.close();
	fout.close();
	remove("Customer.csv");
	rename("CustomerTemp.csv", "Customer.csv");

} 
