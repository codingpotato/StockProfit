#include "StockProfit.hpp"

StockProfit::StockProfit(vector<int> prices)
    : prices_(prices),
      maxProfitsAfterBuy_(prices.size()),
      maxProfitsWithStockInHand_(prices.size()),
      maxProfitsAfterSell_(prices.size()),
      maxProfits_(prices.size()) {
    calculateProfits();
}

vector<int> StockProfit::getMaxProfitsAfterBuy() {
    return maxProfitsAfterBuy_;
}

vector<int> StockProfit::getMaxProfitsWithStockInHand() {
    return maxProfitsWithStockInHand_;
}

vector<int> StockProfit::getMaxProfitsAfterSell() {
    return maxProfitsAfterSell_;
}

vector<int> StockProfit::getMaxProfits() {
    return maxProfits_;
}

void StockProfit::calculateProfits() {
    if (prices_.size() == 0) return;
    maxProfitsAfterBuy_[0] = -prices_[0];
    maxProfitsWithStockInHand_[0] = maxProfitsAfterBuy_[0];
    maxProfitsAfterSell_[0] = 0;
    maxProfits_[0] = 0;
    for (int i = 1; i < (int)prices_.size(); ++i) {
        maxProfitsAfterBuy_[i] = (i >= COOLDOWN_DISTANCE ?
            maxProfits_[i - COOLDOWN_DISTANCE] : 0) - prices_[i];
        maxProfitsWithStockInHand_[i] = max(
            maxProfitsWithStockInHand_[i - 1], maxProfitsAfterBuy_[i]);
        maxProfitsAfterSell_[i] = maxProfitsWithStockInHand_[i - 1]
            + prices_[i];
        maxProfits_[i] = max(maxProfits_[i - 1], maxProfitsAfterSell_[i]);
    }
}

void StockProfit::generateTransactionsByFindBuySellPair(
    int endOfDay, vector<int>& transaction) {
    if (endOfDay >= 1) {
        for (int sell = endOfDay; sell >= 0; --sell) {
            if (maxProfitsAfterSell_[sell] == maxProfits_[endOfDay]) {
                if (sell == 0) {
                    fillPass(transaction, 0, endOfDay);
                    transactions_.insert(transaction);
                    break;
                }
                transaction[sell] = SELL;
                if (sell + 1 < (int)prices_.size()) {
                    transaction[sell + 1] = COOLDOWN;
                    fillPass(transaction,
                        sell + COOLDOWN_DISTANCE, endOfDay);
                }
                for (int buy = sell - 1; buy >= 0; --buy) {
                    if (maxProfitsAfterBuy_[buy] + prices_[sell] == 
                        maxProfits_[sell]) {
                        transaction[buy] = BUY;
                        fillPass(transaction, buy + 1, sell - 1);
                        generateTransactionsByFindBuySellPair(
                            buy - COOLDOWN_DISTANCE, transaction);
                    }
                }
            }
        }
    } else {
        fillPass(transaction, 0, endOfDay);
        transactions_.insert(transaction);
    }
}

void StockProfit::fillPass(vector<int>& transaction,
    int fromDay, int toDay) {
    for (int i = fromDay; i <= toDay; ++i) {
        transaction[i] = PASS;
    }
}

set<vector<int>> StockProfit::getTransactions() {
    if (prices_.size() > 0) {
        vector<int> transaction(prices_.size());
        generateTransactionsByFindBuySellPair(
            prices_.size() - 1, transaction);
    }
    return transactions_;
}