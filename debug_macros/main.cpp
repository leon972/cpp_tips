/*
 * __LINE__, __FILE__ and __func__ (since c++ 11) standard macros
 */
 

#include <cstdlib>
#include <iostream>

#define LOG(message) cout<<message<<" file "<<__FILE__<<" function "<<__func__<<" line "<<__LINE__<<endl;

using namespace std;

void my_function()
{
    cout<<"Hello!"<<endl;
    LOG("called function");
}


int main(int argc, char** argv) {

    LOG("start program");
    
    my_function();
    
    return 0;
}

