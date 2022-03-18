//
//  Stock.h
//  AVL
//
//  Created by Prashanti Pokharel on 11/8/21.
//

#include "Tree.h"
#ifndef Stock_h
#define Stock_h

class Stock
{
private:
    std::string stockName;
    std::string stockSymbol;
    double stockPrice;
    public:
    Stock(const std::string & name = " ", const std::string & symbol = " ", double price = 0);
      Stock(const Stock & s);
        void getData () const;
    void setName(std::string name)
        {
            stockName = name;
        }
    
        void setSymbol(std::string symbol)
        {
            stockSymbol = symbol;
        }
    
        void setPrice(double price)
        {
            stockPrice = price;
        }
        std::string getName() const;
        std::string getSymbol() const;
        double getPrice() const;
        bool operator==(const Stock& rhs) const;
        bool operator!=(const Stock& rhs) const;
        bool operator>(const Stock& rhs) const;
        bool operator<(const Stock& rhs) const;
        friend std::ostream& operator << (std::ostream & out, const Stock& s);
    };
    
    
        inline
        std::string Stock::getName() const
        {
            return stockName;
        }
        inline
        std::string Stock:: getSymbol() const{
        return stockSymbol;
        }
        inline
        double Stock::getPrice() const
        {
            return stockPrice;
        }
    inline
    bool Stock::operator==(const Stock& rhs) const
    {
        return (this->stockSymbol == rhs.stockSymbol);
    }
    
    inline
    bool Stock::operator!=(const Stock& rhs) const
    {
       return (this->stockSymbol != rhs.stockSymbol);
    
    }
    
    inline
    bool Stock::operator>(const Stock& rhs) const
    {
       return (this->stockSymbol > rhs.stockSymbol);
    }
    
    inline
    bool Stock::operator<(const Stock& rhs) const
    {
      return (this->stockSymbol < rhs.stockSymbol);
    }

#endif /* Stock_h */




