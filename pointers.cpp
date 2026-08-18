#include <iostream> 
#include <vector>

void inspect_copy(std::vector<double> v) {
    std::cout << "inside (copy):     " << &v[0] << std::endl;
}

void inspect_ref(const std::vector<double>& v) {
    std::cout << "inside (ref):      " << &v[0] << std::endl;
}


int main() {
    double cash = 1000.0;
    int trades = 3;

    std::cout <<"cash value:    " << cash << std::endl;
    std::cout << "cash address: "<< &cash << std::endl;
    std::cout <<"trades value: " << trades << std::endl;
    std::cout <<"trades address: " << &trades << std::endl;


    double* p = &cash; 
    std::cout <<"p holds:   " << p << std::endl;
    std::cout << "p points toL " << *p << std::endl;

    *p = 2000.0;
    std::cout<<"Cash is now: " << cash << std::endl;

    std::vector<double> prices{100.0, 102.5, 101.0};
    std::cout << "in main:           " << &prices[0] << std::endl;
    inspect_copy(prices);
    inspect_ref(prices);    

    double* heap_cash = new double(1000.0);
    std::cout << "heap value: " << *heap_cash << std::endl;
    std::cout << "heap addr: " << heap_cash << std::endl;
    delete heap_cash;   


    return 0;



}