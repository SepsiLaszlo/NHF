
#include<iostream>
#include"arveres.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <string>
#include "memtrace.h"

#define MEMTRACE 
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

Item getItemFromConsole() {
	cout << "Item:" << endl;
	string name, description;
	double price;
	int method;
	cin.ignore();
	cout << "Name: ";
	getline(cin, name);

	cout << "Description: ";
	getline(cin, description);
	cout << "Price: ";
	cin >> price;
	cout << "Method num: ";
	cin >> method;

	return Item(name,price,description,SellingMetod(method));
}

Customer getCustomerFromConsole() {
	cout << "Customer:" << endl;
	string name;
	double balance;
	
	cin.ignore();
	cout << "Name: ";
	getline(cin, name);

	cout << "Balance: ";
	cin >> balance;

	Customer customer(name,balance);

	return customer;

}

void UserInteractionHandler() {

	PrintOptions();

	char selectedOptionNum;

	while ((cin>>selectedOptionNum),selectedOptionNum!='4')
	{

		switch (selectedOptionNum)
		{
		case '1':
		 auction.AddItemForSale(getItemFromConsole());
			break;
		case '2':
			auction.AddCustomer(getCustomerFromConsole());
		case '3':
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
