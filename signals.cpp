#include <iostream>
#include <vector>
#include <string>

std::vector<double> moving_average (std::vector <double> prices , int window){
    std::vector<double> ma;
    for (int i= 0; i < prices.size () - window + 1; i++){
        double sum = 0.0;
        for (int j = i; j< i + window; j++){
            sum+= prices[j];
        }
        ma.push_back(sum/window);
    }

    return ma;
}

std::vector<std::string> signals(std::vector<double> prices, std::vector<double> ma, int window){
    std::vector<std::string> calls;
    for(int k = 0; k < ma.size(); k++) {
        double today = prices[k+window -1];
        if (today > ma[k]) {
            calls.push_back("BUY");
        } else {
            calls.push_back("SELL");
        }

        
    }

    return calls;
}

int main () {

std::vector<double> prices = {100.0, 102.5, 101.0, 105.3, 104.8, 108.2, 107.0};
std::vector<double> results = moving_average(prices, 3);
std::vector <std::string> calls = signals(prices, results, 3);


for (int i=0; i < calls.size(); i++){

    std::cout <<calls[i] << std::endl;

}


return 0;

}