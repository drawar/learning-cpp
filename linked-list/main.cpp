#include "LinkedList.h"
#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

#define pi 3.14159265358979

int main() {
    cout << "hello" << endl;
    LinkedList <int> a;
    assert(a.empty());
    cout << "Default constructor working." << endl;

    a.push_front(5);
    a.push_front(4);
    a.push_front(3);

    assert(a.size() == 3);
    cout << "push_front() and size() working." << endl;

    assert(a.pop_front() == 3);
    cout << "pop_front() working." << endl;

    a.push_back(6);
    a.push_back(7);
    a.push_back(8);

    assert(a.size() == 5);
    cout << "push_back() and size() working." << endl;

    assert(a.pop_back() == 8);
    cout << "pop_back() working." << endl;

    assert(a.get(2) == 6);
    cout << "get() working" << endl;

    LinkedList <double> b(pi);
    assert(!b.empty());
    cout << "Parametrized constructor working." << endl;
    assert(abs(b.pop_back() - pi) < 0.00000001);
    cout.precision(17);
    cout << "pop_back() working." << endl;

    LinkedList <string> c("Hello");
    c.push_back("World!");
    size_t size = c.size();
    for (size_t i = 0; i < size; i++)
        cout << c.pop_front() << " ";
    return 0;
}