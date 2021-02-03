#include "File.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

File::File(){
	std::fstream fin;
	fin.open("Bus.csv", std::ios::in);
	if(fin.is_open()) {
		flag = true;
	}else{
		flag = false;
	}
	fin.close();
}
void File::getText(std::vector<Bus> &b, std::vector<Customer> &c) { 
	std::fstream fin; 
	fin.open("Bus.csv", std::ios::in);  
	std::vector<std::string> row; 
	std::string line, word, temp; 
	Bus Temp;
	Customer temp2;
	while (!fin.eof()) { 
		row.clear(); 
		getline(fin, line); 
		std::stringstream s(line); 
		while (std::getline(s, word, ',')) { 
            row.push_back(word); 
        }
		Temp.setCode(row[0]);
		Temp.setSeat(std::stoi(row[1]));
		Temp.setOrigin(row[2]);
		Temp.setDestination(row[3]);
		Temp.setHr_in(row[4]);
		Temp.setHr_out(row[5]);
		Temp.setPrice(std::stod(row[6]));
		b.push_back(Temp);	
	}
	fin.close();
	fin.open("Customer.csv", std::ios::in);
	while (!fin.eof()) { 
		row.clear(); 

		getline(fin, line); 

		std::stringstream s2(line); 
		while (std::getline(s2, word, ',')) { 
            row.push_back(word); 
        }
		temp2.setName(row[0]);
		temp2.setCode(row[1]);
		temp2.setCC(row[2]);
		c.push_back(temp2);	
	}
	fin.close();
} 

void File::create(std::vector<Bus> b, std::vector<Customer> c){ 
	std::fstream fout; 
	fout.open("Bus.csv", std::ios::out | std::ios::app);
	if(!flag) {
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
	} 
	fin.close(); 
	fout.close(); 
	remove("Bus.csv"); 
	rename("BusTemp.csv", "Bus.csv");
	
	fin.open("Customer.csv", std::ios::in);
	fout.open("CustomerTemp.csv", std::ios::out);
	for (int i = 0; i < c.size(); i++) {
		fout << c[i].getName() << ","
			<< c[i].getCC() << ","
			<< c[i].getCode() 
			<< "\n"; 
	} 
	fin.close();
	fout.close();
	remove("Customer.csv");
	rename("CustomerTemp.csv", "Customer.csv");

} 
