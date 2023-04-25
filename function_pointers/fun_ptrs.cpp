/*********************************
 * Function pointers 
**********************************/

#include <iostream>
using namespace std;


int fn_square(int x)
{
    return x*x;
}

int fn_cube(int x)
{
    return x*x*x;
}

void display(const char* text)
{
    cout<<"display:"<<text<<endl;
}

/**
 * A function that accept as pointer to function that accept and int and return an int and an int as second argument
*/
void use_function(int (*ptr)(int),int value)
{
    cout<<"il valore restituito è:"<<ptr(value)<<endl;
}

/**
 * Array of pointers to functions that accept an int and return an int
*/
int (*fun_ptr_array[2])(int);

/**
 typedef a pointer to a function that accepts an int and return an int
*/

typedef int (*INT_FUNCTION)(int);

/**
 * A function that accepts and int and return a function pointer to a function that
 * accepts and int and return an int
*/

int (*(choose_function(int id)))(int)
{
    switch (id)
    {
        case 0:
        return fn_square;
        case 1:
        return fn_cube;
        default:
        return 0; //id non valido
    }
}

/**
 * A function pointer that points to a function that accepts two int and return an array of 5 int
*/
int (*(*fn_arr)(int,int))[5];

typedef int vector5[5];


vector5 vec5={1,2,3,4,5};


vector5* test_function(int a,int b)
{
    return &vec5;
}

int main()
{

   
    int (*fun_ptr)(int)=fn_square;

    cout<<fun_ptr(2)<<endl; //prints 4
    
    fun_ptr=fn_cube;

    cout<<fun_ptr(2)<<endl; //prints 8

    
    void (*fun_ptr2)(const char*)=display;

    fun_ptr2("Hello World!");

    use_function(fun_ptr,5);

   
    use_function(fn_square,6);

    //populate the array of function pointers
    fun_ptr_array[0]=fn_square;
    fun_ptr_array[1]=fn_cube;

    cout<<"*** user function pointer array*"<<endl;
    for (int i=0;i<2;i++) use_function(fun_ptr_array[i],6);
  

    INT_FUNCTION fn1=fn_square;

    use_function(fn1,18);

    fn1=choose_function(0);//returns fn_square

    use_function(fn1,3);

    fn1=choose_function(1);//returns fn_cube

    use_function(fn1,3);

    fn_arr=test_function;

    vector5* res=fn_arr(1,1);

    for (int i=0;i<5;i++)
    {
        cout<<(*res)[i]<<endl;
    }

    return 0;

}