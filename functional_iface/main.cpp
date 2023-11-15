/**
 * Functional interface
 */

#include <cstdlib>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

class IFunction
{
    public:
        virtual double operator () (double v) noexcept=0;    
        virtual ~IFunction() {}
};

class SquareFn:public IFunction
{
public:
    double operator () (double v) noexcept override {
        return v*v;
        
    }   
    ~SquareFn()
    {        
    }
};


/**
 * Using functional
 * @param fn
 * @param values
 * @return 
 */
double use_fn(IFunction &fn,const std::vector<double> &values)
{
    for (auto v:values)    
    {
        cout<<v<<" -> "<<fn(v)<<endl;
    }
    return 0;
}

/**
 * Passing functional
 * @param fn
 * @param v
 * @return 
 */
double use_fn2(std::function<double(double)> fn,double v)
{
    cout<<"use_fn2->"<<fn(v)<<endl;
    return fn(v);
}


int main(int argc, char** argv) {
    
    SquareFn sq;
    
    cout<<sq(12.0)<<endl;
    
    auto y=use_fn2(sq,9);
    
    use_fn(sq,{1,2,3,4,5});
    
    return 0;
}

