#include "Libreria.hpp"
template <typename T1, typename T2>
class HashEntidad {
private:
	T1 key;
	T2 value;
public:
	HashEntidad(T1 key, T2 value): key(key), value(value) {}
	T1 getKey() { return key; }
	T2& getValue() { return value; }
	void SetKey(T1 key) { this->key= key; }

};

