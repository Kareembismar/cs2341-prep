#include <iostream>


double percent_change(double old_p, double new_p) {

    return ((new_p - old_p)/old_p);

}

int main() {


std::cout << percent_change(100.0, 103.0) << std::endl;
std::cout << percent_change(40.0, 30.0) << std::endl;
std::cout << "Trap A: " << percent_change(100, 103) << std::endl;
std::cout << "Trap B: " << (103 - 100) / 100.0 << std::endl;

return 0; 

}