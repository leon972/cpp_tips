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


using namespace std;

/*
 * 
 */
void display(const list<int> &lst)
{
    for (auto it=lst.begin();it!=lst.end();++it)    
    {
        cout<<*it<<",";        
    };
    cout<<endl;
}
 
int main (int argc,char *argv[]) {
    
    auto lst=list<int>{1,2,3,4,5};
    
    display(lst);    
    
    for (auto it=lst.begin();it!=lst.end();++it)
    {
        if (*it==3)
        {            
            lst.emplace(it,33);
            lst.remove(it);
            break;
                      
        }
    }
    
    display(lst);  
    
    
}
