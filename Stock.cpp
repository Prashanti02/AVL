//
//  Stock.cpp
//  AVL
//
//  Created by Prashanti Pokharel on 11/8/21.
//

#include "Stock.h"
//***********************************************************************************************
using namespace std;
//****************************************************************************************************
Stock::Stock(const string & name, const string & symbol, double price)
{
    stockName = name;
    stockSymbol = symbol;
    stockPrice = price;
}
//****************************************************************************************************
Stock::Stock(const Stock & s)
{
    stockName = s.stockName;
    stockSymbol = s.stockSymbol;
    stockPrice = s.stockPrice;
}
//****************************************************************************************************
void Stock::getData() const
{
    cout << stockName << " " << stockSymbol << " " << stockPrice << endl;
}
//****************************************************************************************************
 std::ostream &operator << (ostream & File, const Stock & s)
{
     File << s.stockName << endl << s.stockSymbol << endl << s.stockPrice << endl;
     return File;
}
 //****************************************************************************************************
// int Stock:: hash(int hashTableSize) const
// {
//     int index ;
//     index = stockSymbol.size() % hashTableSize;
//    return index;
// }
