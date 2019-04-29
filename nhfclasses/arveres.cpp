
#include "arveres.h"

using namespace std;
string separator="-----------";
ostream& operator <<(ostream & os, Item i)
{

    return os<<fixed
           <<"Targy"<<endl
           <<"Nev:"<<i.getName() << endl
           <<"Kikialtasi ar:"<<i.getPrice() << endl
           << "Leiras:"<<i.getDescription() << endl
           <<"Aukcio modja:"<<i.getSellingMethod()<<endl
           <<separator<<endl;


}
ostream& operator <<(ostream & os, Customer c)
{
    os<<"Vasarlo"<<endl
      <<"Nev:"<<c.getName() << endl
      <<"Egyenleg:"<<fixed<< c.getBalance() <<" Ft"<< endl
      <<"Megvett targyak:"<<endl;


    Vektor<Item>items = c.getItems();

    for (size_t i = 0; i < items.size(); i++)
    {
        os << items[i];
    }
    os<<separator<<endl;

    return os;
}
string MethodNames[] = { { "English" },{ "Dutch" },{ "Blind" } };
ostream& operator <<(ostream & os,  SellingMetod s)
{
    return os << MethodNames[s];
}


ostream& operator <<(ostream & os, Vektor<Item>items)
{
for (size_t i = 0; i <items.size(); i++)
    {
        os << items[i];
    }
    os<<separator<<endl;
    return os;
}
ostream& operator <<(ostream & os, Vektor<Customer>customers)
{
for (size_t i = 0; i <customers.size(); i++)
    {
        os << customers[i];
    }
    os<<separator<<endl;
    return os;
}
ostream& operator <<(ostream & os, Auction a)
{   os<<"Aukcio"<<endl;
    os<< "Eladano targyak:" <<endl<<a.getItemsForsale();
    os<<"Eladott targyak:" <<endl<<a.getItemsSold();
    os<<"Megmaradt targyak:" <<endl<<a.getItemsLeft();
    os<< "Vasarlok:" << endl<<a.getCustomers();

    return os;
}







