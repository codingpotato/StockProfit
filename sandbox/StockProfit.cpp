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
    for (unsigned int i = 1; i < prices_.size(); ++i) {
        maxProfitsAfterBuy_[i] = (i > 1 ? maxProfits_[i - 2] : 0)
            - prices_[i];
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
        for (int sell = endOfDay; sell >= 1; --sell) {
            if (maxProfits_[sell] == maxProfitsAfterSell_[sell]) {
                transaction[sell] = SELL;
                if (sell + 1 < prices_.size()) {
                    transaction[sell + 1] = COOLDOWN;
                    for (unsigned int i = sell + 2; i <= endOfDay; ++i) {
                        transaction[i] = PASS;
                    }
                }
                for (int buy = sell - 1; buy >= 0; --buy) {
                    if (maxProfitsAfterBuy_[buy] + prices_[sell] == 
                        maxProfits_[sell]) {
                        transaction[buy] = BUY;
                        for (unsigned int i = buy + 1; i < sell; ++i) {
                            transaction[i] = PASS;
                        }
                        generateTransactionsByFindBuySellPair(
                            buy - 2, transaction);
                        break;
                    }
                }
                break;
            }
        }
    } else {
        transactions_.push_back(transaction);
    }
}

vector<vector<int>> StockProfit::getTransactions() {
    if (prices_.size() == 0) {
        return transactions_;
    } else if (prices_.size() == 1) {
        vector<int> transaction;
        transaction.push_back(PASS);
        transactions_.push_back(transaction);
    } else {
        vector<int> transaction(prices_.size());
        generateTransactionsByFindBuySellPair(
            prices_.size() - 1, transaction);
    }
    return transactions_;
}