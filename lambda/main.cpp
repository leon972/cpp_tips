/*
 Lambda function
 */

#include <cstdlib>
#include <iostream>
#include <functional>
#include <vector>
#include <numeric>

using namespace std;


/**
 * Passing lambda to function (by value  this is the preferred way)
 * @param lambda
 * @param a operand 1
 * @param b operand 2
 */
void use_my_lambda(std::function<int(int,int)> lambda,int a,int b)
{
    cout<<lambda(a,b)<<endl;    
}

/**
 * Passing lambda using template
 * @param conv
 * @return 
 */
template <typename F>
void use_my_lambda2(F fn,int val)
{
    cout<<fn(val)<<endl;
}


/**
 * Returning a lambda from function
 */
std::function<float(float)> create_conv_fn(const float conv)
{
    return [=](float value) {return value*conv;};
}

/*
 * 
 */
int main(int argc, char** argv) {
    
    int x=99;
    int y=0;
    
    //does not capture anything
    auto print_hello=[]() {
        cout<<"hello!"<<endl;
    }; 
    
    print_hello(); //prints hello
    
    //capture everything in scope by reference    
    auto inc_x=[&](int delta) {
        x+=delta;
    };
    
    inc_x(2); //x=101
    cout<<x<<endl;
    
    //capture everything in scope by copy
    std::function<void(const char*)> fn=[=](const char *msg)
    {
        cout<<msg<<endl;        
        cout<<x<<endl;
        //x++; error x is readonly here            
    };  
    
    fn("capture by copy");
    cout<<"x after call="<<x<<endl;    
    
    //lambda returing values
    auto sum=[](int a,int b)
    {
        return a+b;
    };
    
    cout<<sum(11,22)<<endl;
    
    //lambda specifying return value
    auto sum2=[](int a,int b)->int
    {
        return a+b;
    };    
    
    
    //use lambda
    use_my_lambda(sum,1,2); //prints 3
    
    use_my_lambda([](int a,int b){return a*b;},6,7); //prints 42
    
    //create lambda
    auto deg_to_rad=create_conv_fn(3.1415927f/180.0f);
    
    cout<<deg_to_rad(90.0f)<<endl; //1.507
    
    //captures only x by value
    auto fn3=[x](int a)->int {
        return x+a;
    };
    
    cout<<fn3(11)<<endl; //112
    
    //captures everything by reference except x that is by value
    auto fn4=[&,x]() ->int {
        ++y;
        return x+y;
    };
    
    cout<<fn4()<<endl;
    
    use_my_lambda2(fn3,1003); //1104
    
    use_my_lambda2([](int t){return t*t;},9); //81
    
    //generic lambda (since C++14)
    auto genfn=[](auto a,auto b,auto c) {
        return a*b/c;
    };
    
    cout<<genfn(4.2,2.1,2)<<endl;
    
    auto sumfn=[](auto a,auto b){
        return a+b;
    };
    
    //template lmabda (since C++20)
    auto fnt=[sumfn]<typename T>(const std::vector<T> &vec) {
        return std::accumulate(vec.begin(),vec.end(),T{},sumfn);
    };
    
    std::vector<int> vec{1,2,3}; //prints 6
    cout<<fnt(vec)<<endl;
    
    return 0;
}

