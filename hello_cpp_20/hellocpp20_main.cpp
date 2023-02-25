/**
 * C++20 test
 * Use some C++20 features to check the compiler compatibility
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#define PRINT_FEATURE(feature) cout<<#feature<<" supported : "<<feature<<endl;

void print_compiler_std()
{
#ifndef __cplusplus
    cout<<"No C++ supported"<<endl;
#else
    cout<<"C++ standard: "<<__cplusplus<<endl;
    
    if (__cplusplus>=202002L)
    {
        cout<<"C++20 is supported!"<<endl;
    }
    else
    {
        cout<<"C++20 NOT SUPPORTED"<<endl;
    }
           
    
#endif
}


int main(int argc, char** argv) {

    print_compiler_std();
            
    
#ifdef __cpp_concepts
    PRINT_FEATURE(__cpp_concepts);
#else
    cout<<"Concepts not supported"<<endl;
#endif   

#ifdef __cpp_conditional_explicit
    PRINT_FEATURE(__cpp_conditional_explicit);
#else
     cout<<"Conditional explicit not supported"<<endl;
#endif

#ifdef __cpp_consteval
    PRINT_FEATURE(__cpp_consteval);
#else
    cout<<"Const eval not supported"<<endl;
#endif
    
#ifdef __cpp_constexpr
    PRINT_FEATURE(__cpp_constexpr)
#else
    cout<<"constexpr not supported"<<endl;
#endif
    
#ifdef __cpp_size_t_suffix
    PRINT_FEATURE(__cpp_size_t_suffix);
#else
     cout<<"__cpp_size_t_suffix not supported"<<endl;
#endif

    return 0;
}

