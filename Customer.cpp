#pragma once
#pragma once
#include "Product.h"
#include "Customer.h"
#include<string>
#include<list>
#include<iostream>
using namespace std;


int Customer::getCustId()
{

	return cust_id;
}
string Customer::getCustName()
{
	return cust_name;
}
void Customer::setCustId(int custid)
{

	cust_id = custid;
}
void  Customer::setCustName(string nm)
{
	cust_name = nm;
}

void Customer::AddToCart()
{
	int id, qty, updatedqty, flag = 0;
	double price = 0;

	//
	ofstream fout;
	fout.open("Customer_list.dat", ios::out | ios::app);
	if (fout.is_open())
	{
		Product p;
		cout << "\nEnter the product id:";
		cin >> id;
		cout << "\nEnter the product qty:";
		cin >> qty;



		//Check if Product is available in Product List
		ifstream fin;
		fin.open("Product_list.dat", ios::in);

		if (fin.is_open())
		{
			while (!fin.eof())
			{
				Product *ptr;
				ptr = new Product();

				fin.read((char *)ptr, sizeof(Product));
				if (ptr->getProdNo() == id && qty < ptr->getProdQuantity())
				{
					p.setProdNo(id);
					p.setProdQuantity(qty);
					updatedqty = ptr->getProdQuantity() - qty;
					ptr->setProdQuantity(updatedqty);

					//This Updated qty is to be written to Global Product List


					//p.setProdPrice(0);
					price = ptr->getProdPrice();
					cout << "\n\nPrice after return : " << price << endl << endl;
					price = price * qty;
					p.setProdPrice(price);
					ProdList.push_back(p);
					//flag = 1;

					//for invoice
					fout.write((char *)&p, sizeof(Product));
					cout << "\nAdded to CustomerFile Successfully";
					break;
				}
			}

			fin.close();
		}
		else
		{
			cout << "\nFile cannot be Read ";
		}

		fout.close();

	}
	else
	{
		cout << "\nUnable To Open File to write";
	}
}

void Customer::DisplayProductList()
{
	cout << "\n-------------------Products Purchased By Customer are:-----------------------------";
	list<Product> ::iterator itr = ProdList.begin();
	while (itr != ProdList.end())
	{
		cout << "\n\nProduct ID :" << itr->getProdNo();
		cout << "\nProduct Qty :" << itr->getProdQuantity();
		cout << "\nProduct Overall Price :" << itr->getProdPrice();
		itr++;
	}
	cout << "\n----------------------------------------------------------------------------------";

	ifstream fin;
	fin.open("Customer_list.dat", ios::in);

	if (fin.is_open())
	{

		cout << "\n-------------------Reading Invoice of Customer are:-----------------------------";
		while (!fin.eof())
		{
			Product *p;
			p = new Product();

			fin.read((char *)p, sizeof(Product));
			cout << "\n\nProduct ID :" << p->getProdNo();
			cout << "\nProduct Qty :" << p->getProdQuantity();
			cout << "\nProduct Price :" << p->getProdPrice();
		}

		fin.close();
	}
	else
	{
		cout << "\nFile cannot be Read ";
	}
}

void Customer::UpdateProductList()
{

	int id, quantity;
	int quantityupdated;
	int priceupdated;
	bool flag = false;
	double price = 0;
	cout << "\nEnter the Product id to be updated :";
	cin >> id;

	list<Product> ::iterator itr = ProdList.begin();

	while (itr != ProdList.end())
	{
		if (itr->getProdNo() == id)
		{
			cout << "\nCurrent Quantity of Product " << id << " is: " << itr->getProdQuantity();
			cout << "\nEnter the updated Quantity : ";
			cin >> quantity;

			ifstream fin;
			fin.open("Product_list.dat", ios::in);

			if (fin.is_open())
			{


				while (!fin.eof())
				{
					Product *p;
					p = new Product();

					fin.read((char *)p, sizeof(Product));
					if (p->getProdNo() == id && quantity < p->getProdQuantity())
					{
						//modify the quantity
						quantityupdated = p->getProdQuantity() - quantity;
						p->setProdQuantity(quantityupdated);
						//now as quantity is updated we have to write that all updated data to the file again
						itr->setProdQuantity(quantity);
						priceupdated = quantity * p->getProdPrice();
						itr->setProdPrice(priceupdated);
						cout << "\nProduct List Updated for customer";


						flag = true;
					}
				}
				if (flag == false)
				{
					cout << "\nProduct not found or Quantity of Products in the Supermarket is less  ";
				}

				fin.close();
			}
			else
			{
				cout << "\nFile cannot be Read ";
			}
		}
		itr++;
	}


}