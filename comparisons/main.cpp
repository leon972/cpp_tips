/*
 * Comparison operators 
 * 
 */

/* 
 * File:   main.cpp
 * Author: leonardo
 *
 * Created on 25 aprile 2023, 19:56
 */

#include <cstdlib>
#include <iostream>


/*
 * 
 */
int main(int argc, char** argv) {

    const int *a=nullptr;
    
    std::cout<<"<a==nullptr "<<(a==nullptr)<<std::endl;
    
    const char c[4]="abc";
    
    const char* p1=&c[0];
    const char* p2=&c[1];
    const char *p3=&c[1];
    
    std::cout<<"&c="<<&c<<std::endl;
    std::cout<<"p1="<<p1<<std::endl; //abc 
    std::cout<<"p2="<<p2<<std::endl; //bc
    
    std::cout<<"p1==p2 "<<(p1==p2)<<std::endl; //false (0)
    std::cout<<"p2==p3 "<<(p2==p3)<<std::endl; //true (1)
    std::cout<<"p1<p2 "<<(p1<p2)<<std::endl; //true (1)
    
    int ch=65;
    char ch1=ch;
    
    std::cout<<"ch==ch1 "<<(ch==ch1)<<std::endl; //true (1)
    
    //C++20 three way comparison
    
    int z1=9;
    int z2=12;
    
    auto cmp=z1<=>z2; //cmp is of type std::strong_ordering , return an object that is <0 if z1<0, 0 if z1==z2 and >0 if z1>z2
    std::strong_ordering cmp2=z1<=>z2;    
    
    std::cout<<"z1<=>z2 "<<(cmp<0)<<std::endl; //true
    
    const float f1=0.002f;
    const float f2=0.1f;
    
    auto cmpf=f1<=>f2;
    std::partial_ordering cmpf1=f1<=>f2;
    
    if (cmpf1<0)
    {
        //this will be printed
        std::cout<<"f1<f2"<<std::endl;
    }
    
    const char *ptr=nullptr;
    
    if (!ptr)
    {
        std::cout<<"nullptr ok"<<std::endl;
    }
    
    
    return 0;
}

