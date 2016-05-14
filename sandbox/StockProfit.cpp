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
    if (prices_.size() == 0) return;
    if (prices_.size() > 1) {
        maxProfits_[0] = 0;
        maxProfits_[1] = max(maxProfits_[0], prices_[1] - prices_[0]);
    }
    maxProfitsAfterBuy_[0] = -prices_[0];
    maxProfitsWithStockInHand_[0] = maxProfitsAfterBuy_[0];
    for (unsigned int i = 1; i < prices_.size(); ++i) {
        maxProfitsAfterBuy_[i] = (i > 1 ? maxProfits_[i - 2] : 0)
            - prices_[i];
        maxProfitsWithStockInHand_[i] = max(maxProfitsAfterBuy_[i - 1],
            maxProfitsAfterBuy_[i];
    }
}