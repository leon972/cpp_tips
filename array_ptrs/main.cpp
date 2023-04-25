/*
 * C-style arrays and pointers
 */

/* 
 * File:   main.cpp
 * Author: leonardo
 *
 * Created on 25 aprile 2023, 20:21
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

/**
 * Passing an array pointer as function argument
 * @param ptr
 * @param array_len
 * @param info
 */
template<typename T>
void printArrayInfo(T *ptr,size_t array_len,const string &info)
{
    cout<<info<<" length="<<array_len<<endl;
    for (size_t i=0;i<array_len;++i)
    {
        cout<<"array["<<i<<"]="<<*ptr<<endl;
        ++ptr;
    }    
}

struct MyData
{
    const string data;
    
    MyData(const string& data):data(data)
    {
        
    }
    
    friend std::ostream& operator << (std::ostream &os,const MyData &my_data);    
    
};

std::ostream& operator << (std::ostream &os,const MyData &my_data)
{
    cout<<"MyData "<<my_data.data<<endl;
    return os;
}

//passing array with exact size
void testArraySize(int *a[5])
{
    cout<<"test array size "<<sizeof(*a)<<endl; //8 on 64 bit machine
    
    for (int i=0;i<5;++i)
    {
        cout<<*a[i]<<endl;
    }    
}

//array is not copied but passed by reference
void testArray2(char c[4])
{
    cout<<"test array 2"<<endl;
    for (int i=0;i<4;++i)
    {
        c[i]='X';
    }
    printArrayInfo(c,4,"After changed in function");    
}

/**
 * 
 */
int main(int argc, char** argv) {
    
    const char *text="This is a text";
    
    printArrayInfo(text,14,"ptr to array");
    
    //sizeof d is sizeof MyData*3    
    const MyData d[3]={MyData("test1"),MyData("test2"),MyData("test3")};
    
    //d is consedered a pointer to the beginning of array
    printArrayInfo(d,sizeof(d)/sizeof(MyData),"my data array");   
    
    const MyData *d1=d+1;
    
    cout<<"Pointer from the second element..."<<endl;
    cout<<"sizeof(MyData)="<<sizeof(MyData)<<endl;
    cout<<"sizeof(d)="<<sizeof(d)<<endl; //96=32*3 elements
    cout<<"d="<<d<<endl; //d memory addr
    cout<<"d1="<<d1<<endl; //d1 memory addr
    cout<<"Diff="<<(d1-d)<<endl; //1
    auto newSize=(sizeof(d)/sizeof(MyData)-(d1-d));
    cout<<"New size="<<newSize<<endl; //2
    
    printArrayInfo(d1,newSize,"stating from second element");
    
    cout<<"-------------"<<endl;
    
    int myints[]={1,2,3,4,5};
    int *v[5]={&myints[0],&myints[1],&myints[2],&myints[3],&myints[4]};
    
    testArraySize(v);
    
    char mychars[5]="ABCD";
    
    testArray2(mychars);
    
    printArrayInfo(mychars,4,"after function call");
        
    return 0;
}

