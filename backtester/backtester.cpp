#include <iostream>
#include <vector>
#include <string>

std::vector<double> moving_average (const std::vector <double>& prices , int window){
    std::vector<double> ma;
    for (size_t i= 0; i < prices.size () - window + 1; i++){
        double sum = 0.0;
        for (size_t j = i; j< i + window; j++){
            sum+= prices[j];
        }
        ma.push_back(sum/window);
    }

    return ma;
}

std::vector<std::string> signals(const std::vector<double>& prices, const std::vector<double>& ma, int window){
    std::vector<std::string> calls;
    for (size_t i = 0; i < ma.size(); i++) {
        double today = prices[i+window -1];
        if (today > ma[i]) {
            calls.push_back("BUY");
        } else {
            calls.push_back("SELL");
        }

        
    }

    return calls;
}


double simulation(const std::vector<double>& prices, const std::vector<std::string>& calls, int window, double starting_cash, double fee, int& trades)
{
    double cash = starting_cash;
    double shares = 0.0;
    trades = 0;

    for (size_t k=0; k < calls.size(); k++) {
        std::string call = calls[k];
        double today_price = prices[k + window-1];
        if (call == "BUY" && cash > 0){
            shares = (cash * (1-fee))/today_price;
            cash = 0.0;
            trades ++;
        }   

        else if (call == "SELL" && shares > 0){
            cash = shares * today_price * (1-fee);
            shares = 0.0;
            trades++;

        }

    }

    if (shares > 0) {
        cash = shares * prices[prices.size() - 1] * (1-fee);
        shares = 0.0;
    }
    return cash; 
}