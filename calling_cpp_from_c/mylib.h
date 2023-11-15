
#ifndef MYLIB_H
#define MYLIB_H

/**
 * Questa funzione può essere invocata da codice C
 * @param a
 * @param b
 */
extern "C" {
    void process_data(int a,int b);
}

class ILib
{
public:
    virtual void process(int a,int b)=0;
    virtual ~ILib() {};
};

class MyClass:public ILib
{
public:
    virtual void process(int a,int b);    
    virtual ~MyClass();
};



#endif /* MYLIB_H */

