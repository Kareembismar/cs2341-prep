#include <iostream>
#include <string>
#include <vector>

struct Trade{
    std::string side;
    double price;
    int quantity;
};

int main(){

    std::vector<Trade> trades;
    Trade t;

    t.side = "BUY";
    t.price = 105.3;
    t.quantity = 9;
    trades.push_back(t);

    t.side = "SELL";
    t.price = 106.7;
    t.quantity = 5;
    trades.push_back(t);


    t.side = "BUY";
    t.price = 107.1;
    t.quantity = 3;
    trades.push_back(t);


    for(std::size_t i = 0; i < trades.size(); ++i){
        std::cout << "Trade: " << i << '\n';
        std::cout << "Side:     " << trades[i].side     << '\n';
        std::cout << "Price:    " << trades[i].price    << '\n';
        std::cout << "Quantity: " << trades[i].quantity << '\n';
    }


    return 0;
}