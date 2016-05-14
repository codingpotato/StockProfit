#include "StockProfit.hpp"

StockProfit::StockProfit(vector<int> prices)
    : prices_(prices),
      maxProfitsAfterBuy_(prices.size()),
      maxProfitsWithStockInHand_(prices.size()),
      maxProfits_(prices.size()) {
    calculateProfits();
}

vector<int> StockProfit::getMaxProfitsAfterBuy() {
    return maxProfitsAfterBuy_;
}

vector<int> StockProfit::getMaxProfitsWithStockInHand() {
    return maxProfitsWithStockInHand_;
}

vector<int> StockProfit::getMaxProfits() {
    return maxProfits_;
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

void StockProfit::calculateProfits() {
    if (prices_.size() > 1) {
        maxProfits_[0] = 0;
        maxProfits_[1] = max(maxProfits_[0], prices_[1] - prices_[0]);
    }
    for (unsigned int i = 0; i < prices_.size(); ++i) {
        int profit = -prices_[i];
        if (i > 1) {
            profit += maxProfits_[i - 2];
        }
        maxProfitsAfterBuy_[i] = profit;
        maxProfitsWithStockInHand_[i] = profit;
    }
}
