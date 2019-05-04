

#ifndef ARVERES_H
#define ARVERES_H
#include"arveres.h"
#include<iostream>
#include<string>


using namespace std;
enum SellingMetod
{
    English, Dutch, Blind

};
class Item
{
    string name;
    double price;
    string description;
    SellingMetod sellingMethod;

public:
    Item(string name = "Generic_item", double price = 10, string description = "Generic_description", SellingMetod sellingMethod = English);
    string getName();
    double getPrice();
    string getDescription();
    SellingMetod getSellingMethod();
private:

};
template<typename T>class Vektor
{
    T *data;
    size_t siz;

public:

    explicit Vektor(size_t meret = 0);
    Vektor(const Vektor &v);
    Vektor&	operator =(const Vektor &v);
    size_t size() const;
    T& operator[](size_t index);
    T const& operator[](size_t index) const;
    void Add(T const& new_val);
    void Delete(size_t index);
    T Pop();
    ~Vektor();
};
class Customer
{
    string name;
    double balance;
    Vektor<Item>items;


public:
    Customer(string name = "Generic_Name", double balance = 1000);

    void AddItem(const Item &i);
    Item PopItem();
    string getName();
    double getBalance();
    Vektor<Item>getItems();
    double Bid(double askingprice);
    void Pay(double price);
      bool AcceptOffer(double price);


private:
    double fRand(double fMin, double fMax);
    bool isIntrested();

};
class Auction
{

    Vektor<Customer>customers;
    Vektor<Item>itemsForsale;
    Vektor<Item>itemsSold;
    Vektor<Item>itemsLeft;


public:
    Auction();
    void AddCustomer(const Customer&c);
    void AddItemForSale(const Item &i);
    void Start();
    Vektor<Customer>getCustomers();
    Vektor<Item>getItemsForsale();
    Vektor<Item>getItemsSold();
    Vektor<Item>getItemsLeft();
	~Auction() {};
private:
   
	void sellItem(Item item);
	void EnglisAuction(Item item);
	void DeutchAuction(Item item);
	void BlindAuction(Item item);
	void transferItemToCustomer(Item item, Customer &customer, double price);
};





ostream& operator <<(ostream & os, Item i);
ostream& operator <<(ostream & os, Customer c);
ostream& operator <<(ostream & os, SellingMetod s);
ostream& operator <<(ostream & os, Auction a);
ostream& operator <<(ostream & os, Vektor<Item>items);
ostream& operator <<(ostream & os, Vektor<Customer>items);



template <typename T>
Vektor<T>::Vektor(size_t meret ) :data(new T[meret]),siz(meret) {}
template <typename T>
Vektor<T>::Vektor(const Vektor &v)
{
    siz = v.siz;
    data = new T[siz];

    for (size_t i = 0; i < v.siz; i++)
    {
        data[i] = v.data[i];
    }
}
template <typename T>
Vektor<T>& Vektor<T>::operator=(const Vektor &v)
{
    delete[]data;

    siz = v.siz;
    data = new T[siz];

    for (size_t i = 0; i < v.siz; i++)
    {
        data[i] = v.data[i];
    }
    return *this;
}
template <typename T>
size_t Vektor<T>::size() const
{
    return siz;
}
template <typename T>
T& Vektor<T>::operator[](size_t index)
{
    return data[index];
}
template <typename T>
T const& Vektor<T>::operator[](size_t index) const
{
    return data[index];
}
template <typename T>
void Vektor<T>::Add(T const& new_val)
{
    T *new_data = new T[siz + 1];
    for (size_t i = 0; i < siz; ++i)
        new_data[i] = data[i];
    new_data[siz] = new_val;
    delete[] data;
    data = new_data;
    ++siz;
}
template<typename T>
void Vektor<T>::Delete(size_t index)
{

    for (size_t i = index; i < siz; i++)
    {
        data[i] = data[i + 1];
    }

    siz--;
    T *new_data = new T[siz];
    for (size_t i = 0; i < siz; i++)
    {
        new_data[i] = data[i];
    }
    delete[]data;
    data = new_data;

}
template<typename T>
T Vektor<T>::Pop()
{
    T deleted = data[siz - 1];
    Delete(siz);
    return deleted;

}
template<typename T>
Vektor<T>::~Vektor()
{

    delete[] data;
}





#endif // !ARVERES_H



