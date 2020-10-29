#include "iostream"
#include "conio.h"

class Car {
protected:
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
		printf("Вызван дестуктор ~Car()\n");
	}
};

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
		printf("Вызван дестуктор ~Bus()\n");
	}

};

int main() {
	setlocale(LC_ALL, "");
	{
		Car lada;
		Car* porsh = new Car(130, 3000);
		Car* lamba = new Car(*porsh);
		
		printf("\n\n");

		Bus uaz(50, 8000, 30);
		Bus* uazik = new Bus();
		Bus* uazblin = new Bus(uaz);

		printf("\n\n");

		delete porsh;
		delete lamba;
		delete uazik;
		delete uazblin;
	}
}
