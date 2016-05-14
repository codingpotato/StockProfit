#include "StockProfit.hpp"

StockProfit::StockProfit(vector<int> prices)
    : prices_(prices) {
}

vector<int> StockProfit::getMaxProfitsAfterBuy() {
    vector<int> maxProfitsAfterBuy;
    if (prices_.size() == 1) {
        maxProfitsAfterBuy.push_back(-prices_[0]);
    }
    return maxProfitsAfterBuy;
}

vector<vector<int>> StockProfit::getTransactions() {
    vector<vector<int>> transactions;
    if (prices_.size() == 1) {
        vector<int> transaction;
        transaction.push_back(PASS);
        transactions.push_back(transaction);
    } else if (prices_.size() == 2) {
        vector<int> transaction;
        transaction.push_back(BUY);
        transaction.push_back(SELL);
        transactions.push_back(transaction);
    }
    return transactions;
}
