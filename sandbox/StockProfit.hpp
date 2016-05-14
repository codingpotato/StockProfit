#ifndef STOCK_PROFIT_INCLUDED
#define STOCK_PROFIT_INCLUDED

#include <vector>

using namespace std;

class StockProfit {

public:
    StockProfit(vector<int> prices);

private:
    vector<int> prices_;

};

#endif
