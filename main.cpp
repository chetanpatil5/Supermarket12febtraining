#pragma once
#pragma once
#include "Product.h"
#include<list>
#include "Customer.h"
#include "Admin.h"
#include<string>
#include<list>
#include<iostream>
using namespace std;
//
//int main()
//{
//	list<Product> lp;
//	Admin a;
//	a.AddProductToFile(lp);
//	a.AddProductToFile(lp);
//	a.ViewProductFromFile(lp);
//
//	//list<Product>::iterator itr=lp.begin() ;
//	//while (itr != lp.end())
//	//{
//	//	cout<<endl<<itr->getProdNo()<<" ";
//	//	cout << itr->getProdPrice() << " ";
//	//	cout << itr->getProdQuantity() << " ";
//	//	itr++;
//	//}
//
//	Customer c;
//	c.AddToCart();
//	cout << "\n\n\nGlobal list updated\n\n\n";
//	a.ViewProductFromFile(lp);
//	c.AddToCart();
//	cout << "\n\n\nGlobal list updated\n\n\n";
//	a.ViewProductFromFile(lp);
//	c.DisplayProductList();
//	c.UpdateProductList();
//	cout << "\n\n\nGlobal list updated\n\n\n";
//	a.ViewProductFromFile(lp);
//	c.DisplayProductList();
//	system("pause");
//	return 0;
//}


int main()
{	
	int ch = 0;
	int ch1 = 0;
	list<Product> lp;
	Admin a;
	Customer c;
	while (1)
	{
		cout << "\n1. Admin";
		cout << "\n1. Customer";
		cin >> ch;
		switch (ch)
		{
		case 1:
			while (1)
			{
				cout << "\nInside Admin Section";
				cout << "\n1. Admin add products";
				cout << "\n2. Admin view Products";
				cout << "\n3. Exit";
				cin >> ch1;
				switch (ch1)
				{
				case 1:a.AddProductToFile(lp);
					break;
				case 2:a.ViewProductFromFile(lp);
					break;
				case 3:ch = 3;
					break;
				}
				if (ch == 3)
				{
					break;
				}
			}
			break;
		case 2:
			while (1)
			{
				cout << "\nInside Customer Section";
				cout << "\n1. Customer add products";
				cout << "\n2. Customer view Products";
				cout << "\n3. Customer update Products";
				cout << "\n4. Exit";
				cin >> ch1;
				switch (ch1)
				{
				case 1:c.AddToCart();
					break;
				case 2:c.DisplayProductList();
					break;
				case 3:c.UpdateProductList();
					break;
				case 4:ch = 4;
					break;
				}
				if (ch == 4)
				{
					break;
				}
			}
			break;
		default:
			break;
		}
	}
	//Admin a;
	//a.AddProductToFile(lp);
	//a.AddProductToFile(lp);
	//a.ViewProductFromFile(lp);

	////list<Product>::iterator itr=lp.begin() ;
	////while (itr != lp.end())
	////{
	////	cout<<endl<<itr->getProdNo()<<" ";
	////	cout << itr->getProdPrice() << " ";
	////	cout << itr->getProdQuantity() << " ";
	////	itr++;
	////}

	//Customer c;
	//c.AddToCart();
	//cout << "\n\n\nGlobal list updated\n\n\n";
	//a.ViewProductFromFile(lp);
	//c.AddToCart();
	//cout << "\n\n\nGlobal list updated\n\n\n";
	//a.ViewProductFromFile(lp);
	//c.DisplayProductList();
	//c.UpdateProductList();
	//cout << "\n\n\nGlobal list updated\n\n\n";
	//a.ViewProductFromFile(lp);
	//c.DisplayProductList();
	system("pause");
	return 0;
}