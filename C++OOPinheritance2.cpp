#include <iostream>
using namespace std;

template<typename T>
class Stack {
private:
    T data[100];
    int top;
public:
    Stack() {
        top = -1;
    }
    void push(T item) {
        if (top < 99) {
            top++;
            data[top] = item;
        }
    }
    bool isEmpty() {
        return top == -1;
    }
    T get(int index) {
        if (index >= 0 && index <= top)
            return data[index];
        return T();
    }
    int size() {
        return top + 1;
    }
};

class Engine {
public:
    string engine_no;
    string company;
    double volume;

    Engine() {}

    Engine(string no, string comp, double vol) {
        engine_no = no;
        company = comp;
        volume = vol;
    }

    void show() {
        cout << "Engine No: " << engine_no << endl;
        cout << "Company: " << company << endl;
        cout << "Volume: " << volume << " L" << endl;
    }
};

class Vehicle {
public:
    int id;
    string model;
    string vendor;
    Engine engine;

    Vehicle() {}

    Vehicle(int _id, string _model, string _vendor, Engine _engine) {
        id = _id;
        model = _model;
        vendor = _vendor;
        engine = _engine;
    }

    virtual void show() {
        cout << "ID: " << id << endl;
        cout << "Model: " << model << endl;
        cout << "Vendor: " << vendor << endl;
        engine.show();
    }
};

class Car : public Vehicle {
public:
    bool hasSpoiler;

    Car() {}

    Car(int id, string model, string vendor, Engine engine, bool spoiler)
        : Vehicle(id, model, vendor, engine) {
        hasSpoiler = spoiler;
    }

    void show() override {
        cout << "---- Car ----" << endl;
        Vehicle::show();
        cout << "Has Spoiler? - " << (hasSpoiler ? "Yes" : "No") << endl;
    }
};

class Ship : public Vehicle {
public:
    bool hasSail;

    Ship() {}

    Ship(int id, string model, string vendor, Engine engine, bool sail)
        : Vehicle(id, model, vendor, engine) {
        hasSail = sail;
    }

    void show() override {
        cout << "---- Ship ----" << endl;
        Vehicle::show();
        cout << "Has Sail? - " << (hasSail ? "Yes" : "No") << endl;
    }
};

class Airplane : public Vehicle {
public:
    int engineCount;
    int passengersCapacity;

    Airplane() {}

    Airplane(int id, string model, string vendor, Engine engine, int count, int capacity)
        : Vehicle(id, model, vendor, engine) {
        engineCount = count;
        passengersCapacity = capacity;
    }

    void show() override {
        cout << "---- Airplane ----" << endl;
        Vehicle::show();
        cout << "Engine Count: " << engineCount << endl;
        cout << "Passenger Capacity: " << passengersCapacity << endl;
    }
};

class VehicleDepo {
public:
    Stack<Car> cars;
    Stack<Ship> ships;
    Stack<Airplane> airplanes;

    void showAllVehicle() {
        cout << "\n===== Cars =====" << endl;
        for (int i = 0; i < cars.size(); i++) {
            cars.get(i).show();
            cout << "----------------\n";
        }

        cout << "\n===== Ships =====" << endl;
        for (int i = 0; i < ships.size(); i++) {
            ships.get(i).show();
            cout << "----------------\n";
        }

        cout << "\n===== Airplanes =====" << endl;
        for (int i = 0; i < airplanes.size(); i++) {
            airplanes.get(i).show();
            cout << "----------------\n";
        }
    }
};

void main() {
    VehicleDepo depo;

    Engine e1("E101", "BMW", 3.0);
    Engine e2("S202", "Yamaha", 2.5);
    Engine e3("A303", "Rolls Royce", 5.0);

    depo.cars.push(Car(1, "M5", "BMW", e1, true));
    depo.ships.push(Ship(2, "Titanic", "UK Marine", e2, true));
    depo.airplanes.push(Airplane(3, "Boeing 747", "Boeing", e3, 4, 416));

    depo.showAllVehicle();
}
