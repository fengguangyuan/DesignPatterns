
Singleton2* Singleton2::s#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class Singleton {
    public:
        static Singleton* getInstance(std::thread::id id) {
            if (singleton == NULL) {
                // Utilize C++ feature to release lock automatically
                // after this method returned
                std::lock_guard<std::mutex> lck(mtx);
                if (singleton == NULL) {
                    singleton = new Singleton();
                    cout << id << " will created a singleton object" << endl;
                }
            }
            return singleton;
        }
    private:
        Singleton() {}
        Singleton(Singleton& s);
        Singleton(const Singleton& s);
        Singleton(const Singleton&& s);
        Singleton& operator=(const Singleton& s);
        Singleton& operator=(const Singleton&& s);
        static Singleton* singleton;
        static std::mutex mtx;
};
Singleton* Singleton::singleton = NULL;
// In this case, a static member std::mutex variable can't be used in getInstace(),
// unless it's initialized or constructed explicitly like this.
std::mutex Singleton::mtx;

class Singleton2 {
    public:
        static Singleton2* getInstance(std::thread::id id) {
            static std::mutex mtx;
            if (singleton == NULL) {
                // Utilize C++ feature to release lock automatically
                // after this method returned
                std::lock_guard<std::mutex> lck(mtx);
                if (singleton == NULL) {
                    singleton = new Singleton2();
                    cout << id << " will created a singleton object" << endl;
                }
            }
            return singleton;
        }
    private:
        Singleton2() {}
        Singleton2(Singleton2& s);
        Singleton2(const Singleton2& s);
        Singleton2(const Singleton2&& s);
        Singleton& operator=(const Singleton2& s);
        Singleton& operator=(const Singleton2&& s);
        static Singleton2* singleton;
};
Singleton2* Singleton2::singleton = NULL;

void singleton_test () {
    Singleton* s1 = Singleton::getInstance(std::this_thread::get_id());
    static std::mutex mtx;
    std::lock_guard<std::mutex> lck(mtx);
    cout << std::this_thread::get_id() << " showing: " << s1 << endl;
}

void singleton2_test () {
    Singleton2* s1 = Singleton2::getInstance(std::this_thread::get_id());
    static std::mutex mtx;
    std::lock_guard<std::mutex> lck(mtx);
    cout << std::this_thread::get_id() << " showing: " << s1 << endl;
}

int main(void) {
    std::thread t[10];
    cout << "singleton is testing..." << endl;
    for (int i = 0; i < 10; i++) t[i] = std::thread(singleton_test);
    for (int i =0 ; i < 10; i++) t[i].join();
    cout << "singleton 2 is testing..." << endl;
    for (int i = 0; i < 10; i++) t[i] = std::thread(singleton_test);
    for (int i =0 ; i < 10; i++) t[i].join();
    return 0;
}
