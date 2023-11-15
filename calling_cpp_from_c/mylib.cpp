/**
 Codice C++ invocato da C
 */

#include "mylib.h"
#include <iostream>
#include <memory>

using std::cout;
using std::endl;

void MyClass::process(int a, int b)  {
    cout << "Process " << a << ' ' << b <<'='<< a + b << endl;
}

MyClass::~MyClass() {
    cout << "MyClass destructor" << endl;
}

extern "C" {

    void process_data(int a, int b) {
        auto p = std::unique_ptr<ILib>(new MyClass());
        p->process(a, b);
    }
}
