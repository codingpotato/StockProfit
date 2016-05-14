#include "StockProfit.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(StockProfit, Empty_prices) {
    vector<int> prices;
    vector<vector<int>> expectTransactions;

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectTransactions, stockProfit.getTransactions());
}

TEST(StockProfit, Get_max_profit_after_buy_for_empty_prices) {
    vector<int> prices;
    vector<int> expectMaxProfitsAfterBuy;

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectMaxProfitsAfterBuy,
        stockProfit.getMaxProfitsAfterBuy());
}

TEST(StockProfit, One_day_prices) {
    int priceValues[] = {1};
    vector<int> prices(priceValues, priceValues + 1);
    vector<vector<int>> expectTransactions;
    int transactionValues[] = {PASS};
    expectTransactions.push_back(
        vector<int>(transactionValues, transactionValues + 1));
    
    StockProfit stockProfit(prices);
    ASSERT_EQ(expectTransactions, stockProfit.getTransactions());
}

TEST(StockProfit, Two_day_prices) {
    int pricesLength = 2;
    int priceValues[] = {1, 2};
    vector<int> prices(priceValues, priceValues + pricesLength);
    vector<vector<int>> expectTransactions;
    int transactionValues[] = {BUY, SELL};
    expectTransactions.push_back(
        vector<int>(transactionValues, transactionValues + pricesLength));
    
    StockProfit stockProfit(prices);
    ASSERT_EQ(expectTransactions, stockProfit.getTransactions());
}