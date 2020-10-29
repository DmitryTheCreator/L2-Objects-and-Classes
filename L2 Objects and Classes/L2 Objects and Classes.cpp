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
		printf("Скорость машины = %d, Вес машины = %d\n", speed, weight);
	}
	Car(int speed, int weight) {
		this->speed = speed;
		this->weight = weight;
		printf("Вызван конструктор Car(int speed, int weight)\n");
		printf("Скорость машины = %d, Вес машины = %d\n", speed, weight);
	}
	Car(const Car& c) {
		speed = c.speed;
		weight = c.weight;
		printf("Вызван конструктор Car(const Car& c)\n");
		printf("Скорость машины = %d, Вес машины = %d\n", speed, weight);
	}
	~Car() {
		printf("Вызван дестуктор ~Car()\n");
		//printf("Скорость машины = %d, Вес машины = %d\n", speed, weight);
	}
};

int main() {
	setlocale(LC_ALL, "");
	{
		Car lada;
		Car* porsh = new Car(100, 3000);
		Car* lamba = new Car(*porsh);
		
		delete porsh;
		delete lamba;
	}
}
