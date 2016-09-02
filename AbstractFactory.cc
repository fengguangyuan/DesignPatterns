#include <iostream>

using namespace std;

/*********************************
** Abstract Factory Method Pattern
** Virtues
**   One kind of factory just produce the corresponding family products.
*********************************/
class Product {
    public:
        string info_;
        Product(string info):info_(info) {}
        virtual void print() {
            cout << info_ << " is produced..." << endl;
        }
};

class ChildProduct : public Product {
    public:
        ChildProduct(string info): Product(info) {}
};

class MatureProduct : public Product {
    public:
        MatureProduct(string info): Product(info) {}
};

class ChildMath : public ChildProduct {
    public:
        ChildMath(string info): ChildProduct(info) {
            print();
        }
        void print() {
            cout << info_ << " math is produced..." << endl;
        }
};

class MatureMath : public MatureProduct {
    public:
        MatureMath(string info): MatureProduct(info) {
            print();
        }
        void print() {
            cout << info_ << " math is produced..." << endl;
        }
};

class ChildStory : public ChildProduct {
    public:
        ChildStory(string info): ChildProduct(info) {
            print();
        }
        void print() {
            cout << info_ << " story is produced..." << endl;
        }
};

class MatureStory : public MatureProduct {
    public:
        MatureStory(string info): MatureProduct(info) {
            print();
        }
        void print() {
            cout << info_ << " story is produced..." << endl;
        }
};

class Factory {
    public:
        virtual Product* produceMath(string) = 0;
        virtual Product* produceStory(string) = 0;
};

class ChildFactory : public Factory {
    public:
        virtual ChildProduct* produceMath(string info) {
            return new ChildMath(info);
        }
        virtual ChildProduct* produceStory(string info) {
            return new ChildStory(info);
        }
};
class MatureFactory : public Factory {
    public:
        virtual MatureProduct* produceMath(string info) {
            return new MatureMath(info);
        }
        virtual MatureProduct* produceStory(string info) {
            return new MatureStory(info);
        }
};

int main(void) {
    MatureFactory* mf = new MatureFactory();
    mf->produceMath("mature");
    mf->produceStory("mature");
    ChildFactory* sf = new ChildFactory();
    sf->produceStory("child");
    sf->produceMath("child");
    return 0;
}
