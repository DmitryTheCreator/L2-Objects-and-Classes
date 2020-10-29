#include "iostream"
#include "conio.h"

//  Создаю класс Car и конструкторы: по умолчанию
//  с параметрами, копирующий и деструктор.
//  get_boost изменяет значения переменных
//  speed, weight
class Car {
public:
	int speed, weight;

	Car() {
		speed = 100;
		weight = 2000;
		printf("Вызван конструктор Car()\n");
		printf("Скорость = %d, Вес = %d\n", speed, weight);
		printf("--------------------------\n");
	}
	Car(int speed, int weight) {
		this->speed = speed;
		this->weight = weight;
		printf("Вызван конструктор Car(int speed, int weight)\n");
		printf("Скорость = %d, Вес = %d\n", speed, weight);
		printf("--------------------------\n");
	}
	Car(const Car& c) {
		speed = c.speed;
		weight = c.weight;
		printf("Вызван конструктор Car(const Car& c)\n");
		printf("Скорость = %d, Вес = %d\n", speed, weight);
		printf("--------------------------\n");
	}
	~Car() {
		printf("Вызван деструктор ~Car()\n");
	}
	void get_boost(float accel, float incr) {
		speed *= accel;
		weight *= incr;
		printf("Вызван метод get_boost(int accel, int incr)\n");
		printf("Скорость = %d, Вес = %d\n", speed, weight);
		printf("--------------------------\n");
	}
	void crash();
};

//  crash наследуется от класса Car, изменяет значения
//  переменных
void Car::crash() {
	speed = 0;
	weight *= 0.6;
	printf("Вызван метод crash()\n");
	printf("Скорость = %d, Вес = %d\n", speed, weight);
	printf("--------------------------\n");
}

//  Класс Bus наследуется от класса Car.
//  Добавляется атрибут price
class Bus : public Car {
public:
	int price;

	Bus() {
		speed = 60;
		weight = 7000;
		price = 30;
		printf("Вызван конструктор Bus()\n");
		printf("Скорость = %d, Вес = %d, Стоимость проезда = %d\n", speed, weight, price);
		printf("--------------------------\n");
	}
	Bus(int speed, int weight, int price) : Car(speed, weight) {
		this->price = price;
		printf("Вызван конструктор Bus(int speed, int weight)\n");
		printf("Скорость = %d, Вес = %d, Стоимость проезда = %d\n", speed, weight, price);
		printf("--------------------------\n");
	}
	Bus(const Bus& b) {
		speed = b.speed;
		weight = b.weight;
		price = b.price;
		printf("Вызван конструктор Bus(const Bus& c)\n");
		printf("Скорость = %d, Вес = %d, Стоимость проезда = %d\n", speed, weight, price);
		printf("--------------------------\n");
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
		printf("--------------------------\n");
	}
};

//  Класс CarPark использует композицию объектов
//  класса Car.
//  total_values суммирует общие атрибуты speed, weight
//  объектов porshe, lamba
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
		printf("--------------------------\n");
	}
	CarPark(int speed, int speed2,  int weight, int weight2) {
		porshe = new Car(speed, weight);
		lamba = new Car(speed2, weight2);
		printf("Вызван конструктор CarPark(int speed, int speed2,  int weight, int weight2)\n");
		printf("Porshe: Скорость = %d, Вес = %d\n", porshe->speed, porshe->weight);
		printf("Lamba: Скорость = %d, Вес = %d\n", lamba->speed, lamba->weight);
		printf("--------------------------\n");
	}
	CarPark(const CarPark& cp) {
		porshe = new Car(*(cp.porshe));
		lamba = new Car(*(cp.lamba));
		printf("Вызван конструктор CarPark(const CarPark& cp)\n");
		printf("Porshe: Скорость = %d, Вес = %d\n", porshe->speed, porshe->weight);
		printf("Lamba: Скорость = %d, Вес = %d\n", lamba->speed, lamba->weight);
		printf("--------------------------\n");
	}
	~CarPark() {
		printf("Вызван деструктор ~CarPark()\n");
		delete porshe;
		delete lamba;
	}
	void total_values() {
		int t_speed, t_weight;
		t_speed = (porshe->speed) + (lamba->speed);
		t_weight = (porshe->weight) + (lamba->weight);
		printf("Вызван метод total_values()\n");
		printf("Общая скорость = %d\n", t_speed);
		printf("Общий вес = %d\n", t_weight);
		printf("--------------------------\n");
	}
};

int main() {
	setlocale(LC_ALL, "");
	{
		printf("Взаимодействие с классом Car\n");
		printf("==========================\n");
		{
			Car lada;
			Car* porsh = new Car(130, 3000);
			Car* lamba = new Car(*porsh);
			delete porsh;
			delete lamba;
		}
		printf("==========================\n");
		printf("\n\n");
		printf("Взаимодействие с классом Bus\n");
		printf("==========================\n");
		{
			Bus uaz(50, 8000, 30);
			Bus* monstr = new Bus();
			Car* quadbike = new Bus(uaz);
			delete monstr;
			delete quadbike;
		}
		printf("==========================\n");
		printf("\n\n");	
		printf("Вызов методов констуктора Bus\n");
		printf("==========================\n");
		{
			Bus autobus;
			autobus.get_boost(1.3, 1.5, 3.2);
			Car* mashina = new Car(150, 2500);
			mashina->get_boost(2.3, 1.2);
			mashina->crash();
			delete mashina;
		}
		printf("==========================\n");
		printf("\n\n");
		printf("Взаимодействие с классом CarPark\n");
		printf("==========================\n");
		{			
			CarPark* cars = new CarPark();
			CarPark autos(220, 230, 1500, 1600);
			autos.total_values();
			delete cars;
		}
		printf("==========================\n");

		_getch();
	}
}
