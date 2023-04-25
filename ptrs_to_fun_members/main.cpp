/*
 * Pointers to function members
 */

#include <cstdlib>
#include <iostream>

using namespace std;

class Car
{
private:    
   
    int gear;
    const string name;
    
public:
    
     int engine;
    
    Car(const string &name):gear(0),name(name),engine(5000)
    {
        
    }
    
    static bool is_valid(int gear)
    {
        return gear>=0 && gear<=5;
    }
    
    int shift_gear(int new_gear)
    {
        if (new_gear!=gear && Car::is_valid(new_gear))
        {
            gear=new_gear;            
            cout<<"shifted to "<<gear<<endl;
        }
        else
        {
            cout<<"Same gear"<<endl;            
        }
        return gear;
    }    
    
    int get_gear() const
    {
        return gear;
    }
    
    const string get_name() const
    {
        return name;
    }        
    
};


int main(int argc, char** argv) {

    Car car("Porsche 911");
    
    cout<<car.get_name()<<endl;
    cout<<"gear="<<car.get_gear()<<endl;
    
    // declare a pointer to member function
    int (Car::*shiftFn)(int)=&Car::shift_gear;
    
    //call member function on a object instance    
    (car.*shiftFn)(1);   
    
    //declare a pointer to data member
    int Car::*ptrEngine=&Car::engine;
    
    //change the value on the instance
    car.*ptrEngine=6000;   
          
    cout<<"gear="<<car.get_gear()<<endl;   
    cout<<"engine="<<car.engine<<endl;  
    
    //pointer to static member function (is a normal fn pointer)
    
    bool (*fnIsValid)(int)=Car::is_valid;
    
    cout<<fnIsValid(11)<<endl; //false
    cout<<fnIsValid(1)<<endl; //true
    
    
    return 0;
}

