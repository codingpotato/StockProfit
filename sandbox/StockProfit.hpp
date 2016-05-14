#ifndef STOCK_PROFIT_INCLUDED
#define STOCK_PROFIT_INCLUDED

#include <vector>

using namespace std;


enum Transaction {
    PASS, BUY, SELL, COOLDOWN
};


class StockProfit {

public:
    StockProfit(vector<int> prices);

    vector<int> getMaxProfitsAfterBuy();
    vector<vector<int>> getTransactions();

private:
    void calculateProfits();

    vector<int> prices_;
    vector<int> maxProfitsAfterBuy_;
    vector<int> maxProfits_;

};

#endif