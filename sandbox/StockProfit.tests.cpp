#include "StockProfit.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(StockProfit, Empty_prices) {
    vector<int> prices;
    vector<vector<int>> expectTransactions;

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectTransactions, stockProfit.getTransactions());
}

TEST(StockProfit, Get_max_profits_after_buy_for_empty_prices) {
    vector<int> prices;
    vector<int> expectMaxProfitsAfterBuy;

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectMaxProfitsAfterBuy,
        stockProfit.getMaxProfitsAfterBuy());
}

TEST(StockProfit, Get_max_profits_with_stock_in_hand_for_empty_prices) {
    vector<int> prices;
    vector<int> expectMaxProfitsWithStockInHand;

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectMaxProfitsWithStockInHand,
        stockProfit.getMaxProfitsWithStockInHand());
}

TEST(StockProfit, Get_max_profits_after_sell_for_empty_prices) {
    vector<int> prices;
    vector<int> expectMaxProfitsAfterSell;

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectMaxProfitsAfterSell,
        stockProfit.getMaxProfitsAfterSell());
}

TEST(StockProfit, Get_max_profits_for_empty_prices) {
    vector<int> prices;
    vector<int> expectMaxProfits;

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectMaxProfits, stockProfit.getMaxProfits());
}

TEST(StockProfit, One_day_prices) {
    int pricesValue[] = {1};
    int pricesLength = sizeof(pricesValue) / sizeof(int);
    vector<int> prices(pricesValue, pricesValue + pricesLength);
    vector<vector<int>> expectTransactions;
    int transactionValues[] = {PASS};
    expectTransactions.push_back(
        vector<int>(transactionValues, transactionValues + pricesLength));
    
    StockProfit stockProfit(prices);
    ASSERT_EQ(expectTransactions, stockProfit.getTransactions());
}

TEST(StockProfit, Get_max_profits_after_buy_for_one_day_prices) {
    int pricesValue[] = {1};
    int pricesLength = sizeof(pricesValue) / sizeof(int);
    vector<int> prices(pricesValue, pricesValue + pricesLength);
    int maxProfitsAfterBuyValues[] = {-1};
    vector<int> expectMaxProfitsAfterBuy(maxProfitsAfterBuyValues,
        maxProfitsAfterBuyValues + pricesLength);

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectMaxProfitsAfterBuy,
        stockProfit.getMaxProfitsAfterBuy());
}

TEST(StockProfit, Get_max_profits_with_stock_in_hand_for_one_day_prices) {
    int pricesValue[] = {1};
    int pricesLength = sizeof(pricesValue) / sizeof(int);
    vector<int> prices(pricesValue, pricesValue + pricesLength);
    int maxProfitsWithStockInHandValues[] = {-1};
    vector<int> expectMaxProfitsWithStockInHand(
        maxProfitsWithStockInHandValues,
        maxProfitsWithStockInHandValues + pricesLength);

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectMaxProfitsWithStockInHand,
        stockProfit.getMaxProfitsWithStockInHand());
}

TEST(StockProfit, Get_max_profits_after_sell_for_one_day_prices) {
    int pricesValue[] = {1};
    int pricesLength = sizeof(pricesValue) / sizeof(int);
    vector<int> prices(pricesValue, pricesValue + pricesLength);
    int maxProfitsAfterSellValues[] = {0};
    vector<int> expectMaxProfitsAfterSell(maxProfitsAfterSellValues,
        maxProfitsAfterSellValues + pricesLength);

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectMaxProfitsAfterSell,
        stockProfit.getMaxProfitsAfterSell());
}

TEST(StockProfit, Get_max_profits_for_one_day_prices) {
    int pricesValue[] = {1};
    int pricesLength = sizeof(pricesValue) / sizeof(int);
    vector<int> prices(pricesValue, pricesValue + pricesLength);
    int maxProfitsValue[] = {0};
    vector<int> expectMaxProfits(maxProfitsValue,
        maxProfitsValue + pricesLength);

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectMaxProfits, stockProfit.getMaxProfits());
}

TEST(StockProfit, Two_day_prices) {
    int pricesValue[] = {1, 2};
    int pricesLength = sizeof(pricesValue) / sizeof(int);
    vector<int> prices(pricesValue, pricesValue + pricesLength);
    vector<vector<int>> expectTransactions;
    int transactionValues[] = {BUY, SELL};
    expectTransactions.push_back(
        vector<int>(transactionValues, transactionValues + pricesLength));
    
    StockProfit stockProfit(prices);
    ASSERT_EQ(expectTransactions, stockProfit.getTransactions());
}

TEST(StockProfit, Get_max_profits_after_buy_for_two_day_prices) {
    int pricesValue[] = {1, 2};
    int pricesLength = sizeof(pricesValue) / sizeof(int);
    vector<int> prices(pricesValue, pricesValue + pricesLength);
    int maxProfitsAfterBuyValues[] = {-1, -2};
    vector<int> expectMaxProfitsAfterBuy(maxProfitsAfterBuyValues,
        maxProfitsAfterBuyValues + pricesLength);

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectMaxProfitsAfterBuy,
        stockProfit.getMaxProfitsAfterBuy());
}

TEST(StockProfit, Get_max_profits_with_stock_in_hand_for_two_day_prices) {
    int pricesValue[] = {1, 2};
    int pricesLength = sizeof(pricesValue) / sizeof(int);
    vector<int> prices(pricesValue, pricesValue + pricesLength);
    int maxProfitsWithStockInHandValues[] = {-1, -1};
    vector<int> expectMaxProfitsWithStockInHand(
        maxProfitsWithStockInHandValues,
        maxProfitsWithStockInHandValues + pricesLength);

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectMaxProfitsWithStockInHand,
        stockProfit.getMaxProfitsWithStockInHand());
}

TEST(StockProfit, Get_max_profits_after_sell_for_two_day_prices) {
    int pricesValue[] = {1, 2};
    int pricesLength = sizeof(pricesValue) / sizeof(int);
    vector<int> prices(pricesValue, pricesValue + pricesLength);
    int maxProfitsAfterSellValues[] = {0, 1};
    vector<int> expectMaxProfitsAfterSell(maxProfitsAfterSellValues,
        maxProfitsAfterSellValues + pricesLength);

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectMaxProfitsAfterSell,
        stockProfit.getMaxProfitsAfterSell());
}

TEST(StockProfit, Get_max_profits_for_two_day_prices) {
    int pricesValue[] = {2, 1};
    int pricesLength = sizeof(pricesValue) / sizeof(int);
    vector<int> prices(pricesValue, pricesValue + pricesLength);
    int maxProfitsValue[] = {0, 0};
    vector<int> expectMaxProfits(maxProfitsValue,
        maxProfitsValue + pricesLength);

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectMaxProfits, stockProfit.getMaxProfits());
}

TEST(StockProfit, Get_max_profits_after_buy_for_three_day_prices) {
    int pricesValue[] = {1, 2, 3};
    int pricesLength = sizeof(pricesValue) / sizeof(int);
    vector<int> prices(pricesValue, pricesValue + pricesLength);
    int maxProfitsAfterBuyValues[] = {-1, -2, -3};
    vector<int> expectMaxProfitsAfterBuy(maxProfitsAfterBuyValues,
        maxProfitsAfterBuyValues + pricesLength);

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectMaxProfitsAfterBuy,
        stockProfit.getMaxProfitsAfterBuy());
}

TEST(StockProfit,
    Get_max_profits_with_stock_in_hand_for_three_day_prices) {
    int pricesValue[] = {1, 2, 3};
    int pricesLength = sizeof(pricesValue) / sizeof(int);
    vector<int> prices(pricesValue, pricesValue + pricesLength);
    int maxProfitsWithStockInHandValues[] = {-1, -1, -1};
    vector<int> expectMaxProfitsWithStockInHand(
        maxProfitsWithStockInHandValues,
        maxProfitsWithStockInHandValues + pricesLength);

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectMaxProfitsWithStockInHand,
        stockProfit.getMaxProfitsWithStockInHand());
}

TEST(StockProfit, Get_max_profits_after_sell_for_three_day_prices) {
    int pricesValue[] = {1, 2, 3};
    int pricesLength = sizeof(pricesValue) / sizeof(int);
    vector<int> prices(pricesValue, pricesValue + pricesLength);
    int maxProfitsAfterSellValues[] = {0, 1, 2};
    vector<int> expectMaxProfitsAfterSell(maxProfitsAfterSellValues,
        maxProfitsAfterSellValues + pricesLength);

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectMaxProfitsAfterSell,
        stockProfit.getMaxProfitsAfterSell());
}

TEST(StockProfit, Get_max_profits_for_three_day_prices) {
    int pricesValue[] = {1, 2, 3};
    int pricesLength = sizeof(pricesValue) / sizeof(int);
    vector<int> prices(pricesValue, pricesValue + pricesLength);
    int maxProfitsValue[] = {0, 1, 2};
    vector<int> expectMaxProfits(maxProfitsValue,
        maxProfitsValue + pricesLength);

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectMaxProfits, stockProfit.getMaxProfits());
}

TEST(StockProfit, Get_max_profits_after_buy_for_four_day_prices) {
    int pricesValue[] = {1, 2, 3, 4};
    int pricesLength = sizeof(pricesValue) / sizeof(int);
    vector<int> prices(pricesValue, pricesValue + pricesLength);
    int maxProfitsAfterBuyValues[] = {-1, -2, -3, -3};
    vector<int> expectMaxProfitsAfterBuy(maxProfitsAfterBuyValues,
        maxProfitsAfterBuyValues + pricesLength);

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectMaxProfitsAfterBuy,
        stockProfit.getMaxProfitsAfterBuy());
}

TEST(StockProfit, Get_max_profits_for_four_day_prices) {
    int pricesValue[] = {1, 2, 3, 4};
    int pricesLength = sizeof(pricesValue) / sizeof(int);
    vector<int> prices(pricesValue, pricesValue + pricesLength);
    int maxProfitsValue[] = {0, 1, 2, 3};
    vector<int> expectMaxProfits(maxProfitsValue,
        maxProfitsValue + pricesLength);

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectMaxProfits, stockProfit.getMaxProfits());
}

TEST(StockProfit, Get_max_profits) {
    int pricesValue[] = {1, 2, 3, 1, 3};
    int pricesLength = sizeof(pricesValue) / sizeof(int);
    vector<int> prices(pricesValue, pricesValue + pricesLength);
    int maxProfitsValue[] = {0, 1, 2, 2, 3};
    vector<int> expectMaxProfits(maxProfitsValue,
        maxProfitsValue + pricesLength);

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectMaxProfits, stockProfit.getMaxProfits());
}
