#include "StockProfit.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(StockProfit, Empty_prices)
{
    vector<int> prices;
    vector<vector<int>> expectTransactions;
    StockProfit stockProfit(prices);
    ASSERT_EQ(expectTransactions, stockProfit.getTransactions);
}
