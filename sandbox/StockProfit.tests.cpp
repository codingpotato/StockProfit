#include "StockProfit.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(StockProfit, Empty_prices)
{
    vector<int> prices;
    vector<vector<int>> expectTransactions;
    StockProfit stockProfit(prices);
    ASSERT_EQ(expectTransactions, stockProfit.getTransactions());
}

TEST(StockProfit, One_day_prices)
{
    int priceValues[] = {1};
    vector<int> prices(priceValues, priceValues + 1);
    vector<vector<int>> expectTransactions;
    int transactionValues = {PASS};
    expectTransactions.push_back(
        vector<int>(transactionValues, transactionValues + 1));
    
    StockProfit stockProfit(prices);
    ASSERT_EQ(expectTransactions, stockProfit.getTransactions());
}
