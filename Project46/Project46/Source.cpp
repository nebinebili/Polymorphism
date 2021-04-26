#include<iostream>
#include<vector>
using namespace std;

class Car {
protected:
	string name;
	int year;
	Car() :name(), year() {};
	Car(const string name,const int year)
	{
	  SetName(name);
	  SetYear(year);
	}
public:
	string GetName() {
		return name;
	}
	int GetYear() {
		return year;
	}
	void SetName(const string name) {
		if (name != "")
		this->name = name;
	}
	void SetYear(const int year) {
		if (year > 0)
		this->year = year;
	}

	virtual void Show() {
		cout << "Name->" << name << endl;
		cout << "Year->" << year << endl;
		
	}
};

class Manual: public Car{
	string shiftFork;
public:
	Manual() :shiftFork() {};
	
	Manual(const string name,const int year,const string shiftFork)
	 :Car(name,year)
	{
	  SetshiftFork(shiftFork);
	}
	string GetshiftFork() {
		return shiftFork;
	}
	void SetshiftFork(const string shiftFork) {
		if (shiftFork != " ")
		this->shiftFork = shiftFork;
	}

	void Show() {
		Car::Show();
		cout << "Shift Fork->" << shiftFork << endl;
	}

};

class Automatic:public Car {
	string brakeBand;
public:
	Automatic() :brakeBand() {};

	Automatic(const string name, const int year, const string brakeBand)
		:Car(name, year)
	{
		SetbrakeBand(brakeBand);
	}
	string GetbrakeBand() {
		return brakeBand;
	}
	void SetbrakeBand(const string brakeBand) {
		if (brakeBand != " ")
			this->brakeBand = brakeBand;
	}

	void Show() {
		Car::Show();
		cout << "Brake Band->" << brakeBand << endl;
	}
};

class BMW:public Automatic{
	string bmwlyuk;
public:
	BMW() :bmwlyuk() {};
	BMW(const string name,const int year,const string brakeBand,const string bmwlyuk)
	 :Automatic(name,year,brakeBand)
	{
		SetBmwLyuk(bmwlyuk);
	}
	string GetBmwLyuk(){
		return bmwlyuk;
	}
	void SetBmwLyuk(const string bmwlyuk){
		if (bmwlyuk != " ")
		this->bmwlyuk = bmwlyuk;
	}
	void Show() {
		Automatic::Show();
		cout << "Bmw Lyuk->" << bmwlyuk << endl << endl;
	}
};

class Vaz:public Manual {
	bool hasPionerKalonka;
public:
	Vaz() :hasPionerKalonka() {};
	Vaz(const string name,const int year,const string shiftFork,const bool hasPionerKalonka)
		:Manual(name,year,shiftFork)
	{
		SetHasPionerKalonka(hasPionerKalonka);
	}
	bool GetHasPionerKalonka() {
		return hasPionerKalonka;
	}
	void SetHasPionerKalonka(const bool hasPionerKalonka) {
		this->hasPionerKalonka = hasPionerKalonka;
	}
	void Show() {
		Manual::Show();
		if (hasPionerKalonka == true) {
		  cout << "Has Pioneer Kalonka->Yes" <<endl;
		}
		else
			cout << "Has Pioneer Kalonka->NO" << endl;
	}
};

void report(Car& car) {
	car.Show();
}

int main() {
	BMW b("BMW X7", 2019, "Orginal BMW AX bearing", "X7 lyuk");
	Vaz v("vaz 2107", 2009, "shift fork for gearbox for Vaz", true);
	
	vector<Car*>cars;
	cars.push_back(&b);
	cars.push_back(&v);

	for (int i = 0; i < cars.size(); i++)
	{
		report(*cars[i]);
	}

	return EXIT_SUCCESS;
}