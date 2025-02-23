#include "Dato.h"
#include <iostream>
using namespace std;
Dato::Dato() {}

Dato::Dato(int d) {
	dato = d;
}

int Dato::getDato() {
	return dato;
}

int Dato::getAar() {
	return dato / 10000;
}

int Dato::getMaaned() {
	return (dato % 10000) / 100;
}

int Dato::getDag() {
	return dato % 100;
}

int Dato::getKvartal() {
	return (getMaaned() - 1) / 3 + 1;
}

void Dato::setAar(int a) {
	int currentAar = getAar();

	int differenceInAar = a - currentAar;

	dato += differenceInAar * 10000;

	if (validDato() == false) {
		cout << "Invalid dato" << endl;
		dato -= differenceInAar * 10000;
	}
}

void Dato::setMaaned(int m) {

	int currentMaaned = getMaaned();

	int differenceInMaaned = m - currentMaaned;

	dato += differenceInMaaned * 100;

	if (validDato() == false) {
		cout << "Invalid dato" << endl;
		dato -= differenceInMaaned * 100;
	}
}

void Dato::setDag(int d) {
	int currentDag = getDag();

	int differenceInDag = d - currentDag;

	dato += differenceInDag;

	if(validDato() == false) {
		cout << "Invalid dato" << endl;
		dato -= differenceInDag;
	}
}

bool Dato::skudAar() {
	int aar = getAar();

	if ((aar % 4 == 0 && aar % 100 != 0) || aar % 400 == 0) {
		return true;
	}
	return false;
}

bool Dato::validDato() {
	int aar = getAar();
	int maaned = getMaaned();
	int dag = getDag();

	int daysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	if(skudAar()) {
		daysInMonth[1] = 29;
	}

	if(dato < 17000301){
		return false;
	}

	if (maaned < 1 || maaned > 12) {
		return false;
	}

	if (dag < 1 || dag > daysInMonth[maaned - 1]) {
		return false;
	}

	return true;
}

int Dato::dagIAar() {
	int maaned = getMaaned();
	int dag = getDag();

	int daysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	if(skudAar()) {
		daysInMonth[1] = 29;
	}

	int days = 0;

	for (int i = 0; i < maaned - 1; i++) {
		days += daysInMonth[i];
	}

	days += dag;

	return days;
}

int Dato::restDageIAar() {
	int aarLength = skudAar() ? 366 : 365;

	return aarLength - dagIAar();
}

void Dato::setDatoPlusEn() {
	int dag = getDag();
	int maaned = getMaaned();

	int daysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	if(skudAar()) {
		daysInMonth[1] = 29;
	}

	if (dag == 31 && maaned == 12) {
		dato = (getAar() + 1) * 10000 + 101;
	}
	else if (dag == daysInMonth[maaned - 1]) {
		setMaaned(maaned + 1);
		setDag(1);
	}
	else {
		setDag(dag + 1);
	}
}

void Dato::setDatoMinusEn() {
	int dag = getDag();
	int maaned = getMaaned();

	int daysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	if (skudAar()) {
		daysInMonth[1] = 29;
	}

	if (dag == 1 && maaned == 1) {
		dato = (getAar() - 1) * 10000 + 1231;
	}
	else if (dag == 1) {
		setMaaned(maaned - 1);
		setDag(daysInMonth[maaned - 2]);
	}
	else {
		setDag(dag - 1);
	}
}

void Dato::setNyDato(int d) {
	int oldDate = dato;
	
	dato = d;

	if (validDato() == false) {
		cout << "Invalid dato" << endl;
		dato = oldDate;
	}
}

int Dato::forskelIDage(Dato d) {
	int nyDatoAar = d.getAar();
	int gammelDatotAar = getAar();

	if(nyDatoAar == gammelDatotAar) {
		return d.dagIAar() - dagIAar();
	}
	else {
		int days = restDageIAar();
		days += d.dagIAar();

		while (d.getAar() != getAar()) {
			if(d.skudAar()) {
				days += 366;
			}
			else {
				days += 365;
			}
			d.setAar(d.getAar() - 1);
		}

		days += d.dagIAar() - dagIAar();

		return days;
	}
}



Dato::~Dato() {}