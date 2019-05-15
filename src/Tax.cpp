#include <iostream>
#include <math.h>
#include "Item.hpp"
#include "Tax.hpp"
using namespace std;

double Tax::getTaxOnItem(Item item)
{
    double tax = 0.0;

    //if item is imported ,apply import tax
    if (item.isImported())
        tax += round(item.getPrice() * IMPORT_RATE);

    //if item category is from category on which basic sales can be implemented, apply basic sales tax;
    for (auto c : canTaxOnCategory)
    {
        if (item.getItemCategory() == c)
            tax += round(item.getPrice() * BASIC_RATE);
    }

    return tax;
}

//Round up to nearest 0.05
double Tax::round(double value)
{
    return ceil(value * 20) / 20;
}
