// online.shopping.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<windows.h>
#include <string>
using namespace std;
int oldcounter = 4;
int counter_shop = 4;
int oldcounterShopper = 4;
struct regist
{
	string name;
	int id;
	int password;
	int age;
	char gender;
	string address;
}owner[10], shopper[10];
struct addreciept
{
	string name;
	int quantity;

}pro[20];
struct login
{

	int id;
	int password;

}owners, shoppers;
struct product
{
	string name;
	float price;
	int quantity;

};
struct shop
{
	int owner_id;
	string shop_name;
	string address;
	string category;
	int counter_prod;
	product p[10];
}s[10];

void regist_shopper(regist shopper[10], int &id2)
{

	int existedshopper = oldcounterShopper;
	oldcounterShopper++;
	cout << "you choose to registration shopper \n";

	for (int k = existedshopper; k < oldcounterShopper; k++)
	{
		cout << "\t\tYOUR FIXED ID AND YOU SHOULD KEEP IT  ::  " << oldcounterShopper << "\n";
		cout << " please enter your name \n";
		cin >> shopper[k].name;
		shopper[k].id = oldcounterShopper;
		cout << "please enter your password\n";
		cin >> shopper[k].password;
		cout << "please enter your age\n";
		cin >> shopper[k].age;
		cout << "please enter your gander F for female and M for male\n";
		cin >> shopper[k].gender;
		cout << "please enter your address in alphabet \n";
		cin >> shopper[k].address;
		break;
	}

}
bool login_owner(regist owner[10], int & id)
{

	cout << "enter your id \n";
	cin >> owners.id;
	cout << "enter your password \n";
	cin >> owners.password;
	bool check = false;
	for (int i = 0; i < 10; i++)
	{


		if ((owners.id == owner[i].id) && (owners.password == owner[i].password))

		{
			id = owners.id;
			return true;
		}

	}
	return false;

}
bool login_shopper(regist shopper[10], int &id2)
{
	int id;
	int password;
	cout << "enter your id \n";
	cin >> id2;
	cout << "enter your password \n";
	cin >> password;
	bool check = false;

	for (int i = 0; i < 10; i++)
	{
		if ((shopper[i].id == id2) && (shopper[i].password == password))

		{
			return true;
		}
	}
	return false;

}
void product_information_owner(shop s[10], int &id)
{
	int number = 0;
	cout << " ** " << s[id - 1].shop_name << "***\n";

	int oldProductnum = s[id - 1].counter_prod;
	for (int k = 0; k < oldProductnum; k++)
	{

		cout << " \t name of" << k + 1 << ":" << s[id - 1].p[k].name << " \n price :" << s[id - 1].p[k].price << "\n quantity :" << s[id - 1].p[k].quantity << endl;
	}

}
void product_information_shopper(shop s[10])
{
	int number = 0;
	cout << "CHOOSE ONE OF THE FOLLOWING SHOP \n";

	for (int m = 0; m < counter_shop; m++)
	{

		cout << "[" << m + 1 << "]" << s[m].shop_name;
	}
	cin >> number;
	for (int k = 0; k < s[number - 1].counter_prod; k++)
	{

		cout << " \t name of" << k + 1 << ":" << s[number - 1].p[k].name << " \t price :" << s[number - 1].p[k].price << endl;
	}

}
void add_new_product(shop s[10], int &id)
{
	int number;
	int num;
	int no_product;
	cout << " * " << s[id - 1].shop_name << "***\n";
	cout << "How many product need you add ? \n ";
	cin >> no_product;

	int oldProductnum = s[id - 1].counter_prod;
	s[id - 1].counter_prod += no_product;
	for (int k = oldProductnum; k < s[id - 1].counter_prod; k++)
	{
		cout << "add product name \n";
		cin >> s[id - 1].p[k].name;
		cout << "enter product price \n";
		cin >> s[id - 1].p[k].price;
		cout << "enter product quantity \n";
		cin >> s[id - 1].p[k].quantity;

	}
}
void edit_owner(regist owner[10], int &id)
{
	char choise;

	do {
		cout << "What do you want to edit ?\n";
		cout << " [n] for name \n [a] for age \n [p] for passward \n [d] for address \n ";
		cin >> choise;


		switch (choise)
		{
		case 'n':
		{
			string n1;
			cout << "ENTER YOUR NEW NAME\n";
			cin >> n1;
			owner[id - 1].name = n1;
			break;
		}
		case 'a':
		{
			int a1;
			cout << "ENTER YOUR NEW AGE \n";
			cin >> a1;
			owner[id - 1].age = a1;
			break;
		}
		case 'p':
		{
			int p1;
			cout << "ENTER YOUR NEW PASSWORD\n";
			cin >> p1;
			owner[id - 1].password = p1;
			break;

		}
		case 'd':
		{
			string  d1;
			cout << "ENTER YOUR ADDRESS\n";
			cin >> d1;
			owner[id - 1].address = d1;
			break;
		}
		default:
		{
			cout << "INVALID ENTER \n";
			break;
		}
		}
		cout << "DO YOU WANT TO EDIT AGAIN? (y /n) \n";
		cin >> choise;
	} while (choise == 'y');


}
void edit_shopper(regist shopper[10], int &id2)
{
	char choise;

	do {
		cout << "What do you want to edit ?\n";
		cout << " [n] for name \n [a] for age \n [p] for passward \n [d] for address \n ";
		cin >> choise;


		switch (choise)
		{
		case 'n':
		{
			string n1;
			cout << "ENTER YOUR NEW NAME\n";
			cin >> n1;
			shopper[id2 - 1].name = n1;
			break;
		}
		case 'a':
		{
			int a1;
			cout << "ENTER YOUR NEW AGE \n";
			cin >> a1;
			shopper[id2 - 1].age = a1;
			break;
		}
		case 'p':
		{
			int p1;
			cout << "ENTER YOUR NEW PASSWORD\n";
			cin >> p1;
			shopper[id2 - 1].password = p1;
			break;

		}
		case 'd':
		{
			string  d1;
			cout << "ENTER YOUR ADDRESS\n";
			cin >> d1;
			shopper[id2 - 1].address = d1;
			break;
		}
		default:
		{
			cout << "INVALID ENTER \n";
			break;
		}
		}
		cout << "DO YOU WANT TO EDIT AGAIN? (y /n) \n";
		cin >> choise;
	} while (choise == 'y');


}



void add_shop_data(shop s[10])
{
	int number_of_shop;
	int number_of_product;
	cout << "How many number of shops ?\n";
	cin >> number_of_shop;
	int oldShopCount = counter_shop;
	counter_shop += number_of_shop;
	for (int i = oldShopCount; i < counter_shop; i++)
	{
		cout << "Enter the owner id \n";
		cin >> s[i].owner_id;
		cout << "enter the name of shop \n";
		cin >> s[i].shop_name;
		cout << "Enter the address of shop \n";
		cin >> s[i].address;
		cout << "Enter the category of shop \n";
		cin >> s[i].category;

		cout << "How many product you need \n";
		cin >> number_of_product;
		s[i].counter_prod = number_of_product;
		for (int x = 0; x < number_of_product; x++)
		{
			cout << "Enter your shop product name:\n ";
			cin >> s[i].p[x].name;
			cout << "Enter your shop product price:\n ";
			cin >> s[i].p[x].price;
			cout << "Enter your shop product quantity :\n ";
			cin >> s[i].p[x].quantity;


		}

	}


}
void search(shop s[10])
{
	char let;
	int search;

	cout << "SEARCH BY \n [1] SHOP \n [2] category \n [3] product name";
	cin >> search;
	if (search == 1)
	{
		do
		{

			for (int m = 0; m < counter_shop; m++)
			{

				cout << "[" << m + 1 << "]" << s[m].shop_name;
			}
			cin >> search;
			for (int k = 0; k < s[search - 1].counter_prod; k++)
			{

				cout << " \t name of" << k + 1 << ":" << s[search - 1].p[k].name << " \t price :" << s[search - 1].p[k].price << endl;
			}
			cout << "SEARCH AGAIN (y/n) \n  ";
			cin >> let;

		} while (let == 'y');
	}
	else if (search == 2)
	{
		do
		{
			for (int m = 0; m < counter_shop; m++)
			{

				cout << "[" << m + 1 << "]" << s[m].category;
			}
			cin >> search;
			for (int k = 0; k < s[search - 1].counter_prod; k++)
			{

				cout << " \t name of" << k + 1 << ":" << s[search - 1].p[k].name << " \t price :" << s[search - 1].p[k].price << endl;
			}
			cout << "SEARCH AGAIN (y/n) \n  ";
			cin >> let;

		} while (let == 'y');
	}
	else if (search == 3)
	{
		char  letter[50];
		bool found = false;
		do
		{
			cout << "ENTER PRODUCT NAME :\n";
			cin >> letter;

			for (int m = 0; m < counter_shop; m++)
			{
				for (int k = 0; k < s[m].counter_prod; k++)
				{
					if (s[m].p[k].name == letter)
					{
						cout << "name : " << s[m].p[k].name << "\nprice : " << s[m].p[k].price << endl;
						found = true;
					}

				}
			}
			if (found == false)
			{
				cout << "NOT FOUND  \n";
			}
			cout << "SEARCH AGAIN (y/n) \n  ";
			cin >> let;
		} while (let == 'y');
	}


}
void remove(shop s[10], int & id)
{
	string name;
	int  size = 10, i, count = 0;
	string del;
	cout << " * " << s[id - 1].shop_name << "***\n";
	for (int k = 0; k < s[id - 1].counter_prod; k++)
	{

		cout << " \t name of" << k + 1 << ":" << s[id - 1].p[k].name << " \n price :" << s[id - 1].p[k].price << endl;
	}
	cout << "Enter item to be delete : ";
	cin >> del;
	for (i = 0; i < size; i++)
	{
		if (s[id - 1].p[i].name == del)
		{
			for (int j = i; j < (size - 1); j++)
			{
				s[id - 1].p[j].name = s[id - 1].p[j + 1].name;
				s[id - 1].p[j].price = s[id - 1].p[j + 1].price;
				s[id - 1].p[j].quantity = s[id - 1].p[j + 1].quantity;

			}
			count++;
			break;
		}
	}
	if (count == 0)
	{
		cout << "Element not found..!! \n";
	}
	else
	{
		cout << "item deleted successfully..!!\n";
		cout << "Now items after remove are  :\n";
		for (i = 0; i < (size - 1); i++)
		{
			cout << s[id - 1].p[i].name << " ";
		}
	}
}
void recepit(shop s[10], addreciept pro[20])
{
	int i, order1;
	bool found = false;
	int num;
	int number = 0;
	string prod;
	float payable = 0, total1 = 0, cash = 0, change = 0, quantity = 0;
	char f, lett, c;
	do
	{
		do
		{
			cout << "PLEASE CHOOSE AN SHOP\n";
			for (int i = 0; i < counter_shop; i++)
			{
				cout << " \t[" << i + 1 << "]" << s[i].shop_name << "\t \n";

			}
			cin >> num;


			cout << "*OUR PRODUCT**\n ";
			cout << "\tPlease choose your order: " << endl;
			for (i = 0; i < s[num - 1].counter_prod; i++)
			{
				cout << "\n " << i + 1 << s[num - 1].p[i].name << "        " << s[num - 1].p[i].price;
			}

			do
			{
				cout << "\n\t\t Please enter  your order name from the list: ";
				cin >> prod;
				for (i = 0; i < s[num - 1].counter_prod; i++)
				{
					if (prod == s[num - 1].p[i].name)

					{
						cout << "\n\tYou ordered for:" << s[num - 1].p[i].name << endl;
						cout << "\tPrice: P" << s[num - 1].p[i].price << endl;
						cout << "\tHow many: ";
						cin >> order1;
						s[num - 1].p[i].quantity -= order1;
						total1 += s[num - 1].p[i].price * order1;
						cout << "\tTotal: P" << total1 << endl;
						quantity += order1;
						pro[number].name = s[num - 1].p[i].name;
						pro[number].quantity = order1;
						number++;

						found = true;
						break;
					}
				}
				if (found == false)

					cout << "\a\n\n\t\t\tSorry it is not available here." << endl << endl;



				cout << "\n\t\t\tDo you want to order another (y/n)? ";
				cin >> lett;
			} while ((lett == 'y') || (lett == 'Y'));

			cout << "\n\t\t\tDo you want to go to another shop (y/n)? ";
			cin >> f;
			system("cls");

		} while ((f == 'Y') || (f == 'y'));
		payable = payable + total1;
		cout << "\n\tAmount to be paid: P" << payable;
		do {
			cout << "\n\tYour cash is: P";
			cin >> cash;
			if (cash < payable)
			{
				cout << "\a\n\t\t\t     Your money is not enough. " << endl;

			}
		} while (cash < payable);
		change = cash - payable;
		cout << "\n\tYour change is: P" << change << "\n\n" << endl << endl;
		cout << "\t\t  For your receipt: ";

		system("pause");
		system("cls");
		system("color E0");

		cout << "\t\t\t O F F I C I A L    R E C E I P T" << endl;

		cout << " \t\t\tWISH TO COME AGAIN " << " -\n";
		cout << "\n\tYou ordered :\n " << "\tname\t" << "quantity\n";
		for (int i = 0; i < number; i++)
		{
			cout << "\t" << pro[i].name << "\t" << pro[i].quantity;
			cout << "\n";

		}
		cout << "\n\tTotal quantity: " << quantity;
		cout << "\t\t\t\t    Cash: P" << cash;
		cout << "\n\tTotal: P" << payable;
		cout << "\t\t\t\t\t    Change: P" << change;
		cout << "\a\n\t\t\t    Thank you,please come again!" << endl;
		cout << "\t\t\t THE QUANTITY THAT REMIND FROM TOTAL:" << s[num - 1].p[i].quantity;
		cout << "\n\tTime: " << __TIME__;

		cout << "\n\tDate: " << __DATE__ << endl;
		cout << "PRESS ANY KEY TO CONTINUE \n";
		getchar();
		cin.get();
		cout << "any operation (y or n)";
		cin >> c;
	} while (c == 'y');
	system("pause");
	system("cls");

}

void init()
{
	owner[0].id = 1;
	owner[0].name = "doaa";
	owner[0].password = 12345;
	owner[0].age = 18;
	owner[0].gender = ' f';
	owner[0].address = "25 abbasia ";
	owner[1].id = 2;
	owner[1].name = "sara";
	owner[1].password = 67890;
	owner[1].age = 18;
	owner[1].gender = ' f';
	owner[1].address = "rehab ";
	owner[2].id = 3;
	owner[2].name = "ali";
	owner[2].password = 101010;
	owner[2].age = 17;
	owner[2].gender = ' m';
	owner[2].address = "abbasia ";
	owner[3].id = 4;
	owner[3].name = "ahmed";
	owner[3].password = 202020;
	owner[3].age = 17;
	owner[3].gender = ' m';
	owner[3].address = "maddi ";
	shopper[0].id = 1;
	shopper[0].name = "rawan";
	shopper[0].password = 2468;
	shopper[0].age = 19;
	shopper[0].gender = 'f';
	shopper[0].address = "abour";
	shopper[1].id = 2;
	shopper[1].name = "kholoud";
	shopper[1].password = 101214;
	shopper[1].age = 19;
	shopper[1].gender = 'f';
	shopper[1].address = "maady";
	shopper[2].id = 3;
	shopper[2].name = "rawda";
	shopper[2].password = 252525;
	shopper[2].age = 19;
	shopper[2].gender = 'f';
	shopper[2].address = "cairo";
	shopper[3].id = 4;
	shopper[3].name = "asmaa";
	shopper[3].password = 303030;
	shopper[3].age = 25;
	shopper[3].gender = 'f';
	shopper[3].address = "zmalik";

	s[0] = { owner[0].id, "zara", "abbasya", "cloths", 3 };
	s[0].p[0] = { "skirt", 200, 10 };
	s[0].p[1] = { "pantlon", 300, 10 };
	s[0].p[2] = { "dress", 2000, 10 };

	s[1] = { owner[1].id, "mansor", "zamalk", "cars", 3 };
	s[1].p[0] = { "bmw", 1000000, 3 };
	s[1].p[1] = { "kia", 500000, 3 };
	s[1].p[2] = { "nissan", 300000, 3 };

	s[2] = { owner[2].id, "compu me", "city star", "electron", 3 };
	s[2].p[0] = { "lab", 150000, 3 };
	s[2].p[1] = { "mobil", 8000, 3 };
	s[2].p[2] = { "printer", 3000, 3 };

	s[3] = { owner[3].id, "seliver", "city star", "acc", 3 };
	s[3].p[0] = { "ring", 200, 10 };
	s[3].p[1] = { "neck", 400, };
	s[3].p[2] = { "medal", 100, 3 };

}
void  regist_owner(regist owner[10], int &id)
{

	int existedowner = oldcounter;
	oldcounter++;
	cout << "you choose to registration owner \n";
	for (int i = existedowner; i < oldcounter; i++)
	{
		cout << "\t\tYOUR FIXED ID AND YOU SHOULD KEEP IT  :: " << oldcounter << "\n";
		cout << "enter your name \n";
		cin >> owner[i].name;
		owner[i].id = oldcounter;
		cout << "enter your password \n";
		cin >> owner[i].password;
		cout << "enter your age \n";
		cin >> owner[i].age;
		cout << "enter your gender \n";
		cout << "[f] for female .... [m] for male\n";
		cin >> owner[i].gender;
		cout << "enter your address \n";
		cin >> owner[i].address;


		break;
	}
};
int main()
{
	system("COLOR F0 ");
	init();
	int index = 0;
	int index2 = 0;
	int num15 = 0;
	char letter;
	char lett = 'u';
	char cond = 'j';
	while (lett != 'e')
	{
		cond = 'o';
		while (cond != 't')
		{
			system("cls");
			system("COLOR F0 ");
			int num, num1, num5, num7, num8;
			cout << "\t\t\t\t*WELCOME TO ONLINE SHOPPING STORE*\t\t" << endl;
			cout << " choose 1 if owner and 2 if shopper \n";
			cin >> num;
			if (num == 1)
			{

				cout << "choose 1 for registration and 2 if login \n";
				cin >> num1;
				if (num1 == 1)
				{
					regist_owner(owner, index);

					cout << "NOTE** \n YOU HAVE ONLY TO ADD SHOP \n";


					do
					{

						cout << "Choose an number for following operation " << endl;
						cout << "[1] add shop data " << endl;
						cin >> num7;


						if (num7 == 1)
							add_shop_data(s);
						cout << "DO YOU WANT ANY OPERATION(y/n) " << endl;
						cin >> letter;

					} while (letter == 'y');
				}
				else if (num1 == 2)

				{
					while (login_owner(owner, index) == false)
					{
						cout << "WRONG" << endl;
					}
					do
					{

						cout << "Choose an number for following operation " << endl;
						cout << "[1] add shop data " << endl;
						cout << "[2] edit data  " << endl;
						cout << "[3] add new product " << endl;
						cout << "[4] remove an product " << endl;
						cout << "[5] view all shop product " << endl;
						cin >> num7;

						if (num7 == 3)
							add_new_product(s, index);

						else if (num7 == 5)

							product_information_owner(s, index);
						else if (num7 == 1)
							add_shop_data(s);
						else if (num7 == 4)
							remove(s, index);
						else if (num7 == 2)
							edit_owner(owner, index);

						cout << "DO YOU WANT ANY OPERATION (y/n)" << index << endl;
						cin >> letter;
					} while (letter == 'y');

				}
				else if ((num1 != 1) && (num1 != 2))
				{
					cout << "INVALID ENTER\n";
					continue;
				}
			}
			else if (num == 2)
			{
				cout << "you choose shopper \n";
				cout << "choose 1 for registration and 2 for login \n";
				cin >> num5;
				if (num5 == 1)
					regist_shopper(shopper, index2);
				else if (num5 == 2)
				{

					while (login_shopper(shopper, index2) == false)
					{
						cout << "WRONG" << endl;
					}
				}
				else if ((num5 != 1) && (num5 != 2))
				{
					cout << "INVALID ENTER\n";
					continue;
				}
				do
				{
					cout << "choose an number for following operation \n";
					cout << " [1] edit your data \n";
					cout << " [2] search for specific product \n";
					cout << " [3] view product information \n";
					cout << " [4] start shopping \n";

					cin >> num8;
					if (num8 == 3)
						product_information_shopper(s);
					else if (num8 == 2)
						search(s);
					else if (num8 == 4)
						recepit(s, pro);
					else if (num8 == 1)
						edit_shopper(shopper, index2);

					cout << "DO YOU WANT ANY OPERATION (y/n)" << index << endl;
					cin >> letter;
				} while (letter == 'y');


			}

			cout << "if you want logout press t ";
			cin >> cond;
		}

		cout << "IF YOU WANT TO EXIT PRESS e ELSE PRESS ANY LETTER \n";
		cin >> lett;
	}
	system("pause");
	return 0;
}