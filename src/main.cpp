#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include "ItemCategory.hpp"
#include "Item.hpp"
#include "Tax.hpp"
using namespace std;

vector<Item> basket; //stores all items of a basket

vector<string> order; // stores each order of item

Tax tax;

void printReceipt()
{
    cout << "------------------------------------------RECEIPT-----------------------------------------" << endl;
    //print order of each item
    for (auto s : order)
        cout << s << "\n";

    double salesTax = 0.0, total = 0.0;
    for (auto item : basket)
    {
        total += item.getPrice();
        salesTax += tax.getTaxOnItem(item);
    }
    total += salesTax;
    //print sales tax and total bill
    cout << "Sales Tax: " << salesTax << "\n";
    cout << "Total: " << total << "\n";
    cout << "------------------------------------------------------------------------------------------" << endl;
}
int main()
{
    string s;

    cout << "Enter your order on each line:\nAt the end type 'stop' on a new line to finish" << endl;

    //read whole line using getline
    while (getline(cin, s))
    {
        //stop if getline gives "stop"
        if (s == "stop")
            break;

        //push orders to our vector
        order.push_back(s);

        //using string stream to iterate over words of string
        stringstream ss(s);
        string temp;
        ItemCategory itemCategory = ItemCategory::General;
        bool imported = false;

        while (ss >> temp)
        {

            //decide whether item is imported or not and items category based on words in given sample
            if (temp == "imported")
                imported = true;
            if (temp == "chocolates" or temp == "chocolate")
                itemCategory = ItemCategory::Food;
            else if (temp == "pills")
                itemCategory = ItemCategory::Medical;
            else if (temp == "book")
                itemCategory = ItemCategory::Book;
        }
        //get price from last word of string
        double price = stod(temp);

        // push item object to basket
        basket.push_back(Item(itemCategory, price, imported));
    }

    printReceipt();

    return 0;
}