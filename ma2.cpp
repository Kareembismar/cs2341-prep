#include <iostream>
#include <vector>

std::vector<double> moving_averages(std::vector<double> prices, int windows){
    std::vector<double> ma;
    for(int i=0; i < prices.size () - windows + 1; i++){
    double sum = 0.0;
        for (int j = i; j< i + windows; j++){
            sum += prices[j];

        }
        ma.push_back(sum/windows);
    }

return ma;

}

int main() {


std::vector<double> prices = {100.0, 102.5, 101.0, 105.3, 104.8, 108.2, 107.0};
std::vector<double> results = moving_averages(prices, 3);

for (int i=0; i < results.size(); i++){

    std::cout << results[i] << std::endl; 
}

return 0;
}