#include "iostream"
#include "conio.h"

class Car {
public:
	int speed, weight;
public:
	Car() {
		speed = 100;
		weight = 2000;
		printf("Вызван конструктор Car()\n");
		printf("Скорость = %d, Вес = %d\n", speed, weight);
	}
	Car(int speed, int weight) {
		this->speed = speed;
		this->weight = weight;
		printf("Вызван конструктор Car(int speed, int weight)\n");
		printf("Скорость = %d, Вес = %d\n", speed, weight);
	}
	Car(const Car& c) {
		speed = c.speed;
		weight = c.weight;
		printf("Вызван конструктор Car(const Car& c)\n");
		printf("Скорость = %d, Вес = %d\n", speed, weight);
	}
	~Car() {
		printf("Вызван деструктор ~Car()\n");
	}
	void get_boost(float accel, float incr) {
		speed *= accel;
		weight *= incr;
		printf("Вызван метод get_boost(int accel, int incr)\n");
		printf("Скорость = %d, Вес = %d\n", speed, weight);
	}
	void crash();
};

void Car::crash() {
	speed = 0;
	weight *= 0.6;
	printf("Вызван метод crash()\n");
	printf("Скорость = %d, Вес = %d\n", speed, weight);
}

class Bus : public Car {
protected:
	int price;
public: 
	Bus() {
		speed = 60;
		weight = 7000;
		price = 30;
		printf("Вызван конструктор Bus()\n");
		printf("Скорость = %d, Вес = %d, Стоимость проезда = %d\n", speed, weight, price);
	}
	Bus(int speed, int weight, int price) : Car(speed, weight) {
		this->price = price;
		printf("Вызван конструктор Bus(int speed, int weight)\n");
		printf("Скорость = %d, Вес = %d, Стоимость проезда = %d\n", speed, weight, price);
	}
	Bus(const Bus& b) {
		speed = b.speed;
		weight = b.weight;
		price = b.price;
		printf("Вызван конструктор Bus(const Bus& c)\n");
		printf("Скорость = %d, Вес = %d, Стоимость проезда = %d\n", speed, weight, price);
	}
	~Bus() {
		printf("Вызван деструктор ~Bus()\n");
	}
	void get_boost(float accel, float incr, float infl) {
		speed *= accel;
		weight *= incr;
		price *= infl;
		printf("Вызван метод get_boost(int accel, int incr, int infl)\n");
		printf("Скорость = %d, Вес = %d, Стоимость проезда = %d\n", speed, weight, price);
	}
};

class CarPark {
public:
	Car* porshe;
	Car* lamba;

	CarPark() {
		porshe = new Car();
		lamba = new Car();
		printf("Вызван конструктор CarPark()\n");
		printf("Porshe: Скорость = %d, Вес = %d\n", porshe->speed, porshe->weight);
		printf("Lamba: Скорость = %d, Вес = %d\n", lamba->speed, lamba->weight);
	}
	CarPark(int speed, int speed2,  int weight, int weight2) {
		porshe = new Car(speed, weight);
		lamba = new Car(speed2, weight2);
		printf("Вызван конструктор CarPark(int speed, int speed2,  int weight, int weight2)\n");
		printf("Porshe: Скорость = %d, Вес = %d\n", porshe->speed, porshe->weight);
		printf("Lamba: Скорость = %d, Вес = %d\n", lamba->speed, lamba->weight);
	}
	CarPark(const CarPark& cp) {
		porshe = new Car(*(cp.porshe));
		lamba = new Car(*(cp.lamba));
		printf("Вызван конструктор CarPark(const CarPark& cp)\n");
		printf("Porshe: Скорость = %d, Вес = %d\n", porshe->speed, porshe->weight);
		printf("Lamba: Скорость = %d, Вес = %d\n", lamba->speed, lamba->weight);
	}
	~CarPark() {
		printf("Вызван деструктор ~CarPark()\n");
	}
};

int main() {
	setlocale(LC_ALL, "");
	{
		{
			Car lada;
			Car* porsh = new Car(130, 3000);
			Car* lamba = new Car(*porsh);
			delete porsh;
			delete lamba;
		}
		
		printf("\n\n");

		{
			Bus uaz(50, 8000, 30);
			Bus* monstr = new Bus();
			Bus* quadbike = new Bus(uaz);
			delete monstr;
			delete quadbike;
		}

		printf("\n\n");	

		{
			Bus autobus;
			autobus.get_boost(1.3, 1.5, 3.2);
			Car* mashina = new Car(150, 2500);
			mashina->get_boost(2.3, 1.2);
			mashina->crash();
			delete mashina;
		}

		printf("\n\n");

		{
			CarPark autos(220, 230, 1500, 1600);
			CarPark* cars = new CarPark();
			delete cars;
		}

	}
}
