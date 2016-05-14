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
    int pricesLength = sizeof(priceValues) / sizeof(int);
    vector<int> prices(priceValues, priceValues + pricesLength);
    vector<vector<int>> expectTransactions;
    int transactionValues[] = {PASS};
    expectTransactions.push_back(
        vector<int>(transactionValues, transactionValues + pricesLength));
    
    StockProfit stockProfit(prices);
    ASSERT_EQ(expectTransactions, stockProfit.getTransactions());
}

TEST(StockProfit, Get_max_profit_after_buy_for_one_day_prices) {
    int priceValues[] = {1};
    int pricesLength = sizeof(priceValues) / sizeof(int);
    vector<int> prices(priceValues, priceValues + pricesLength);
    int maxProfitsAfterBuyValues[] = {-1};
    vector<int> expectMaxProfitsAfterBuy(maxProfitsAfterBuyValues,
        maxProfitsAfterBuyValues + pricesLength);

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectMaxProfitsAfterBuy,
        stockProfit.getMaxProfitsAfterBuy());
}

TEST(StockProfit, Two_day_prices) {
    int priceValues[] = {1, 2};
    int pricesLength = sizeof(priceValues) / sizeof(int);
    vector<int> prices(priceValues, priceValues + pricesLength);
    vector<vector<int>> expectTransactions;
    int transactionValues[] = {BUY, SELL};
    expectTransactions.push_back(
        vector<int>(transactionValues, transactionValues + pricesLength));
    
    StockProfit stockProfit(prices);
    ASSERT_EQ(expectTransactions, stockProfit.getTransactions());
}

TEST(StockProfit, Get_max_profit_after_buy_for_two_day_prices) {
    int priceValues[] = {1, 2};
    int pricesLength = sizeof(priceValues) / sizeof(int);
    vector<int> prices(priceValues, priceValues + pricesLength);
    int maxProfitsAfterBuyValues[] = {-1, -2};
    vector<int> expectMaxProfitsAfterBuy(maxProfitsAfterBuyValues,
        maxProfitsAfterBuyValues + pricesLength);

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectMaxProfitsAfterBuy,
        stockProfit.getMaxProfitsAfterBuy());
}

TEST(StockProfit, Get_max_profit_after_buy_for_four_day_prices) {
    int priceValues[] = {1, 2, 3, 4};
    int pricesLength = sizeof(priceValues) / sizeof(int);
    vector<int> prices(priceValues, priceValues + pricesLength);
    int maxProfitsAfterBuyValues[] = {-1, -2, -3, -3};
    vector<int> expectMaxProfitsAfterBuy(maxProfitsAfterBuyValues,
        maxProfitsAfterBuyValues + pricesLength);

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectMaxProfitsAfterBuy,
        stockProfit.getMaxProfitsAfterBuy());
}
