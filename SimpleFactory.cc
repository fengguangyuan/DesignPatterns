#include <iostream>
#include <string>

using namespace std;

/*********************************
** Simple Factory Pattern
** Weakness:
**   The core factory class would do too many works.
*********************************/
class Product {
    public:
        string info_;
        Product(string info):info_(info) {}
        virtual void print() {
            cout << info_ << " is produced..." << endl;
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
        Story* produceStory(string info) {
            return new Story(info);
        }
        Math* produceMath(string info) {
            return new Math(info);
        }
};

int main(void) {
    Factory* f = new Factory();
    f->produceStory("child");
    f->produceMath("logical");
}
