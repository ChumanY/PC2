#include "Persona.hpp"
#include "HashTabla.hpp"
class Dataset {
	HashTabla<int,Persona> personas;

public:

	Dataset() {
		readCSV("Bank_Personal_Loan_Modelling.csv");
	}
	
	void readCSV(string name = "", bool header = true) {//campos separados por comas
		ifstream file(name);
        string reg;
		int id, age, experience, income, family,education, mortgage, ploan, securities,cd, online, creditcard;
        long zip;
        float  ccavrg;
		if (header)
			getline(file, reg);
		while (file>>id>>age>>experience>>income>>zip>>family>>ccavrg>>
                education>>mortgage>>ploan>>securities>>cd>>online>>creditcard) {
			personas.insert(rand() % 5000, Persona(id,age,experience,income,zip,family,ccavrg,education,mortgage,ploan,securities,cd,online,creditcard));
		}
	}
	
	void print() {
		personas.imprimirTablaHash();	
	}

	void metodos()
	{	
		int seleccion;
		bool terminar =false;
		do  //garantizamos que al menos se ejecute una vez nuestro código
	{
		cout<<endl<<"Menu de implementacion de metodos:"<<endl;
		cout << "(1) Find If" << endl;
		cout << "(2) Search n" << endl;
		cout << "(3) Transform" << endl;
		cout << "(4) Is permutation" << endl;
		cout << "(5) Find first of" << endl;
		cout << "(6) For each" << endl;
		cout << "(7) Random Shuffle" << endl;
		cout << "(0) Salir" << endl;
		cin >> seleccion;
		system ("cls");
		switch (seleccion) {
		case 1:{
			// cout<<"Ingrese la edad que desea buscar:"<<endl;
			// cin>>n;
			int n=38;
			personas.Find_if(n);
			break;
		}
		case 2: {
			// cout<<"Ingrese la cantidad de experiencia que busca:"<<endl;
			// cout<<"Se considerada valida la experiencia si se encuentran a dos personas con aquella cantidad"<<endl;
			// cin>>n;
			int n=20;
			personas.Search_n(n);
			// prueba 20 - 18
			break;
		}
		case 3: {
			personas.Transform();
			break;
		}
		case 4: {
			personas.Is_Permutation();
			break;
		}
		case 5: {
			
			personas.Find_first_of();
			break;
		}
		case 6: {
			personas.For_each();
			break;
		}
		case 7: {
			personas.Random_shuffle();
			break;
		}
		case 0: {
			terminar = true;
			break;
		}
		default: {
			cout << "Opción no válida, vuelve a intentarlo" << endl;
			break;
		}
		} //Fin de switch
	} //fin de do
	while (not terminar); //Repite el ciclo hasta presionar 0

		
	}
	


};
