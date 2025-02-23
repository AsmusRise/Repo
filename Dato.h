#pragma once
using namespace std;

class Dato{
public:
	Dato();
	Dato(int);
	
	int getDato();
	int getAar();
	int getMaaned();
	int getDag();
	int getKvartal();
	
	void setAar(int);
	void setMaaned(int);
	void setDag(int);
	
	bool skudAar();
	bool validDato();
	
	int dagIAar();
	int restDageIAar();

	void setDatoPlusEn();
	void setDatoMinusEn();
	void setNyDato(int);

	int forskelIDage(Dato);

	int ugeDag();

	~Dato();

private:
	int dato; //YYYYMMDD

};

