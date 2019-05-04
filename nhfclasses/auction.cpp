#include"arveres.h"

Auction::Auction() :customers(Vektor<Customer>(0)), itemsForsale(Vektor<Item>(0)), itemsSold(Vektor<Item>(0)), itemsLeft(Vektor<Item>(0)) {}
void Auction::AddCustomer(const Customer&c)
{
    customers.Add(c);
}
void Auction::AddItemForSale(const Item &i)
{
    itemsForsale.Add(i);
}
Vektor<Customer>Auction::getCustomers()
{
    return customers;
}
Vektor<Item>Auction::getItemsForsale()
{
    return itemsForsale;
}
Vektor<Item>Auction::getItemsSold()
{
    return itemsSold;
}
Vektor<Item>Auction::getItemsLeft()
{
    return itemsLeft;
}
void  Auction::Start()
{
	if (itemsSold.size() > 0 || itemsLeft.size() > 0) { return; }
	for (size_t i = 0; i < itemsForsale.size(); i++)
	{
		sellItem(itemsForsale[i]);
	}

}

void Auction::sellItem(Item item)
{

	switch (item.getSellingMethod())
	{
	case 0:
		EnglisAuction(item);
		break;
	case 1:
		DeutchAuction(item);
		break;

	case 2:
		BlindAuction(item);
		break;

	default:
		break;
	}
	
}

void Auction::transferItemToCustomer(Item item, Customer &customer, double price)
{
	customer.Pay(price);
	customer.AddItem(item);
	itemsSold.Add(item);
}


void Auction::EnglisAuction(Item item)
{

	double higestBid = item.getPrice();
	Customer *higestBidder = &(customers[0]);

	bool someone_bid = true;
	while (someone_bid)
	{
		someone_bid = false;
		for (size_t i = 0; i < customers.size(); i++)
		{
			double bid = customers[i].Bid(higestBid);

			if (bid>higestBid)
			{
				higestBid = bid;
				higestBidder = &customers[i];
				someone_bid = true;
			}
		}

	}
	if (higestBid != item.getPrice())
	{
		transferItemToCustomer(item, *higestBidder, higestBid);
	}
	else
	{
		itemsLeft.Add(item);
	}


}

void Auction::DeutchAuction(Item item)
{
	double curentPrice = item.getPrice();
	double deltaPrice = curentPrice / 10;
	while (curentPrice>0)
	{
		for (size_t i = 0; i < customers.size(); i++)
		{
			if (customers[i].AcceptOffer(curentPrice))
			{
				transferItemToCustomer(item, customers[i], curentPrice);
				return;
			}
		}
		curentPrice -= deltaPrice;
	}
	itemsLeft.Add(item);
}
void Auction::BlindAuction(Item item) {

	double higestBid = item.getPrice();
		double startingPrice = higestBid;
	Customer *higestBidder = &(customers[0]);

	
		for (size_t i = 0; i < customers.size(); i++)
		{
			double bid = customers[i].Bid(startingPrice);

			if (bid>higestBid)
			{
				higestBid = bid;
				higestBidder = &customers[i];
				
			}
		}

	
	if (higestBid != item.getPrice())
	{
		transferItemToCustomer(item, *higestBidder, higestBid);
	}
	else
	{
		itemsLeft.Add(item);
	}


	
}



