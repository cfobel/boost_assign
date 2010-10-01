#include <iostream>

#include <boost/foreach.hpp>
#include <boost/assign/std/vector.hpp> // for 'operator+=()'
#include <boost/assign/list_inserter.hpp> // for 'push_back()'
#include <boost/assign/list_of.hpp>       // for 'list_of()' and 'ref_list_of()'
#include <cstdlib>


using namespace boost::assign;
using namespace std;

template< class T >
struct next    
{
    T seed;
    next( T seed ) : seed(seed) 
    { }
    
    T operator()() 
    {
        return seed++;
    }
};


int main () {
    vector<int> v, v2;
    v  = list_of(1)(2)(3);
    push_back(v2).repeat_fun(10, next<int>(0));
    push_back(v2).repeat_fun(10, rand);

    BOOST_FOREACH(int i, v2) {
        cout << i << endl;
    }

    return 0;
}
