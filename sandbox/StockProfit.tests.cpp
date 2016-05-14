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
    vector<int> prices({1}, 1);
    vector<vector<int>> expectTransactions;
    expectTransactions.push_back(vector<int>({PASS}, 1));
    StockProfit stockProfit(prices);
    ASSERT_EQ(expectTransactions, stockProfit.getTransactions());
}
