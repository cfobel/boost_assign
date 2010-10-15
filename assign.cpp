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
    // Initialization using list_of()
    vector<int> v3 = list_of(1)(2)(3)(4);

    // Assignment using list_of()
    v  = list_of(1)(2)(3);

    // Appending using repeat_fun() to fill with count.
    push_back(v2).repeat_fun(10, next<int>(0));
    // Appending using repeat_fun() to fill with random numbers.
    push_back(v2).repeat_fun(10, rand);

    BOOST_FOREACH(int i, v2) {
        cout << i << endl;
    }

    cout << endl << endl;

    // Appending using += operator and repeat_fun().
    v3 += 1, 2, 3, repeat_fun(4, rand), 4;
    // Appending using push_back() and range().
    push_back(v3).range(v2.begin() + 10, v2.begin() + 13);
    BOOST_FOREACH(int i, v3) {
        cout << i << endl;
    }

    return 0;
}
