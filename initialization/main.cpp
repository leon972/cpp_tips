/**
 * Initialization types
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include <numeric>

using std::cout;
using std::endl;

struct Sim {
    int value;
};

struct Foo {
    std::string data;
    //User-provided default constructor

    Foo() : Foo("I am Foo") //<!-- c++11 constructions delegations
    {

        // Foo("I am Foo"); <! -- ERROR this create an object foo it doesn't call the constructor
    }

    Foo(const std::string &name) {
        data = name;
        cout << data << endl;
    }

    const std::string str() const {
        return std::string("[Foo]:") + std::string(data);
    }

};

struct Bar : public Foo {
    int value;

    explicit Bar(int value) : Foo("I am Bar"), value(value) //<!-- constructor delegation
    {

    }

    explicit Bar() : Foo("Im am explicit Bar"), value(0) {

    }

    Bar(int value, const std::string &data) : Foo(data), value(value) {

    }

    void display() const {
        cout << "Bar " << data << " value=" << value;
    }

};

int sum_items(const std::vector<int> &v) {
    return std::accumulate(v.begin(), v.end(), 0, [](auto prev, auto v) {
        return prev + v;
    });
}

void process_bar(const Bar &bar) {
    cout << "processing bar " << bar.data << endl;
}


int g_myint; //initialized to default value (zero)

struct Device {
    const char* name;
    int size;
    bool enabled;
    char type;
};


//C-style struct initialization
const Device devices[] = {
    {
        .name = "Device1",
        .size = 0,
        .enabled = true,

    },
    {
        .name = "Device2",
        .size = 1,
        .enabled = true

    }
};

void print_device(const Device *ptr) {
    if (ptr) {
        cout << "name=" << ptr->name << " enabled=" << ptr->enabled << " size=" << ptr->size << " type=" << ptr->type << endl;
    } else {
        cout << "null" << endl;
    }
}

/*
 * 
 */
int main(int argc, char** argv) {


    //---------------------- default initialization ------

    int a; //undeterminate (avoid!)    
    std::string cc; //default string initialization to ""
    float *pf; //undeterminate
    Sim sim; //calls the implicit default constructor
    //const Sim sim2; error:no user provided ctor       
    Foo foo; //call the user-provided default constructor
    const Foo foo2; //call the user-provided default constructor   
    Bar bar; //ok call Bar()


    cout << "a=" << a << endl; //undefined behaviour
    cout << "cc=" << cc << endl;
    cout << "pf=" << pf << endl; //undefined  behaviour
    // cout<<"*pf="<<*pf<<endl; //undefined  behaviour
    cout << "sim.value=" << sim.value << endl;
    cout << "foo.data=" << foo.data << endl;
    cout << "foo2.data=" << foo2.data << endl;
    cout << "bar=";
    bar.display();
    cout << endl;


    //-------------------- copy initialization -----------

    const Foo foo3 = std::string("Foo 3 data"); //ok copy initialization 
    //Bar bar2=22; error bercause the ctor Bar(int value) is explicit!

    long l1;
    long l2 = l1; //undefined behaviour
    int ax = 10;
    const Foo foo4 = foo3;

    cout << "foo3=" << foo3.data << endl;
    cout << "l2=" << l2 << endl; //undefined behaviour
    int e1, e2 = 5;
    cout << "e1=" << e1 << endl; //undefined behaviour
    cout << "e2=" << e2 << endl;
    Bar baz = {22, std::string("fff")}; //ok user defined ctror
    //Bar baz1={55}; //errror! this ctor is declared explicit! cannot copy initialize

    //------------------ direct initialization -------------
    Bar baz3(22);
    Bar baz4{22};
    cout << "typeid(baz)="<<typeid (baz).name() << endl;

    cout << "baz3.value=" << baz3.value << endl;
    cout << "baz4.value=" << baz4.value << endl;

    float ft1(8.1f);
    cout << ft1 << endl;
    int16_t reg1{0x01FA};
    cout << reg1 << endl; //506

    //-------------------- char array initialization ------------
    char arr1[] = {'a', 'b', 'c'};
    cout << arr1[2] << endl; //prints c
    cout << sizeof (arr1) << endl; //3
    char arr2[3] = {'X', 'Y', 'Z'}; //aggregate initialization
    cout << arr2 << endl; //XYZ
    const char *txt = "This is a text";
    cout << sizeof (txt) << endl; //size of pointer (8 o 64 bit machines)
    cout << sizeof (*txt) << endl; //sizeo of the first element of the array
    const char *txt2{"Text 2"};
    cout << txt2 << endl; //Text 2
    char txt3[]{"Text 3"};
    cout << txt3 << endl; //text 3
    cout << sizeof (txt3) << endl; //7
    const Foo foos[] = {
        {"f1"},
        {"f2"},
        {"f3"}}; //aggregate and uniform initialization 
    cout << foos[1].str() << endl;
    cout << "sizeof(foos)=" << sizeof (foos) << endl; //96 sizeof (foo)*3
    cout << "foos len=" << (sizeof (foos) / sizeof (Foo)) << endl;

    //-------------- uniform initialization ----------------------------
    auto f8{22};
    cout << typeid (f8).name() << endl; //i=integer
    auto f9{22.1};
    cout << typeid (f9).name() << endl; //d=double
    auto f10{99.0001f};
    cout << typeid (f10).name() << endl; //f=float
    std::vector va{1, 2, 3, 4}; //vector uniform initialization
    va.push_back(11);
    cout << sum_items({5, 5, 5, 10}) << endl; //25 
    process_bar({11, "Bar to be processed"});

    print_device(&devices[0]);



    return 0;

}

