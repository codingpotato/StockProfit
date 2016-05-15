#ifndef STOCK_PROFIT_INCLUDED
#define STOCK_PROFIT_INCLUDED

#include <set>
#include <vector>

using namespace std;


enum Transaction {
    PASS, BUY, SELL, COOLDOWN
};


class StockProfit {

public:
    StockProfit(vector<int> prices);

    vector<int> getMaxProfitsAfterBuy();
    vector<int> getMaxProfitsWithStockInHand();
    vector<int> getMaxProfitsAfterSell();
    vector<int> getMaxProfits();
    set<vector<int>> getTransactions();

private:
    void calculateProfits();
    void generateTransactionsByFindBuySellPair(
        int endOfDay, vector<int>& transaction);
    void fillPass(vector<int>& transaction, int fromDay, int toDay);

    vector<int> prices_;
    vector<int> maxProfitsAfterBuy_;
    vector<int> maxProfitsWithStockInHand_;
    vector<int> maxProfitsAfterSell_;
    vector<int> maxProfits_;

    set<vector<int>> transactions_;

    static const int COOLDOWN_DISTANCE = 2;

};

#endif