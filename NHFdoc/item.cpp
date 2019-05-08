#include"arveres.h"
Item::Item(string name, double price, string description, SellingMetod sellingMethod )
    :name(name), price(price), description(description), sellingMethod(sellingMethod) {}
string Item::getName()
{
    return name;
}
double Item::getPrice()
{
    return price;
}
string Item::getDescription()
{
    return description;
}
SellingMetod Item::getSellingMethod()
{
    return sellingMethod;
}

