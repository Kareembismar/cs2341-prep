#include <iostream>
#include <vector>
#include <string>

std::vector<double> moving_average (const std::vector <double>& prices , int window);
std::vector<std::string> signals(const std::vector<double>& prices, const std::vector<double>& ma, int window);
double simulation(const std::vector<double>& prices, const std::vector<std::string>& calls, int window, double starting_cash, double fee, int& trades);


int main () {

std::vector<double> prices = {100.0, 102.5, 101.0, 105.3, 104.8, 108.2, 107.0};
std::vector<double> results = moving_average(prices, 3);
std::vector <std::string> calls = signals(prices, results, 3);


for (size_t i=0; i < calls.size(); i++){

    std::cout <<calls[i] << std::endl;

}

int trades = 0;

double final_cash = simulation(prices, calls, 3, 1000.0, 0.001, trades);

std::cout << "Final: $" << final_cash << "(" << trades << "trades)" << std::endl;

return 0;

}