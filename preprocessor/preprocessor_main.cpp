/**
 * Use of preprocessors macros
 */

#include <cstdlib>
#include <iostream>
#include <string>

//included once because of the geaders guards
#include "mylib.h"

#if __has_include("mylib2.h") //since C++17: detects if the include header is available
#include "mylib2.h"
#endif

using namespace std;


#define LINUX 
#define POSIX

#ifdef WINDOWS
#undef POSIX
#endif 


//custom defined pgma, depends on compiler
//for gcc this shows a message while compiling
#pragma message "Compiling " __FILE__ "..."

//defines constants
#define BUFFER_SIZE 1024

//macros with arguments
#define PRINT(msg) cout<<msg<<endl
#define PRINT_TITLE(title) cout<<endl<<title<<endl<<"------------------"<<endl
#define SAFE_DELETE_ARRAY(a) delete[] a;a=nullptr
#define SAFE_DELETE_ARRAY2(a,msg) delete[] a;a=nullptr;cout<<msg<<endl

//function-like macros
#define uppercase2(s) uppercase(s) 

//Stringizing: macro arg as string
#define NICE_LOOP(nloops) fprintf (stderr, "Nice loop till: " #nloops "\n");for (int i=0;i<nloops;++i) {cout<<i<<endl;} 
#define PRINT_SIZE(datatype) cout<<#datatype" : "<<sizeof(datatype)<<endl
#define PRINT_MACRO(m) cout<<#m<<"="<<m<<endl;


string uppercase(const string &s)
{
    string s1=string(s);
    std::transform(s1.begin(), s1.end(), s1.begin(), std::ptr_fun<int, int>(std::toupper));
    return s1;
}

//concatenation macros

struct Command
{
  const char *name;
  void (*function) (void);
};

void move_command()
{
    cout<<"Called "<<__func__<<endl;
}

void stop_command()
{
     cout<<"Called "<<__func__<<endl;    
}

//concatenation
#define CREATE_COMMAND(cmd) {#cmd, cmd##_command}

const Command mycommands[]={CREATE_COMMAND(move),CREATE_COMMAND(stop)};

/*
 * 
 */
int main(int argc, char** argv) {
    
    PRINT_TITLE("Preprocessor demo");
    PRINT("Avoid macro magic!");

#ifdef LINUX
    string system = "LINUX"s;
#elif defined WINDOWS
    string system = "WINDOWS"s;
#elif defined MAC_OS
    string system = "MAC OS"s;
#else 
    string system = "UNKNOWN";
#endif

    cout << system << endl;

    //checks if not is defined    
#ifndef DEBUG_MODE
    cout << "production mode" << endl;
#endif 

#ifdef POSIX
    cout << "posix" << endl;
#else 
    cout << "not posix" << endl;
#endif   

#ifdef POSIX
    cout << "posix" << endl;
#elif !defined POSIX
    cout << "not defined posix" << endl;
#endif   

    //included from mylib
    cout << squared(3.3) << endl;

    cout << myMin(7.0, 9.0) << endl;

    //file and line
    cout << "We are on file " << __FILE__ << " at line " << __LINE__ << endl;


#define COUT cout<<

    COUT"Hello World"<<endl;
    
    int* v=new int[100];
    
    SAFE_DELETE_ARRAY(v);
    
    v=new int[BUFFER_SIZE];
    
    SAFE_DELETE_ARRAY2(v,"deleted v");

    cout<<v<<endl; //prints 0
    
    //function like macro
    cout<<uppercase2("Hello world!"s)<<endl;
    
    NICE_LOOP(10)
    
    PRINT_SIZE(double);  
    PRINT_SIZE(int);  
    PRINT_SIZE(char);
    
    PRINT_TITLE("Standard macros");
    
    cout<<"This file is "<<__FILE__<<endl;
    cout<<"Current line in "<<__LINE__<<endl;
    cout<<"Function "<<__func__<<endl;
    cout<<"Compiler conforms to ISO Standard "<<__STDC__<<endl;
    cout<<"Date and time "<<__DATE__<<" "<<__TIME__<<endl; //time when preprocessor is run
    
#ifdef __cplusplus
    cout<<"C++"<<endl;
#endif
     
    PRINT_TITLE("GNU C specific macros");
    
#ifdef __GNUC__
    
    PRINT_MACRO(__GNUC__);
    PRINT_MACRO(__GNUC_MINOR__);
    PRINT_MACRO(__GNUC_MINOR__);
    PRINT_MACRO(__GNUC_PATCHLEVEL__);
    cout<<"Compiler version "<<__VERSION__<<endl;
    
#endif
    
    mycommands[0].function();

    return 0;
    
    


}

