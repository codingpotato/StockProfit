#include "StockProfit.hpp"

StockProfit::StockProfit(vector<int> prices)
    : prices_(prices) {
}

vector<int> StockProfit::getMaxProfitsAfterBuy() {
    vector<int> maxProfitsAfterBuy;
    int maxProfits[2];
    maxProfits[0] = 0;
    maxProfits[1] = prices_[1] - prices_[0];
    for (unsigned int i = 0; i < prices_.size(); ++i) {
        int profit = -prices_[i];
        if (i > 1) {
            profit += maxProfits[i - 2];
        }
        maxProfitsAfterBuy.push_back(profit);
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
