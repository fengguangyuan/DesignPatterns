#include <iostream>

using namespace std;

/*********************************
** Factory Method Pattern
*********************************/
class Product {
    public:
        string info_;
        Product(string info):info_(info) {}
        virtual void print() {
            cout << info_ << " is produced..." << endl;
        }
};

class Math : public Product {
    public:
        Math(string info): Product(info) {
            print();
        }
        void print() {
            cout << info_ << " math is produced..." << endl;
        }
};

class Story : public Product {
    public:
        Story(string info): Product(info) {
            print();
        }
        void print() {
            cout << info_ << " story is produced..." << endl;
        }
};

class Factory {
    public:
        virtual Product* produceProduct(string) = 0;
};

class MathFactory : public Factory {
    public:
        Math* produceProduct(string info) {
            return new Math(info);
        }
};
class StoryFactory : public Factory {
    public:
        Story* produceProduct(string info) {
            return new Story(info);
        }
};

int main(void) {
    MathFactory* mf = new MathFactory();
    mf->produceProduct("logical");
    StoryFactory* sf = new StoryFactory();
    sf->produceProduct("child");
    return 0;
}
