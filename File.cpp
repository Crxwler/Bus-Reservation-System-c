#include "File.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

File::File(){
	//printf("Verifico Archivo\n");
	std::fstream fin;
	fin.open("Bus.csv", std::ios::in);
	if(fin.is_open()) {
		flag = true;
		//printf("Verdaddero\n");
	}else{
		//printf("File not found, No schedule\n");
		flag = false;
		//printf("Falso\n");
	}
	fin.close();
}
//getData from csv to vector 
void File::getText(std::vector<Bus> &b, std::vector<Customer> &c) { 
	//File();
	std::fstream fin; 
	fin.open("Bus.csv", std::ios::in);  
	
	std::vector<std::string> row; 
	std::string line, word, temp; 
	Bus Temp;
	Customer temp2;
	//printf("Valor flag %d\n", flag);
	while (!fin.eof()) { 
		//printf("Si obtiene datos\n");
		//printf("Valor flag %d\n", flag);
		row.clear(); 

		getline(fin, line); 

		std::stringstream s(line); 
		while (std::getline(s, word, ',')) { 
			//printf("palabra %s\n", word);
			//std::cout << "Palabra "<< word;
            row.push_back(word); 
        }
		Temp.setCode(row[0]);
		Temp.setSeat(std::stoi(row[1]));
		Temp.setOrigin(row[2]);
		Temp.setDestination(row[3]);
		Temp.setHr_in(row[4]);
		Temp.setHr_out(row[5]);
		Temp.setPrice(std::stod(row[6]));
		//std::cout << "codigo guardado "<< Temp.getCode()<< "\n";
		b.push_back(Temp);	
	}
	//delete *Temp;
	fin.close();
	fin = NULL;
	fin.open("Customer.csv", std::ios::in);
	//std::cout << "Customer size "<< c.size()<< "n";
	//printf("\n"); 
	while (!fin.eof()) { 
		//printf("Si obtiene datos\n");
		//printf("Valor flag %d\n", flag);
		row.clear(); 

		getline(fin, line); 

		std::stringstream s2(line); 
		while (std::getline(s2, word, ',')) { 
			//printf("palabra %s\n", word);
			//std::cout << "Palabra "<< word;
            row.push_back(word); 
        }
        //printf("\n");
		temp2.setName(row[0]);
		temp2.setCode(row[1]);
		temp2.setCC(row[2]);
		//std::cout << "codigo guardado "<< temp2.getCode()<< "\n";
		c.push_back(temp2);	
	}
	fin.close();
	//delete *temp2;
	
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
	//printf("Lo guardooo!!\n");
	std::fstream fin, fout; 
	fin.open("Bus.csv", std::ios::in); 
	fout.open("BusTemp.csv", std::ios::out); 
	//std::cout << "Size of bus" << b.size()<< "\n";
	for (int i = 0; i < b.size(); i++) { 
		//if (i == b.size()-1)
		//	continue;
		fout << b[i].getCode() << ","
			<< b[i].getSeat() << ","
			<< b[i].getOrigin() << ","
			<< b[i].getDestination() << ","
			<< b[i].getHr_in() << ","
			<< b[i].getHr_out() << ","
			<< b[i].getPrice()
			<< "\n"; 
			//printf("lo esta guardando %d\n", b[i].getCode());
			//std::cout<< "lo esta guardando"<< b[i].getCode()<<"\n";	
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
		//if (i == c.size()-1)
		//	continue;
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
