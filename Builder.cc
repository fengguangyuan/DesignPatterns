#include <iostream>
#include <vector>

using namespace std;

/**********************
 * components of a ship
 **/
class ShipProduct {
    public:
        virtual void print() = 0;
};
class Iron : public ShipProduct {
    public:
        Iron() { print(); }
        virtual void print() { cout << "Iron has ready" << endl; }
};
class Nail : public ShipProduct {
    public:
        Nail() { print(); }
        virtual void print() { cout << "Nail has ready" << endl; }
};
class Oar : public ShipProduct {
    public:
        Oar() { print(); }
        virtual void print() { cout << "Oar has ready" << endl; }
};

class Ship {
    public:
        vector<ShipProduct*> components_;
        Ship(vector<ShipProduct*> components): components_(components) {}
        void print() { cout << "A ship was built!" << endl; }
};

/**********
 * Builder
 **/
class Builder {
    public:
        virtual Iron* buildIron() = 0;
        virtual Nail* buildNail() = 0;
        virtual Oar* buildOar() = 0;
        virtual Ship* buildOver(vector<ShipProduct*>&) = 0;
};
class ShipBuilder : public Builder {
    public:
        Iron* buildIron() {
            return new Iron();
        }
        Nail* buildNail() {
            return new Nail();
        }
        Oar* buildOar() {
            return new Oar();
        }
        Ship* buildOver(vector<ShipProduct*>& components) {
            Ship* ship = new Ship(components);
            return ship;
        }
};

/***********
 * designer
 **/
class Designer {
    public:
        Ship* buildShip(Builder* builder) {
            vector<ShipProduct*> components;
            components.push_back(builder->buildIron());
            components.push_back(builder->buildNail());
            components.push_back(builder->buildOar());
            return builder->buildOver(components);
        }
};

int main(void) {
    Designer* de = new Designer();
    ShipBuilder* builder = new ShipBuilder();
    Ship * ship = de->buildShip(builder);
    ship->print();
    for(auto it : ship->components_) {
        cout << typeof(*)<< endl;
    }
    return 0;
}
