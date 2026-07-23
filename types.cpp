#include <iostream>
#include <string>


int main() {

std::string item = "Football Card";
double cost = 20.0;
double sold = 40.0;
int quantity = 1; 

double profit = (sold - cost) * quantity;

std::cout <<"Item " << item << std::endl;

std::cout << "Profit from Item " << profit << std::endl;


return 0; 
}