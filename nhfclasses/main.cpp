
#include<iostream>
#include"arveres.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <string>

#include "gtest_lite.h"
#include "memtrace.h"


using namespace std;

Auction auction;

void PrintOptions() {

	cout<<"-Options-"<<endl
		<< "1.Add Item" << endl
		<< "2.Add Customer" << endl
		<< "3.Start Auction"<<endl
		<< "4.Print Auction" << endl
		<<"5.Reset Auction"<<endl
		<<"6.Seed Auction"<<endl
		<<"7.Exit"<<endl;



}

Item getItemFromConsole() {
	cout << "Item:" << endl;
	string name, description;
	double price;
	int methodnum;
	cin.ignore();
	cout << "Name: ";
	getline(cin, name);

	cout << "Description: ";
	getline(cin, description);
	cout << "Price: ";
	cin >> price;
	cout << "Method num: ";
	cin >> methodnum;

	Item item(name, price, description, SellingMetod(methodnum));
	TEST(Aukcio, TargyFelvetelEllenorzes)
		EXPECT_EQ(item.getName(), name) << "A függvény hibás eredményt adott" << std::endl;
		EXPECT_EQ(item.getDescription(), description) << "A függvény hibás eredményt adott" << std::endl;
		EXPECT_EQ(item.getPrice(), price) << "A függvény hibás eredményt adott" << std::endl;
		EXPECT_EQ(item.getSellingMethod(),SellingMetod(methodnum)) << "A függvény hibás eredményt adott" << std::endl;

	END

	return item;
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
	TEST(Aukcio, VasarloLetrehozasEllenorzes)
		EXPECT_EQ(customer.getName(),name) << "A függvény hibás eredményt adott" << std::endl;
		EXPECT_EQ(customer.getBalance(), balance) << "A függvény hibás eredményt adott" << std::endl;
	END

	return customer;

}

void SeedAuction() {
	Customer c1("Customer Cecil", 5000);
	Customer c2("Generic Geza", 10000.0);
	Customer c3("Random Robert", 20000.0);
	Customer c4("Sample Sam", 30000.0);

	auction.AddItemForSale(Item("alma", 100.0, "Egeszseges", English));
	auction.AddItemForSale(Item("szekreny", 2000.0, "Butor", Blind));
	auction.AddItemForSale(Item("mogyorovaj", 155.0, "Finom", Dutch));

	auction.AddCustomer(c1);
	auction.AddCustomer(c2);
	auction.AddCustomer(c3);
	auction.AddCustomer(c4);


}

void UserInteractionHandler() {


	char selectedOptionNum;	PrintOptions();

	while ((cin>>selectedOptionNum),selectedOptionNum!='7')
	{


		switch (selectedOptionNum)
		{
		case '1':
		 auction.AddItemForSale(getItemFromConsole());

			break;
		case '2':
			auction.AddCustomer(getCustomerFromConsole());
			break;
		case '3':
			TEST(Aukcio,TargyakSzamanakEllenorzese)
				size_t sizebefore = auction.getItemsForsale().size();
			auction.Start();
				EXPECT_EQ(auction.getItemsSold().size() + auction.getItemsLeft().size(),sizebefore) << "A fuggveny hibas eredmenyt adott" << std::endl;
			END
			break;
		case '4':
			cout << auction;
			break;
		case '5':
			auction = Auction();
			break;
		case '6':

			SeedAuction();
			break;

		default:
			break;
		}

		PrintOptions();
	}




}
void Test() {

	cout << "Welcome to the Auction!" << endl;
	 Auction a();

	SeedAuction();
	UserInteractionHandler();


}
int main() {




	Test();



	return 0;
}
