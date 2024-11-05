#include <iostream>
#include <memory>
#include <string>
#include <windows.h>
using namespace std;

// Базовий інтерфейс для транспорту
class Transport {
public:
    virtual void deliver() const = 0;
    virtual ~Transport() = default;
};

// Клас для автомобіля
class Car : public Transport {
public:
    void deliver() const override {
        cout << "Доставка автомобілем" << endl;
    }
};

// Клас для велосипеда
class Bike : public Transport {
public:
    void deliver() const override {
        cout << "Доставка велосипедом" << endl;
    }
};

// Базовий інтерфейс для водіїв
class Driver {
public:
    virtual void drive() const = 0;
    virtual ~Driver() = default;
};

// Клас водія для автомобіля
class CarDriver : public Driver {
public:
    void drive() const override {
        cout << "Керування автомобілем" << endl;
    }
};

// Клас водія для велосипеда
class BikeDriver : public Driver {
public:
    void drive() const override {
        cout << "Керування велосипедом" << endl;
    }
};

// Абстрактна фабрика для створення транспортних засобів і водіїв
class TransportFactory {
public:
    virtual unique_ptr<Transport> createTransport() const = 0;
    virtual unique_ptr<Driver> createDriver() const = 0;
    virtual ~TransportFactory() = default;
};

// Фабрика для автомобілів і водіїв автомобілів
class CarFactory : public TransportFactory {
public:
    unique_ptr<Transport> createTransport() const override {
        return make_unique<Car>();
    }

    unique_ptr<Driver> createDriver() const override {
        return make_unique<CarDriver>();
    }
};

// Фабрика для велосипедів і велосипедистів
class BikeFactory : public TransportFactory {
public:
    unique_ptr<Transport> createTransport() const override {
        return make_unique<Bike>();
    }

    unique_ptr<Driver> createDriver() const override {
        return make_unique<BikeDriver>();
    }
};

// Функція для роботи з фабрикою
void deliverAndDrive(const TransportFactory& factory) {
    auto transport = factory.createTransport();
    auto driver = factory.createDriver();
    transport->deliver();
    driver->drive();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    CarFactory carFactory;
    BikeFactory bikeFactory;

    cout << "Фабрика автомобілів:" << endl;
    deliverAndDrive(carFactory);

    cout << "Фабрика велосипедів:" << endl;
    deliverAndDrive(bikeFactory);

}
