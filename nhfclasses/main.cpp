
#include<iostream>
#include"arveres.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <string>
using namespace std;

Auction auction;

void PrintOptions() {

	cout <<"Welcome to the Auction!"<<endl
		<<"-Options-"<<endl
		<< "1.Add Item" << endl
		<< "2.Add Customer" << endl
		<< "3.Start Auction"<<endl
		<<"4.Exit"<<endl;



}

void AddItemPanel() {

	string itemName,itemDescription;
	double itemPrice;
	SellingMetod itemSellingMethod;

	cout << "Item name:"<<endl;
	cin >> itemName;

	cout << "Item description:" << endl;
	cin >> itemDescription;

	cout << "Item price:" << endl;
	cin >> itemPrice;

	cout << "Selling method(English=0, Dutch=1, Blind=2):" << endl;
	int methodNumber;
	cin >> methodNumber;
	itemSellingMethod = SellingMetod(methodNumber);


	auction.AddItemForSale(Item(itemName,itemPrice, itemDescription, itemSellingMethod));

}

void UserInteractionHandler() {

	PrintOptions();

	int selectedOptionNum;

	while ((cin>>selectedOptionNum),selectedOptionNum!=4)
	{

		switch (selectedOptionNum)
		{
		case 1:
			AddItemPanel();
			break;
		case 3:
			auction.Start();
			break;
		default:
			break;
		}

	}




}

void Test() {

	Customer c1("Customer Cecil", 20000.0);
	Customer c2("Generic Geza", 10000.0);
	Customer c3("Random Robert", 20000.0);
	Customer c4("Burnout Bela", 20000.0);

	 auction = Auction();

	auction.AddItemForSale(Item("alma", 100.0, "Egeszseges", English));
	auction.AddItemForSale(Item("szekreny", 2000.0, "Butor", Blind));
	auction.AddItemForSale(Item("mogyorovaj", 155.0, "Finom", Dutch));

	auction.AddCustomer(c1);
	auction.AddCustomer(c2);
	auction.AddCustomer(c3);
    auction.AddCustomer(c4);


	UserInteractionHandler();



}






int main() {



	Test();
    cout<<auction;
	return 0;
}
