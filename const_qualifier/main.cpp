/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: leonardo
 *
 * Created on 5 settembre 2023, 14:43
 */

#include <cstdlib>
#include <iostream>

using std::cout,std::endl;

using namespace std;

class Foo
{
public:
    
    Foo(const char *text):data(text)
    {
        
    }
    
    void display() const
    {
        cout<<data<<endl;        
    }
    
    void set(const char *text)
    {
        data=text;
    }
    
    
private:
    const char *data;
};

void process_foo(const Foo &foo)
{
    foo.display(); //ok è const
    //foo.set("xxx"); errore perché foo è const
}

/*
 * 
 */
int main(int argc, char** argv) {

    
    const auto a=11; //const int
    //a=9; errore!
    const Foo foo{"Foo!"};    
    foo.display(); //ok perché display è const
    process_foo(foo);
    
    //foo.set("Test"); //errore perché foo è dichiarata const    
    auto ref_a=&a; //const ref to a    
    cout<<a<<endl;
    //a=99; errore perché ref_a è const reference    
    
    const int *pa=&a; //a pointer to const int (punta a un oggetto costante)
    //*pa=88; //errore perché punta ad un valore costante
    pa=nullptr; //ok perché il puntantore non è constate
    
    const int * const pa1  =&a; //const pointer to const data
    //*pa1=99; errore
    //pa1=nullptr; errore perché il puntato è constante
    int c=100;
    
    int *const pa2=&c; //a const pointer to non-const data
    
    *pa2=101; //ok perché punta a dati non costanti
    cout<<c<<endl; //101
    
    const int v[]={1,2,3};
    //v[1]=99; errore array di valori costanti
    const int m[][2]={{1,2},{11,12}};
    cout<<m[1][1]<<endl;
    cout<<m[0][1]<<endl;
    //m[1][1]=9; errore perché const
    
    return 0;
}

