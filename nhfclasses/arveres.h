

#ifndef ARVERES_H
#define ARVERES_H
#include"arveres.h"
#include<iostream>
#include<string>


#include "memtrace.h"
using namespace std;

enum SellingMetod
{
    English, Dutch, Blind

};
/** \brief Osztály egy tárgy modellezésére.
 */
class Item
{
    string name;
    double price;
    string description;
    SellingMetod sellingMethod;

public:
    /** \brief Konstruktor default paraméterekkel ellátva, létrehozás után az értékek nem változtathatók
     *
     * \param "Generic_item" string name=
     * \param 10 double price=
     * \param "Generic_description" string description=
     * \param English SellingMetod sellingMethod=
     *
     */
    Item(string name = "Generic_item", double price = 10, string description = "Generic_description", SellingMetod sellingMethod = English);
    /** \brief Lekérdezi a tárgy nevét
     *
     * \return string
     *
     */
    string getName();
    /** \brief Lekérdezi a tárgy árát
     *
     * \return double
     *
     */
    double getPrice();
    /** \brief Lekérdezi a tárgy leírását
     *
     * \return string
     *
     */
    string getDescription();
    /** \brief Lekérdezi a tárgy eladási módját
     *
     * \return SellingMetod
     *
     */
    SellingMetod getSellingMethod();
private:

};
/** \brief Egy template osztály megadható tipusú elemek tárolására, vektorban, listafunkciókkal
 *
 * \param
 * \param
 * \return
 *
 */
template<typename T>class Vektor
{
    T *data;
    size_t siz;

public:

    /** \brief Létrehoz egy tárolót a megadott mérettel
     *
     * \param 0 size_t meret=
     * \return explicit
     *
     */
    explicit Vektor(size_t meret = 0);
    /** \brief Másolókonstruktor
     *
     * \param v const Vektor&
     *
     */
    Vektor(const Vektor &v);
    /** \brief Értékadó operáor
     *
     * \param v const Vektor&
     * \return Vektor&	operator
     *
     */
    Vektor&	operator =(const Vektor &v);
    /** \brief Lekérdezi a tároló méretét
     *
     * \return size_t
     *
     */
    size_t size() const;
    /** \brief Indexelő operátor nem konstans adattagokra
     *
     * \param index size_t
     * \return T&
     *
     */
    T& operator[](size_t index);
    /** \brief Indexelőoperátor konstans adattagokra
     *
     * \param index size_t
     * \return T const&
     *
     */
    T const& operator[](size_t index) const;
    /** \brief Új elemet ad a vektorhoz
     *
     * \param new_val T const&
     * \return void
     *
     */
    void Add(T const& new_val);
    /** \brief Töri a paraméterként kapott indexű elemet
     *
     * \param index size_t
     * \return void
     *
     */
    void Delete(size_t index);
    /** \brief Az utolsó elemet töri és a másolatát visszadja
     *
     * \return T
     *
     */
    T Pop();
    /** \brief Felszabadítja a foglalt memóriát
     *
     *
     */
    ~Vektor();
};
/** \brief Oszály egy vásárló modellezésére
 */
class Customer
{
    string name;
    double balance;
    Vektor<Item>items;


public:
    /** \brief Konstruktor default paraméterekkel ellátva, létrehozás után az értékek nem változtathatók
     *
     * \param "Generic_Name" string name=
     * \param 1000 double balance=
     *
     */
    Customer(string name = "Generic_Name", double balance = 1000);
    /** \brief A vásárlóhoz tartozó tárgy tárolóhoz ad egy tárgyat
     *
     * \param i const Item&
     * \return void
     *
     */
    void AddItem(const Item &i);
    /** \brief A vásárló utolsó tárgyát törli és egy másolatot ad vissza róla
     *
     * \return Item
     *
     */
    Item PopItem();
    /** \brief Lekérdezi a vásárló nevét
     *
     * \return string
     *
     */
    string getName();
    /** \brief lekérdezi a vásárló egyenlegét
     *
     * \return double
     *
     */
    double getBalance();
    /** \brief Egy másolatot ad a vásárló tárgyairól
     *
     * \return Vektor<Item>
     */
    Vektor<Item>getItems();
    /** \brief A vásárló eldönti,hogy szeretne-e licitálni, ha igen egy ajánlatot ad vissza,ha nem akkor 0-át.
     *
     * \param askingprice double
     * \return double
     *
     */
    double Bid(double askingprice);
    /** \brief A vásárló egyenlegéből levonásra kerül a megadott összeg
     *
     * \param price double
     * \return void
     *
     */
    void Pay(double price);
      bool AcceptOffer(double price);



private:

    /** \brief ffMin-fMax tartományban generál egy véletlen számot
     *
     * \param fMin double
     * \param fMax double
     * \return double
     *
     */
    double fRand(double fMin, double fMax);
    /** \brief Igaz értéked ad vissza, ha a vásárló szeretne résztvenni az árverésen
     *
     * \return bool
     *
     */
    bool isIntrested();

};
/** \brief Oszály az aukció modellezésére
 */
class Auction
{

    Vektor<Customer>customers;
    Vektor<Item>itemsForsale;
    Vektor<Item>itemsSold;
    Vektor<Item>itemsLeft;


public:
    /** \brief Létrehoz egy aukció modellt
     *
     *
     */
    Auction();
    /** \brief Vásárlót vesz fel az osztály vektorába
     *
     * \param Customer&c const
     * \return void
     *
     */
    void AddCustomer(const Customer&c);
    /** \brief Fel vesz egy tárgyat az eleadandó tárgyak vektorába
     *
     * \param i const Item&
     * \return void
     *
     */
    void AddItemForSale(const Item &i);
    /** \brief Elindítja az árverést
     *
     * \return void
     *
     */
    void Start();
    /** \brief Egy máslatot ad vissza a vevőket tároló vektorról
     *
     *
     */
    Vektor<Customer>getCustomers();
    /** \brief  Egy máslatot ad vissza az eladandó árukat tároló vektorról
     *
     *
     */
    Vektor<Item>getItemsForsale();
    /** \brief Egy máslatot ad vissza az eladott árukat tároló vektorról
     *
     *
     */
    Vektor<Item>getItemsSold();
    /** \brief Egy máslatot ad vissza a megmaradt árukat tároló vektorról
     *
     *
     */
    Vektor<Item>getItemsLeft();

    /** \brief Destruktor
     *
     * \param
     * \param
     * \return
     *
     */
	~Auction() {};
private:

    /** \brief A megfelelő árverezési módot hívja meg az adott árura
     *
     * \param item Item
     * \return void
     *
     */
	void sellItem(Item item);
    /** \brief Angol akció elvégzése
     *
     * \param item Item
     * \return void
     *
     */
	void EnglisAuction(Item item);
    /** \brief Német aukció elvégzése
     *
     * \param item Item
     * \return void
     *
     */
	void DeutchAuction(Item item);
    /** \brief Vak aukció elvégzése
     *
     * \param item Item
     * \return void
     *
     */
	void BlindAuction(Item item);
    /** \brief A paraméterként megadott árut átadja a megfelelő vásárlónak ,akitől levonja a megadott árat
     *
     * \param item Item
     * \param customer Customer&
     * \param price double
     * \return void
     *
     */
	void transferItemToCustomer(Item item, Customer &customer, double price);
};


/** \brief inserter operátor egy tárgy kiírásához
 *
 * \param os ostream&
 * \param i Item
 * \return ostream& operator
 *
 */

ostream& operator <<(ostream & os, Item i);
/** \brief inserter operátor egy vásárló kiírásához
 *
 * \param os ostream&
 * \param c Customer
 * \return ostream& operator
 *
 */
ostream& operator <<(ostream & os, Customer c);
/** \brief inserter operátor egy eladási mód kiírásához
 *
 * \param os ostream&
 * \param s SellingMetod
 * \return ostream& operator
 *
 */
ostream& operator <<(ostream & os, SellingMetod s);
/** \brief inserter operátor egy aukció kiírásához
 *
 * \param os ostream&
 * \param a Auction
 * \return ostream& operator
 *
 */
ostream& operator <<(ostream & os, Auction a);
/** \brief inserter operátor egy tárgy vektor kiírásához
 *
 * \param os ostream&
 * \param Vektor<Item>items
 * \return ostream& operator
 *
 */
ostream& operator <<(ostream & os, Vektor<Item>items);
/** \brief inserter operátor egy vásárló vektor kiírásához
 *
 * \param os ostream&
 * \param Vektor<Customer>items
 * \return ostream& operator
 *
 */
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



