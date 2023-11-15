/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: leonardo
 *
 * Created on 25 febbraio 2023, 15:23
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <list>
#include <format>


using namespace std;

/*
 * 
 */

 
int main (int argc,char *argv[]) {
    
    
    cout<<std::format("{1} to {0}", "a", "b");   
    
    const string str=std::format("{1} to {0}", "a", "b");
    cout <<str+"xx";
 
    
    
}
