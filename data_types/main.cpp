/*
 * C++ Data types
 * C++20 compiler required
 */

/* 
 * File:   main.cpp
 * Author: leonardo
 *
 * Created on 20 gennaio 2023, 19:07
 */


#include <iostream>

using namespace std;


constexpr auto a = 9 + 8;

void implicit_type_conversion();
void explicit_type_conversion();


/**
 * Test data types
 */
int main(int argc, char** argv) {


    cout << "Size of following Datatypes in bytes: \n";
    cout << "char : " << sizeof (char) << endl;
    cout << "int : " << sizeof (int) << endl;
    cout << "unsigned int : " << sizeof (unsigned int) << endl;
    cout << "short int : " << sizeof (short int) << endl;
    cout << "long int : " << sizeof (long int) << endl;
    cout << "unsigned short int : " << sizeof (unsigned short int) << endl;
    cout << "unsigned long int : " << sizeof (unsigned long int) << endl;
    cout << "long long int : " << sizeof (long long int) << endl;
    cout << "unsigned long long int : " << sizeof (unsigned long long int) << endl;
    cout << "signed char : " << sizeof (signed char) << endl;
    cout << "unsigned char : " << sizeof (unsigned char) << endl;
    cout << "wchar_t : " << sizeof (wchar_t) << endl;
    cout << "float : " << sizeof (float) << endl;
    cout << "double : " << sizeof (double) << endl;

    cout << "pointers" << endl;

    cout << "char* :" << sizeof (char*) << endl; //8 on 64 bit machines
    cout << "int* :" << sizeof (int *) << endl; //8 on 64 bit machines

    cout << "New C++11 fixed width integers" << endl;
    
    cout << "int8_t : " << sizeof (int8_t) << endl;
    cout << "int16_t : " << sizeof (int16_t) << endl;
    cout << "int32_t : " << sizeof (int32_t) << endl;
    cout << "int16_t : " << sizeof (int16_t) << endl;
    cout << "int32_t : " << sizeof (int32_t) << endl;
    cout << "int64_t : " << sizeof (int64_t) << endl;

    cout << "uint8_t : " << sizeof (uint8_t) << endl;
    cout << "uint16_t : " << sizeof (uint16_t) << endl;
    cout << "uint32_t : " << sizeof (uint32_t) << endl;
    cout << "uint16_t : " << sizeof (uint16_t) << endl;
    cout << "uint32_t : " << sizeof (uint32_t) << endl;
    cout << "uint64_t : " << sizeof (uint64_t) << endl;

    cout << "Fastest signed integers" << endl;

    cout << "int_fast8_t : " << sizeof (int_fast8_t) << endl;
    cout << "int_fast16_t : " << sizeof (int_fast16_t) << endl;
    cout << "int_fast32_t : " << sizeof (int_fast32_t) << endl;
    cout << "int_fast64_t : " << sizeof (int_fast64_t) << endl;

    cout << "Smallest signed integers" << endl;
    cout << "int_least8_t : " << sizeof (int_least8_t) << endl;
    cout << "int_least16_t : " << sizeof (int_least16_t) << endl;
    cout << "int_least32_t : " << sizeof (int_least32_t) << endl;
    cout << "int_least64_t : " << sizeof (int_least64_t) << endl;
    
    cout<<"Pointers and arrays"<<endl;
    cout<<"char * : "<<sizeof(char*)<<endl;
    cout<<"int * : "<<sizeof(int *)<<endl;
    
    
    cout<<"Size of data"<<endl;
    
    int arr[]={1,2,3,4,5};
    int *arr2=new int[90];
    long long *arr3=new long long[100];
    
    cout<<"size of array of int : "<<sizeof(arr)<<endl; //prints array number of elements * element size in bytes (5 *sizeof(int)) = 20
    cout<<"sizeof int array pointer : "<<sizeof(arr2)<<endl; //prints 8 on 64 bit machine
    cout<<"sizeof long long array pointer : "<<sizeof(arr3)<<endl; //print 8 on 64 bit machine
    
    string str="Test string"s;    
    string &str2=str;
    
    cout<<"string size : "<<sizeof(str)<<endl; //prints 32 (gcc on linux 64 bit)
    cout<<"string ref size : "<<sizeof(str2)<<endl; //prints 32 (gcc on linux 64 bit)
    
    
    delete[] arr2;arr2=nullptr;       
    delete[] arr3;arr3=nullptr;
    
    implicit_type_conversion();
    explicit_type_conversion();

    return 0;

}

void implicit_type_conversion()
{
    //bool -> char -> short int -> int -> 

    //unsigned int -> long -> unsigned -> 

    //long long -> float -> double -> long double
    cout<<"Implicit type conversion"<<endl;
    char a='A';    
    int b=a;
    
    //char converted to int 
    cout<<b<<endl; //prints 65 (ASCII code of 'A')
    
    int c=9;
    
    //converts int to double
    double res=c/2.0;
    cout<<res<<endl;
    
    unsigned char a1='B';
    int b1=a1;
    
    cout<<b1<<endl; //prints 66
    
    int_fast16_t i1=100;
    
    //implicit conversion from int_fast16_t to double
    long double dbl=i1+0.01;
    
    cout<<dbl<<endl;
    
    int u=11;
    
    //truncation: no conversion    
    cout<<u/2<<endl;
    
    auto y1=u/2;  //y1 is of type int
    cout<<y1<<endl;
    
    auto y2=u/2.0; //convert to double
    
    cout<<y2<<endl;
    cout<<sizeof(y2)<<endl;
    
    auto y3=u/2.0f; //convert to float
    cout<<y3<<" "<<sizeof(y3)<<endl;  
    
    //implicit int to char
    int a2=65;
    char b2=a1;  
    cout<<b2<<endl; //prints  'A'
    
    
}

void explicit_type_conversion()
{
    cout<<"Explicit type conversion"<<endl;
    //convert larger sizes to smaller sizes
    double pi=3.1415;
    
    cout<<static_cast<int>(pi)<<endl; //prints 3 converts double to int
    
    double x=65.9123236;
    
    cout<<static_cast<char>(x)<<endl; //prints A truncation to char
    
    //no needs static_cast
    char t=x;
    cout<<t<<endl;
    
    int16_t v1=-890;    
    uint16_t v2=v1;
    cout<<v2<<endl;  
    
    char h='H';    
    void *ptr=&h;    
    cout<<ptr<<endl;
    
    
}

