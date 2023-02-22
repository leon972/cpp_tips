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

#include <cstdlib>
#include <iostream>
#include <map>
#include <iostream>
#include <ranges>


using namespace std;


constexpr auto a=9+8;

/*
 * 
 */
int main(int argc, char** argv) {
    
    

  cout << "Size of following Datatypes in bytes: \n";
  cout << "char : " << sizeof(char) << endl;
  cout << "int : " << sizeof(int) << endl;
  cout << "unsigned int : " << sizeof(unsigned int) << endl;
  cout << "short int : " << sizeof(short int) << endl;
  cout << "long int : " << sizeof(long int) << endl;
  cout << "unsigned short int : " << sizeof(unsigned short int) << endl;
  cout << "unsigned long int : " << sizeof(unsigned long int) << endl;
  cout << "long long int : " << sizeof(long long int) << endl;
  cout << "unsigned long long int : " << sizeof(unsigned long long int) << endl;
  cout << "signed char : " << sizeof(signed char) << endl;
  cout << "unsigned char : " << sizeof(unsigned char) << endl;
  cout << "wchar_t : " << sizeof(wchar_t) << endl;
  cout << "float : " << sizeof(float) << endl;
  cout << "double : " << sizeof(double) << endl;
  
  cout<<"pointers"<<endl;
    
  cout <<"char* :"<<sizeof(char*)<<endl; //8 on 64 bit machines
  cout <<"int* :"<<sizeof(int *)<<endl; //8 on 64 bit machines
  
  auto const ints = {0, 1, 2, 3, 4, 5};
    auto even = [](int i) { return 0 == i % 2; };
    auto square = [](int i) { return i * i; };
 
    // the "pipe" syntax of composing the views:
    for (int i : ints | std::views::filter(even) | std::views::transform(square))
        std::cout << i << ' ';
 
    std::cout << '\n';
 
    // a traditional "functional" composing syntax:
    for (int i : std::views::transform(std::views::filter(ints, even), square))
        std::cout << i << ' ';
   
  
}

