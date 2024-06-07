#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class CVehicle{

	int price;
	int speed;
	int constructionYear;

public:
	CVehicle(int price, int speed, int constructionYear) {
		this->price = price;
		this->speed = speed;
		this->constructionYear = constructionYear;
	}

	virtual int get_Price() {
		return(price);
	}

	virtual int get_Speed() {
		return(speed);
	}

	virtual int getConstruction_year() {
		return(constructionYear);
	}
};

class CPlane : public CVehicle{

	int maxhigh;
	int capacity;

public:
	CPlane(int price, int speed, int construcyionYear, int maxhigh, int capacity) :CVehicle(price, speed, construcyionYear) {
		this->maxhigh = maxhigh;
		this->capacity = capacity;
	}

	int get_Maxhigh() {
		return(maxhigh);
	}

	int get_Capacity() {
		return(capacity);
	}
};

class CCar :public CVehicle {

public:
	CCar(int price, int speed, int construcyionYear) :CVehicle(price, speed, construcyionYear) {}
};

class CShip : public CVehicle {

	int capacity;

public:
	CShip(int price, int speed, int construcyionYear, int capacity) :CVehicle(price, speed, construcyionYear) {
		this->capacity = capacity;
	}

	int get_Capacity() {
		return(capacity);
	}
};

int main() {
	setlocale(LC_ALL, "rus");
	std::vector <CVehicle*> VEC; // implement using std::shared_ptr and std::dynamic_pointer_cast
	int var;
	int var2;
	cout << "Желаете создать новый класс? (0 - нет, 1 - да)" << endl;
	cin >> var;
	while (var != 0) {
		cout << "Какой класс вы желаете создать?" << endl;
		cout << "1 - Самолёт" << endl;
		cout << "2 - Машина" << endl;
		cout << "3 - Корабль" << endl;
		cin >> var2;
		int price, speed, construcyionYear, maxhigh, capacity;
		if (var2 == 1) {
			cout << "Введите цену самолёта" << endl;			
			cout << "Введите скорость самолёта" << endl;			
			cout << "Введите год изготовления самолёта" << endl;			
			cout << "Введите максимальную высоту самолёта" << endl;			
			cout << "Введите вместимость самолёта" << endl;
			cin >> price >> speed >> construcyionYear >> maxhigh >> capacity;
			CPlane Plane1(price, speed, construcyionYear, maxhigh, capacity);
			VEC.push_back(new CPlane(Plane1));
		}
		else if (var2 == 2) {
			cout << "Введите цену машины" << endl;
			cout << "Введите скорость машины" << endl;
			cout << "Введите год изготовления машины" << endl;
			cin >> price >> speed >> construcyionYear;
			CCar Car1(price, speed, construcyionYear);
			VEC.push_back(new CCar(Car1));
		}
		else if (var2 == 3) {
			cout << "Введите цену корабля" << endl;
			cout << "Введите скорость корабля" << endl;
			cout << "Введите год изготовления корабля" << endl;
			cout << "Введите вместимость корабля" << endl;
			cin >> price >> speed >> construcyionYear >> capacity;
			CShip Ship1(price, speed, construcyionYear,  capacity);
			VEC.push_back(new CShip(Ship1));
		}
		cout << "Желаете создать еще один класс? (0 - нет, 1 - да)" << endl;
		cin >> var;
	}	
	cout << "___________________________________________________________________________________" << endl;
	for (int i = 0; i < VEC.size(); ++i) {

		if (dynamic_cast<CPlane*>(VEC[i])) {
			cout << "Number = " << i << " - Самолёт" << endl;
			cout << "Price = " << VEC[i]->get_Price() << endl;
			cout << "Speed = " << VEC[i]->get_Speed() << endl;
			cout << "ConstructionYear = " << VEC[i]->getConstruction_year() << endl;
			cout << "Max Height of Fly = " << dynamic_cast<CPlane*>(VEC[i])->get_Maxhigh() << endl;
			cout << "Max Count of Passengers = " << dynamic_cast<CPlane*>(VEC[i])->get_Capacity() << endl;
			cout << "___________________________________________________________________________________" << endl;
		}
		else if (dynamic_cast<CCar*>(VEC[i])) {
			cout << "Number = " << i << " - Машина" << endl;
			cout << "Price = " << VEC[i]->get_Price() << endl;
			cout << "Speed = " << VEC[i]->get_Speed() << endl;
			cout << "ConstructionYear = " << VEC[i]->getConstruction_year() << endl;
			cout << "___________________________________________________________________________________" << endl;
		}
		else if (dynamic_cast<CShip*>(VEC[i])) {
			cout << "Number = " << i << " - Корабль" << endl;
			cout << "Price = " << VEC[i]->get_Price() << endl;
			cout << "Speed = " << VEC[i]->get_Speed() << endl;
			cout << "ConstructionYear = " << VEC[i]->getConstruction_year() << endl;
			cout << "Max Count of Passengers = " << dynamic_cast<CShip*>(VEC[i])->get_Capacity() << endl;
			cout << "___________________________________________________________________________________" << endl;
		}
	}
}