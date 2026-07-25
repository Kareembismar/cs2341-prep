#include <iostream>
#include <vector>

double percent_change(double old_p, double new_p) {

    return ((new_p - old_p)/old_p);

}

std::vector<double> daily_returns(std::vector<double>prices){
    std::vector<double> basket;
    for (int i=1; i < prices.size(); i++){
        basket.push_back(percent_change(prices[i-1],prices[i]));
    }
    return basket; 

}

int main() {


std::vector<double> prices = {100.0, 102.5, 101.0, 105.3, 104.8, 108.2, 107.0};
std::vector<double> result = daily_returns(prices);


for (int i=0; i < result.size(); i++) {

std::cout<< result[i] << std::endl;

}


return 0; 

}


