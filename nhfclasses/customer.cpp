#include"arveres.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
Customer::Customer(string name, double balance)
    :name(name), balance(balance), items(Vektor<Item>(0))
{
    srand(time(NULL));
}
void Customer:: AddItem(const Item &i)
{
    items.Add(i);
}
Item Customer:: PopItem()
{
    return items.Pop();
}
string Customer::getName()
{
    return  name;
}
double Customer::getBalance()
{
    return balance;
}
Vektor<Item>Customer::getItems()
{
    return items;
}



double Customer::fRand(double min, double max)
{

double res = (int)min + rand() % ((int)(max - min)+1);

	return res;

}
bool Customer::isIntrested(){
return fRand(0, 1) > 0.5;
}
double Customer::Bid(double askingprice)
{

    if (isIntrested()&&askingprice <= balance)
    {

        return fRand(askingprice, balance);
    }
    return 0;
}
bool Customer::AcceptOffer(double price){

    return balance>=price&&isIntrested();

}



void Customer::Pay(double price)
{
    balance -= price;
}
