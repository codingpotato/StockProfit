#include "StockProfit.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(StockProfit, Empty_prices) {
    vector<int> prices;
    set<vector<int>> expectTransactions;

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
    set<vector<int>> expectTransactions;
    int transactionValues[] = {PASS};
    expectTransactions.insert(
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
    set<vector<int>> expectTransactions;
    int transactionValues[] = {BUY, SELL};
    expectTransactions.insert(
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
    int pricesValue[] = {1, 2};
    int pricesLength = sizeof(pricesValue) / sizeof(int);
    vector<int> prices(pricesValue, pricesValue + pricesLength);
    int maxProfitsValue[] = {0, 1};
    vector<int> expectMaxProfits(maxProfitsValue,
        maxProfitsValue + pricesLength);

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectMaxProfits, stockProfit.getMaxProfits());
}

TEST(StockProfit, Get_max_profits_for_two_day_descending_prices) {
    int pricesValue[] = {2, 1};
    int pricesLength = sizeof(pricesValue) / sizeof(int);
    vector<int> prices(pricesValue, pricesValue + pricesLength);
    int maxProfitsValue[] = {0, 0};
    vector<int> expectMaxProfits(maxProfitsValue,
        maxProfitsValue + pricesLength);

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectMaxProfits, stockProfit.getMaxProfits());
}

TEST(StockProfit, Three_day_prices) {
    int pricesValue[] = {1, 2, 3};
    int pricesLength = sizeof(pricesValue) / sizeof(int);
    vector<int> prices(pricesValue, pricesValue + pricesLength);
    set<vector<int>> expectTransactions;
    int transactionValues[] = {BUY, PASS, SELL};
    expectTransactions.insert(
        vector<int>(transactionValues, transactionValues + pricesLength));
    
    StockProfit stockProfit(prices);
    ASSERT_EQ(expectTransactions, stockProfit.getTransactions());
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

TEST(StockProfit, Get_transactions) {
    int pricesValue[] = {1, 2, 3, 1, 3};
    int pricesLength = sizeof(pricesValue) / sizeof(int);
    vector<int> prices(pricesValue, pricesValue + pricesLength);
    set<vector<int>> expectTransactions;
    int transactionValues[] = {BUY, SELL, COOLDOWN, BUY, SELL};
    expectTransactions.insert(
        vector<int>(transactionValues, transactionValues + pricesLength));
    
    StockProfit stockProfit(prices);
    ASSERT_EQ(expectTransactions, stockProfit.getTransactions());
}

TEST(StockProfit, Get_max_profits_after_buy) {
    int pricesValue[] = {1, 2, 3, 1, 3};
    int pricesLength = sizeof(pricesValue) / sizeof(int);
    vector<int> prices(pricesValue, pricesValue + pricesLength);
    int maxProfitsAfterBuyValues[] = {-1, -2, -3, 0, -1};
    vector<int> expectMaxProfitsAfterBuy(maxProfitsAfterBuyValues,
        maxProfitsAfterBuyValues + pricesLength);

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectMaxProfitsAfterBuy,
        stockProfit.getMaxProfitsAfterBuy());
}

TEST(StockProfit, Get_max_profits_after_sell) {
    int pricesValue[] = {1, 2, 3, 1, 3};
    int pricesLength = sizeof(pricesValue) / sizeof(int);
    vector<int> prices(pricesValue, pricesValue + pricesLength);
    int maxProfitsAfterSellValues[] = {0, 1, 2, 0, 3};
    vector<int> expectMaxProfitsAfterSell(maxProfitsAfterSellValues,
        maxProfitsAfterSellValues + pricesLength);

    StockProfit stockProfit(prices);
    ASSERT_EQ(expectMaxProfitsAfterSell,
        stockProfit.getMaxProfitsAfterSell());
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

TEST(StockProfit, Get_transactions_not_last_sell) {
    int pricesValue[] = {1, 2, 3, 1};
    int pricesLength = sizeof(pricesValue) / sizeof(int);
    vector<int> prices(pricesValue, pricesValue + pricesLength);
    set<vector<int>> expectTransactions;
    int transactionValues[] = {BUY, PASS, SELL, COOLDOWN};
    expectTransactions.insert(
        vector<int>(transactionValues, transactionValues + pricesLength));
    
    StockProfit stockProfit(prices);
    ASSERT_EQ(expectTransactions, stockProfit.getTransactions());
}

TEST(StockProfit, Get_transactions_multipul_sell) {
    int pricesValue[] = {1, 1};
    int pricesLength = sizeof(pricesValue) / sizeof(int);
    vector<int> prices(pricesValue, pricesValue + pricesLength);
    set<vector<int>> expectTransactions;
    int transactionValues1[] = {BUY, SELL};
    expectTransactions.insert(vector<int>(
        transactionValues1, transactionValues1 + pricesLength));
    int transactionValues2[] = {PASS, PASS};
    expectTransactions.insert(vector<int>(
        transactionValues2, transactionValues2 + pricesLength));
    
    StockProfit stockProfit(prices);
    ASSERT_EQ(expectTransactions, stockProfit.getTransactions());
}

TEST(StockProfit, Get_transactions_multiple_buy) {
    int pricesValue[] = {1, 1, 1};
    int pricesLength = sizeof(pricesValue) / sizeof(int);
    vector<int> prices(pricesValue, pricesValue + pricesLength);
    set<vector<int>> expectTransactions;
    int transactionValues1[] = {BUY, SELL, COOLDOWN};
    expectTransactions.insert(vector<int>(
        transactionValues1, transactionValues1 + pricesLength));
    int transactionValues2[] = {BUY, PASS, SELL};
    expectTransactions.insert(vector<int>(
        transactionValues2, transactionValues2 + pricesLength));
    int transactionValues3[] = {PASS, BUY, SELL};
    expectTransactions.insert(vector<int>(
        transactionValues3, transactionValues3 + pricesLength));
    int transactionValues4[] = {PASS, PASS, PASS};
    expectTransactions.insert(vector<int>(
        transactionValues4, transactionValues4 + pricesLength));
    
    StockProfit stockProfit(prices);
    ASSERT_EQ(expectTransactions, stockProfit.getTransactions());
}
