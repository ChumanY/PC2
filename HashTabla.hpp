#include "HashEntidad.hpp"   
template <typename T1,typename T2>

class HashTabla {
private:
	HashEntidad<T1,T2>** ht;
    int numElementos;
	int TABLE_SIZE;
    
 
public:
	HashTabla(int TABLE_SIZE = 5000) {
		this->TABLE_SIZE = TABLE_SIZE;
		ht = new HashEntidad<T1, T2>* [TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; ++i) {
			ht[i] = nullptr;
		}
		numElementos = 0;
	}
	//Direccionamiento según Prueba Lineal
    void insert(T1 key, T2 value) {
		//Hash prima
		int base, step, hash;
		//validar si la tabla está llena
		if (numElementos == TABLE_SIZE)return;
		//Función Hash1
		base = key % TABLE_SIZE;
		hash = base;
		//constante para Hash2
		step = 0;
		while (ht[hash] != nullptr)
		{
			//Función Hash2
			hash = (base + step) % TABLE_SIZE;
			step++;
		}
		//almacenarlo en la tabla
		ht[hash] = new HashEntidad<T1, T2>(key, value);
		numElementos++;
	}

	void imprimirTablaHash() {
		cout << "SIZE TABLA: " << TABLE_SIZE << endl;
		cout << "SIZE ACTUAL: " <<numElementos << endl;
		for (int i = 0; i < TABLE_SIZE; ++i) {
			cout <<ht[i]->getKey()+1<<" ---> "<<ht[i]->getValue()  <<endl;
			
		}
	}
    int buscar(int key) {
		int step = 0;
		int i,base;
		// //i=base=key% TABLE_SIZE;
		 i  =base= key;//% TABLE_SIZE; //hash1 es = a hash2 cuando step=0;
		while (true)
		{
			if (ht[key] == nullptr){
                cout<<"Esta key no tiene value";
                return -1;
                
            }
		 	else if (ht[i]->getKey() == key) {
		 		return i;
		 	}
		 	else step++;

		 	i = (base + step) % TABLE_SIZE;
		 }
		
	}

	////////METODOS IMPLEMENTADOS////////


	void Find_if(int value){  // Big (O) detallado ---------> 12n+4
		vector<int> myvector; //1
		int age,cnt=0; // int age =1 , int cnt=0 ;1  -> 2
 		for(int i=0;i<TABLE_SIZE;++i)  // 1+n(12)
		 {
			//2
			age=ht[i]->getValue().GetAge(); // 1
			myvector.push_back(age);        // 1
			if(myvector.at(i)==value) //2 + max -> 6
			{
				cout<<ht[i]->getKey()+1<<" ---> "<<ht[i]->getValue()<<endl;         //4
				++cnt;                                                              //1
				cout<<"El valor se encuentra en la key: "<<ht[i]->getKey()+1<<endl; //3
			}
		}
	}

	void Search_n(int exp){   // Big (O) detallado ---------> 16n+4
		vector<int> myvector,mycopy; //2
		int experience;//1
		for(int i=0;i<TABLE_SIZE;++i)//1+ n(16)
			{
				//2
				experience=ht[i]->getValue().GetExperience();//2
				myvector.push_back(experience);//1
				mycopy.push_back(experience);//1
				reverse( mycopy.begin(), mycopy.end() );//1
				if(myvector.at(i)==exp && myvector.at(i)==mycopy.at(i)){ // 5 + 4
					cout<<ht[i]->getKey()+1<<" ---> "<<ht[i]->getValue()<<endl;	//4
					cout<<"El valor se encuentra en la key: "<<ht[i]->getKey()+1<<endl;//3
				}
			}

	}
	
	void Transform(){         // Big (O) detallado ---------> 16n+5
		vector<int> myvector;//1
		int members,maxm,modmembers;//3
		for(int i=0;i<TABLE_SIZE;++i)//1 +n(11)
			{
				//2
				members=ht[i]->getValue().GetFamily();//1
				myvector.push_back(members);//1
				if(myvector.at(i)>3){ //2 + max=5
					cout<<ht[i]->getKey()+1<<" ---> "<<ht[i]->getValue()<<endl;	//4
					maxm=members-2;//2
					cout<<"Valor max es 2, su valor deberia ser como maximo: "<<endl;//2
					ht[i]->getValue().SetFamily(maxm);//1
					cout<<ht[i]->getKey()+1<<" ---> "<<ht[i]->getValue()<<endl<<endl;	//5
				}
			}
	}

	void Is_Permutation(){    // Big (O) detallado ---------> 12n+5
		vector<int> myvector,mycopy;//2
		int experience,id;//2
		for(int i=0;i<TABLE_SIZE;++i) // 1+n(12)
		{
			//2
			experience=ht[i]->getValue().GetExperience();//1
			id=ht[i]->getValue().GetID();//1
			myvector.push_back(experience);//1
			mycopy.push_back(id);//1
			if( myvector.at(i)==mycopy.at(i))//3 +max=3
			{
				cout<<"Se encuentran los mismos valores en experience y value en: "<<ht[i]->getKey()<<endl;//3
			}		
		}		
	}
	
	void Find_first_of(){     // Big (O) detallado ---------> 15n+8
		vector<int> myvector,mycopy;//2
		int creditcard, online,cnt=0;//3
		for(int i=0;i<TABLE_SIZE;++i)//1+n(15)
		{
			//2
			creditcard=ht[i]->getValue().GetCreditcard();//1
			online=ht[i]->getValue().GetOnline();//1
			myvector.push_back(creditcard);//1
			mycopy.push_back(online);//1
			if(myvector.at(i)==1 && mycopy.at(i)==1){//5+max=4
				cout<<ht[i]->getKey()+1<<" ---> "<<ht[i]->getValue()<<endl;	//4
				++cnt;//2
			}			
		}
		cout<<"Se han encontrado "<<cnt<<" parejas con valor comun entre creditcard y online";//3
	}
	
	void For_each(){          // Big (O) detallado ---------> 10n+6
		vector<int> myvector;//1
		int zip;//1
		int cnt=0;//1
		for(int i=0;i<TABLE_SIZE;++i)//1+n(10)
		{
			//2
			zip=ht[i]->getValue().GetZip();//1
			myvector.push_back(zip);//1
			cout<<ht[i]->getKey()+1<<" ---> "<<ht[i]->getValue()<<endl;	//4
			++cnt;//2
		}
		cout<<"La cantidad de datos es de: "<<cnt;//2
	}

	void Random_shuffle(){    // Big (O) detallado ---------> 17n+4
		vector<int> myvector;//1
		int key;//1
		int cnt=0;//1
		for(int i=0;i<50;++i)//1+n(17)
		{
			//2
			cout<<ht[i]->getKey()+1<<" ---> "<<ht[i]->getValue()<<endl;//4
			key=ht[i]->getKey()+rand()%50+1;//4
			ht[i]->SetKey(key);//1
			cout<<"Nueva posicion: "<<endl;	//2
			cout<<ht[i]->getKey()+1<<" ---> "<<ht[i]->getValue()<<endl;	//4
		}
		

	}
};
