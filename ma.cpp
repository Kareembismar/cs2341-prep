#include <iostream>
#include <vector>

std::vector<double> moving_average(std::vector<double> prices, int window){
    std::vector<double> ma;
    for (int i=0; i < prices.size() - window + 1; i++){
        double sum = 0.0;
        for (int j = i; j < i +window; j++) {
            sum += prices[j];

        }
        ma.push_back(sum/window);

    }

    return ma;
}

int main() {

std::vector<double> prices = {100.0, 102.5, 101.0, 105.3, 104.8, 108.2, 107.0};
std::vector<double> results = moving_average(prices, 3);

for (int i=0; i < results.size(); i++){
    std::cout << results[i] << std::endl;
}

return 0;

}