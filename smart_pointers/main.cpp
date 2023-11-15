/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: leonardo
 *
 * Created on 1 novembre 2023, 18:36
 */

#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>
#include <cassert>
#include <vector>

using namespace std;

class Base {
public:

    Base(std::string name) : name(name) {
    }

    virtual ~Base() {
        cout << "Base destroyed " << endl;
    }

    virtual void display() const = 0;
    
    
    void set_name(std::string n)
    {
        name=n;
    }

protected:

    std::string name;

};

class Foo : public Base {
public:

    Foo(std::string name) : Base(name) {

    }  
    
    Foo():Foo("non-name")
    {
        cout<<"called Foo default ctor"<<endl;
    }
   
    void display() const override {
        cout << "I' am Foo " << name << endl;
    }

    ~Foo() {
        cout << "Foo " << name << " destroyed" << endl;
    }

};


/**
 * Error cannot copy unique_ptr
 * @param ptr
 */
/*void use_ptr(std::unique_ptr<Foo> ptr)
{
    ...
}*/

void use_ptr(std::unique_ptr<Foo> &ptr)
{
    cout<<"Passed to function"<<endl;
    ptr->display();
}

/**
 * Shared ptrs can be passed by value
 * @param ptr
 */
void use_shared(std::shared_ptr<Foo> ptr)
{
    cout<<"Passed shared ptr to function"<<endl;
    ptr->display();    
}

class FooFactory
{
private:
    FooFactory()
    {
        
    }

public:
    
    static unique_ptr<Foo> createCar()
    {
        return std::make_unique<Foo>("Car created from factrory");
    };   
    
    static unique_ptr<Foo[]> createCars(const std::vector<std::string> &names)
    {
        auto ptrv=make_unique<Foo[]>(names.size());
        for (int i=0;i<names.size();++i)
        {
            ptrv.get()[i].set_name(names[i]);            
        }
        return ptrv;
        
    };
        
};

/*
 * 
 */
int main(int argc, char** argv) {
    
    std::unique_ptr<Foo> pfoo(new Foo("Test"));
    
    //call method
    pfoo->display();
    
    //get the raw ptr
    Foo *raw_foo=pfoo.get();
    if (raw_foo!=nullptr)
    {
        raw_foo->display();
    }
    
    //destroy previous pointer ad reassign a new pointer
    pfoo.reset(new Foo("Test2"));
    
    pfoo->display();
    
    //std::unique_ptr<Foo> pfoo2=pfoo; error unique pointer cannot be assigned    
    
    use_ptr(pfoo);
    
    //using move to transfer ownership
    
    std::unique_ptr<Foo> pfoo3=std::move(pfoo);
    
    assert(pfoo.get()==nullptr); //ownership transferred to pfoo3
    

    //array of objects  
    
    auto pfoos=std::make_unique<Foo[]>(2); //created an array of Foo with nullptr that must be initialized
    
    Foo p=pfoos.get()[0];
    
    p.display();
    
    auto pfoos2=std::make_unique<Foo*[]>(2); 
    
    std::unique_ptr<Foo> psmart=std::unique_ptr<Foo>(new Foo("inside array"));
    
    pfoos2.get()[0]=psmart.get();
    
    auto pcar=FooFactory::createCar();
    
    pcar->display();
    
    //shared ptr
    
    auto sfoo=std::make_shared<Foo>("Shared foo");
    
    sfoo->display();
    
    auto sfoo2=sfoo;
    
    //sfoo and sfoo2 reference the same object
    assert(sfoo.get()!= nullptr);
    assert(sfoo2.get()!=nullptr);
    
    use_shared(sfoo2);
    
    unique_ptr<Foo[]> cars=FooFactory::createCars({"A","B","C"});
        
    cout<<"end"<<endl;
    
    //managed objects are destroyed
    
    return 0;
}

