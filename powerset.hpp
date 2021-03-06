#include "range.hpp"
#include "pair.hpp"

namespace itertools{
template <typename T>
class powerset{
    
    private:
    T t;
    
    public:
    //T t;
    powerset<T>(const T t0) : t(t0){}

    class iterator{

    private:
    typename T::iterator it;
    typename T::iterator it1;
    public:
    
    iterator(typename T::iterator t0) :
    it(t0) , it1(t0) {}

    bool operator !=(const iterator& t0) {
        return (it != t0.it && it1 != t0.it1);
    }

    iterator& operator ++(){
        bool not_equal = (it1 != it);
        if (!not_equal){
        ++it1;
        bool b = (it1 != it);
        if (!b)
        {
            ++it;
        }
        else{
        ++it1;
        }
        return *this;
    }
        ++it;
        return *this;
    }

    auto operator * () {
        return pair(*it,*it1);
    }



};
        iterator begin(){
            return iterator(t.begin());
        }
        iterator end(){
            return iterator(t.end());
        }

};

}