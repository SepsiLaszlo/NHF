
#include<iostream>
#include"arveres.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <string>

#include "gtest_lite.h"


using namespace std;

Auction auction;

void PrintOptions() {

	cout <<"Welcome to the Auction!"<<endl
		<<"-Options-"<<endl
		<< "1.Add Item" << endl
		<< "2.Add Customer" << endl
		<< "3.Start Auction"<<endl
		<< "4.Print Auction" << endl
		<<"5.Delete Auction"<<endl
		<<"6.Initilaize Auction"<<endl
		<<"5.Exit"<<endl;



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
		EXPECT_EQ(item.getName(), name) << "A f�ggv�ny hib�s eredm�nyt adott" << std::endl;
		EXPECT_EQ(item.getDescription(), description) << "A f�ggv�ny hib�s eredm�nyt adott" << std::endl;
		EXPECT_EQ(item.getPrice(), price) << "A f�ggv�ny hib�s eredm�nyt adott" << std::endl;
		EXPECT_EQ(item.getSellingMethod(),SellingMetod(methodnum)) << "A f�ggv�ny hib�s eredm�nyt adott" << std::endl;

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
		EXPECT_EQ(customer.getName(),name) << "A f�ggv�ny hib�s eredm�nyt adott" << std::endl;
		EXPECT_EQ(customer.getBalance(), balance) << "A f�ggv�ny hib�s eredm�nyt adott" << std::endl;
	END

	return customer;

}

void initializeTestAuction() {
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

	PrintOptions();

	char selectedOptionNum;

	while ((cin>>selectedOptionNum),selectedOptionNum!='7')
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
			TEST(Aukcio,TargyakSzamanakEllenorzese)
				EXPECT_EQ(auction.getItemsSold().size() + auction.getItemsLeft().size(), auction.getItemsForsale().size()) << "A f�ggv�ny hib�s eredm�nyt adott" << std::endl;
			END
			break;
		case '4':
			cout << auction;
			break;
		case '5':
			auction.~Auction();
			break;
		case '6':
			auction.~Auction();
			initializeTestAuction();
			break;

		default:
			break;
		}
		

	}




}
void Test() {

	 Auction a();

	initializeTestAuction();
	UserInteractionHandler();


}
int main() {

	


	Test();

	char *x = new char[100];

	//	auction.AddItemForSale(Item());

	
	return 0;
}
