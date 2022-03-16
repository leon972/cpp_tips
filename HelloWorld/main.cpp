/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: leonardo
 *
 * Created on 16 marzo 2022, 21:46
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <numbers>

using namespace std;

constexpr int factorial(int n)
{
    return n <= 1 ? 1 : (n * factorial(n - 1));
}

constexpr std::string_view msg = "hello, world c++ 20"sv;
constexpr auto v=std::numbers::phi;

/*
 * 
 */
int main(int argc, char** argv) {

    cout<<msg<<endl;
    cout<<factorial(30)<<endl;   
    cout<<std::numbers::phi<<endl;
    cout<<v<<endl;
    
    return 0;
}

