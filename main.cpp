#include "Dataset.hpp"

auto run=[](Dataset ds){ds.readCSV();ds.metodos();};
int main(){

	Dataset ds;

	//ds.readCSV();
	//ds.Comprobacion();
	//Sleep(10000);
	//system("cls");
	//ds.print();
	//ds.metodos();
	
	run(ds);
	cin.get();
    return 0;
}