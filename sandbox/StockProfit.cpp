#include "StockProfit.hpp"

StockProfit::StockProfit(vector<int> prices)
    : prices_(prices) {
}

vector<vector<int>> StockProfit::getTransactions() {
    vector<vector<int>> transactions;
    if (prices.size() == 1) {
        vector<int> transaction;
        transaction.push_bakc(PASS);
        transactions.push_back(transaction);
    }
    return transactions;
}
