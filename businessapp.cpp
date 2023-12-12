#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
void modifyProduct(string item[], float price[], int quantity[], int count1);
void loginHeader();
bool nameCheck(string name1);
bool passwordCheck(string pass);
void signupHeader();
void adminMenuHeader();
void gotoxy(int x, int y);
void logout(string name[], string password[], string role[], int count);
void removeProduct(string item[], float price[], int quantity[], int count1);
void addProduct(string item[], float price[], int quantity[], int &count1);
float brand(string item[], float price[], int quantity[], int count1, string product, int quantity1);
bool quantityCheck(int quantity1);
bool priceCheck(float pri);
void printheader();
void viewProducts(string item[], float price[], int quantity[], int count1);
void loginAdmin(string item[], float price[], int quantity[], int count1);
void signup(string name[], string password[], string role[], int &count);
void feedback();
void logincustomer(string item[], float price[], int quantity[], int count1, string name[], string password[], string role[], int count);
string roleChecker(string name2, string pass2, string name[], string password[], string role[], int count);
void about();
void welcome();
// file handling
void loadData(string name[], string password[], string role[], int &count);
void Datastorage(string name[], string password[], string role[], int count);
string getFieldData(string data, int count);
void login(string name[], string password[], string role[], int count, string item[], float price[], int quantity[], int &count1);
void products(string item[], float price[], int quantity[], int count1);
void search(string item[], float price[], int quantity[], int count1);
void contactUs();
int main()
{
	/// variable for price name quantity of product
	int count1 = 0;
	int size = 1000;
	string item[size] = {""};
	float price[size] = {};
	int quantity[size] = {};
	// variable for login signup
	int count = 0;
	string name[100] = {""};
	string role[100] = {""};
	string password[100] = {""};
	loadData(name, password, role, count);
	welcome();
	while (true)
	{

	start:
		system("cls");
		printheader();
		cout << endl;
		cout << "Press 1,2 or 3:...." << endl;
		string press; /// string variable to press key
		cout << "1.login......." << endl
			 << "2.sign up........." << endl
			 << "3.About us....." << endl
			 << "4.Exit...." << endl;
		cin >> press;
		if (press == "1")
		{
			login(name, password, role, count, item, price, quantity, count1);
		}
		else if (press == "2")
		{
			signup(name, password, role, count);
		}
		else if (press == "3")
		{

			about();
		}
		else if (press == "4")
		{
			Datastorage(name, password, role, count);
			cout << "Thanks for visiting..." << endl;
			return 0;
		}
		else
		{
			cout << "Invalid input..." << endl;
			Sleep(2000);
			goto start;
		}
	}
}
void about()
{
	system("cls");
	SetConsoleTextAttribute(h, 6);
	cout << R"( ________  ________  ________  ___  ___  _________        ___  ___  ________      
|\   __  \|\   __  \|\   __  \|\  \|\  \|\___   ___\     |\  \|\  \|\   ____\     
\ \  \|\  \ \  \|\ /\ \  \|\  \ \  \\\  \|___ \  \_|     \ \  \\\  \ \  \___|_    
 \ \   __  \ \   __  \ \  \\\  \ \  \\\  \   \ \  \       \ \  \\\  \ \_____  \   
  \ \  \ \  \ \  \|\  \ \  \\\  \ \  \\\  \   \ \  \       \ \  \\\  \|____|\  \  
   \ \__\ \__\ \_______\ \_______\ \_______\   \ \__\       \ \_______\____\_\  \ 
    \|__|\|__|\|_______|\|_______|\|_______|    \|__|        \|_______|\_________\
                                                                      \|_________|)"
		 << endl;
	SetConsoleTextAttribute(h, 13);
	cout << "Welcome to ClickNShop Hub - Your Ultimate Destination for Seamless Online Shopping Delight!" << endl;
	cout << endl;
	cout << "At ClickNShop Hub, we redefine your shopping experience, transforming it into a world of convenience and joy. As your one-stop destination for all your needs, we curate a diverse and exciting range of products to cater to every aspect of your lifestyle." << endl;
	cout << endl;
	cout << "Discover a wonderland of choices at ClickNShop Hub, where each click takes you on a delightful journey from browsing to doorstep delivery. Whether you're a tech aficionado, a fashion trendsetter, or a home decor enthusiast, our hub offers a plethora of options to satisfy your desires." << endl;
	cout << endl;
	cout << "Embrace the joy of hassle-free shopping, where the latest trends meet affordability, and quality meets convenience. ClickNShop Hub is more than just an online store; it's a vibrant community built on the pillars of choice, reliability, and customer satisfaction." << endl;
	cout << endl;
	cout << "Join us on this exciting adventure – Click, Shop, and Delight with ClickNShop Hub!" << endl;
	cout << endl;
	SetConsoleTextAttribute(h, 8);
	cout << "Press any key to go back." << endl;
	getch();
}

void Datastorage(string name[], string password[], string role[], int count)
{
	fstream storeFile;
	// string data = "";
	storeFile.open("data.txt", ios::out);
	for (int i = 0; i < count; i++)
	{
		storeFile << name[i] << "," << password[i] << "," << role[i];
		if (i != count - 1)
		{
			storeFile << endl;
		}
		// data = "";
	}
	storeFile.close();
}
string getFieldData(string data, int count)
{
	string result = "";
	int comma = 0;
	for (int i = 0; i < data.length(); i++)
	{
		if (data[i] == ',')
		{
			comma++;
		}
		else if (comma == count)
		{
			result += data[i];
		}
		else if (comma > count)
		{
			break;
		}
	}
	return result;
}
void loadData(string name[], string password[], string role[], int &count)
{
	fstream loadFile;
	string data = "";
	loadFile.open("data.txt", ios::in);
	while (!loadFile.eof())
	{
		getline(loadFile, data);
		name[count] = getFieldData(data, 0);
		password[count] = getFieldData(data, 1);
		role[count] = getFieldData(data, 2);
		count++;
	}
	loadFile.close();
}
void login(string name[], string password[], string role[], int count, string item[], float price[], int quantity[], int &count1)
{
start:
	system("cls");
	loginHeader();
	// cout<<name[0] << name[1] <<endl;
	string name2; /// variable for login
	string pass2; /// variable for login
	cout << "Enter your name:...." << endl;
	cin >> name2;
	cout << "Enter your password:...." << endl;
	cin >> pass2;
	string result = roleChecker(name2, pass2, name, password, role, count);
	if (result == "admin")
	{
		loginAdmin(item, price, quantity, count1);
	}
	else if (result == "customer")
	{

		logincustomer(item, price, quantity, count1, name, password, role, count);
	}
	else
	{

		cout << "Invalid input......" << endl;
		cout << "Don't have account. want to register.." << endl;
		cout << "Press 1 or 2" << endl;
		cout << "want to register.." << endl;
		cout << "\t"
			 << "or" << endl;
		cout << "try again..." << endl;
		string press;
		cin >> press;
		if (press == "1")
		{

			signup(name, password, role, count);
		}
		else if (press == "2")
		{

			Sleep(2000);
			goto start;
		}
		else
		{
			cout << "Press correct key." << endl;
		}
	}
}
void signup(string name[], string password[], string role[], int &count)
{
start1:
	system("cls");
	signupHeader();
	cout << endl;
	string name1;
	// int count1=1;
	// while(count!=0){

	cout << "Enter your name:..." << endl;
	cin >> name1;
	if (!nameCheck(name1))
	{
		cout << "Incorrect Character Entered." << endl;
		// continue;
		cin.clear();
		cin.ignore();
		goto start1;
	}
// }
start:
	string pass;
	cout << "Set password....." << endl;
	cin >> pass;
	if (!passwordCheck(pass))
	{
		cout << "Password must have atleast eight characters." << endl;

		goto start;
	}
	string role1;
	cout << "You want to sign up as administrator or customer: ";
	cin >> role1;
	for (int i = 0; i < count; i++)
	{
		if (name[i] == name1 && password[i] == pass && role[i] == role1)
		{
			cout << "Account already exists." << endl;
			Sleep(2000);
			goto start1;
		}
	}
	cout << "Congratulation! You have successfully created the account." << endl;
	name[count] = name1;
	password[count] = pass;
	role[count] = role1;
	count++;
}
bool nameCheck(string name1)
{
	for (int i = 0; name1[i] != '\0'; i++)
	{
		if (!((name1[i] >= 'A' && name1[i] <= 'Z') || (name1[i] >= 'a' && name1[i] <= 'z') || (name1[i] >= '0' && name1[i] <= '9') || (name1[i] == '_')))
		{
			return false;
		}
	}
	return true;
}
bool passwordCheck(string pass)
{
	if (pass.length() < 6)
	{
		return false;
	}
	return true;
}
float brand(string item[], float price[], int quantity[], int count1, string product, int quantity1)
{
	for (int i = 0; i < count1; i++)
	{
		if (item[i] == product)
		{
			if (quantity[i] >= quantity1)
			{
				quantity[i] -= quantity1;
				return price[i] * quantity1;
			}
			else
			{
				return -1.0f;
			}
		}
	}
	return -2.0f;
}

void printheader()
{

	cout << R"( ________  ___       ___  ________  ___  __    ________   ________  ___  ___  ________  ________        ___  ___  ___  ___  ________     
|\   ____\|\  \     |\  \|\   ____\|\  \|\  \ |\   ___  \|\   ____\|\  \|\  \|\   __  \|\   __  \      |\  \|\  \|\  \|\  \|\   __  \    
\ \  \___|\ \  \    \ \  \ \  \___|\ \  \/  /|\ \  \\ \  \ \  \___|\ \  \\\  \ \  \|\  \ \  \|\  \     \ \  \\\  \ \  \\\  \ \  \|\ /_   
 \ \  \    \ \  \    \ \  \ \  \    \ \   ___  \ \  \\ \  \ \_____  \ \   __  \ \  \\\  \ \   ____\     \ \   __  \ \  \\\  \ \   __  \  
  \ \  \____\ \  \____\ \  \ \  \____\ \  \\ \  \ \  \\ \  \|____|\  \ \  \ \  \ \  \\\  \ \  \___|      \ \  \ \  \ \  \\\  \ \  \|\  \ 
   \ \_______\ \_______\ \__\ \_______\ \__\\ \__\ \__\\ \__\____\_\  \ \__\ \__\ \_______\ \__\          \ \__\ \__\ \_______\ \_______\
    \|_______|\|_______|\|__|\|_______|\|__| \|__|\|__| \|__|\_________\|__|\|__|\|_______|\|__|           \|__|\|__|\|_______|\|_______|
                                                            \|_________|                                                                 )";
}
// void function for login function
string roleChecker(string name2, string pass2, string name[], string password[], string role[], int count)
{
	for (int i = 0; i <= count; i++)
	{
		if (name[i] == name2 && password[i] == pass2)
		{
			return role[i];
		}
	}
	return "user not found";
}

void addProduct(string item[], float price[], int quantity[], int &count1)
{
	string product;
	cout << "Enter product name: " << endl;
	cin >> product;
start:
	float pri;
	cout << "Entert price of product: " << endl;
	cin >> pri;
	if (!priceCheck(pri))
	{
		cout << "Incorrect Entry." << endl;
		goto start;
	}
	int quantity1;
start1:
	cout << "Enter quantity of products: " << endl;
	cin >> quantity1;
	if (!quantityCheck(quantity1))
	{
		cout << "Incorrect Entry" << endl;
		goto start1;
	}
	item[count1] = product;
	price[count1] = pri;
	quantity[count1] = quantity1;
	count1++;
	cout << "Press any key to go back." << endl;
	getch();
}
bool priceCheck(float pri)
{
	if (pri < 1)
	{
		return false;
	}
	return true;
}
bool quantityCheck(int quantity1)
{
	if (quantity1 < 1)
	{
		return false;
	}
	return true;
}
void modifyProduct(string item[], float price[], int quantity[], int count1)
{
	system("cls");
	adminMenuHeader();
	cout << "Press 1 , 2 or 3...." << endl;
	cout << "1.Want to change price...." << endl;
	cout << "2.Want to cahnge quantity...." << endl;
	cout << "3.Want to change both...." << endl;
	string press;
	cin >> press;
	if (press == "1")
	{

		string name;
		cout << "Enter the name of the product to update: " << endl;
		cin >> name;
		int w = 0;
		for (int i = 0; i < count1; i++)
		{
			if (item[i] == name)
			{
				w++;
			}
		}
		if (w == 0)
		{
			cout << "Product not found..." << endl;
		}
		if (w >= 1)
		{
		start:
			float pr;
			cout << "Enter new price: " << endl;
			cin >> pr;
			if (!priceCheck(pr))
			{
				cout << "Incorrect Entry" << endl;
				goto start;
			}
			for (int i = 0; i < count1; i++)
			{
				if (item[i] == name)
				{
					price[i] = pr;
					// quantity[i] = quantity1;
				}
				else
				{
					cout << "Product not found..." << endl;
				}
			}
		}
		if (press == "2")
		{

		start1:
			string name;
			cout << "Enter the name of the product to update: " << endl;
			cin >> name;

			int quantity1;
			cout << "Enter quantity:" << endl;
			cin >> quantity1;
			if (!quantityCheck(quantity1))
			{
				cout << "Incorrect Entry" << endl;
				goto start1;
			}
			for (int i = 0; i < count1; i++)
			{
				if (item[i] == name)
				{
					quantity[i] = quantity1;
					cout << "Product updated successfully..." << endl;
				}
			}
		}
		if (press == "3")
		{

			string name;
			cout << "Enter the name of the product to update: " << endl;
			cin >> name;
		Start:
			float pr;
			cout << "Enter new price: " << endl;
			cin >> pr;
			if (!priceCheck(pr))
			{
				cout << "Incorrect Entry" << endl;
				goto Start;
			}

		start2:
			int quantity1;
			cout << "Enter quantity:" << endl;
			cin >> quantity1;
			if (!quantityCheck(quantity1))
			{
				cout << "Incorrect Entry" << endl;
				goto start2;
			}
			for (int i = 0; i < count1; i++)
			{
				if (item[i] == name)
				{
					quantity[i] = quantity1;
					price[i] = pr;
					cout << "Product updated successfully..." << endl;
				}
			}
		}
	}
	cout << "Press any key to go back." << endl;
	getch();
}
void removeProduct(string item[], float price[], int quantity[], int count1)
{
	string name;
	cout << "Enter the produt name to remove: " << endl;
	cin >> name;
	for (int i = 0; i < count1; i++)
	{
		if (item[i] == name)
		{
			for (int j = i; j < count1 - 1; j++)
			{
				item[j] = item[j + 1];
				price[j] = price[j + 1];
				quantity[j] = quantity[j + 1];
			}
			count1--;
			break;
		}
	}
	cout << "Press any key to go back." << endl;
	getch();
}
void viewProducts(string item[], float price[], int quantity[], int count1)
{
	cout << "Number \t\t\t\t"
		 << "Product Name \t\t\t\t"
		 << "Price \t\t\t\t"
		 << "Quantity" << endl;
	for (int i = 0; i < count1; i++)
	{
		cout << 1 + i << "\t\t\t\t" << item[i] << "\t\t\t\t" << price[i] << "\t\t\t\t" << quantity[i] << endl;
	}
	cout << "Press any key to go back." << endl;
	getch();
}
void adminMenuHeader()
{

	cout << R"( ________  ________  _____ ______   ___  ________           _____ ______   _______   ________   ___  ___     
|\   __  \|\   ___ \|\   _ \  _   \|\  \|\   ___  \        |\   _ \  _   \|\  ___ \ |\   ___  \|\  \|\  \    
\ \  \|\  \ \  \_|\ \ \  \\\__\ \  \ \  \ \  \\ \  \       \ \  \\\__\ \  \ \   __/|\ \  \\ \  \ \  \\\  \   
 \ \   __  \ \  \ \\ \ \  \\|__| \  \ \  \ \  \\ \  \       \ \  \\|__| \  \ \  \_|/_\ \  \\ \  \ \  \\\  \  
  \ \  \ \  \ \  \_\\ \ \  \    \ \  \ \  \ \  \\ \  \       \ \  \    \ \  \ \  \_|\ \ \  \\ \  \ \  \\\  \ 
   \ \__\ \__\ \_______\ \__\    \ \__\ \__\ \__\\ \__\       \ \__\    \ \__\ \_______\ \__\\ \__\ \_______\
    \|__|\|__|\|_______|\|__|     \|__|\|__|\|__| \|__|        \|__|     \|__|\|_______|\|__| \|__|\|_______|
                                                                                                                    
)" << endl;
}
void loginAdmin(string item[], float price[], int quantity[], int count1)
{
start:
	adminMenuHeader();
	string choice;
	cout << "........Admin menu........" << endl;
	cout << "1.Add Product" << endl;
	cout << "2.Modify Product" << endl;
	cout << "3.Remove Product" << endl;
	cout << "4.View products" << endl;
	cin >> choice;
	if (choice == "1")
	{
		addProduct(item, price, quantity, count1);
	}
	if (choice == "2")
	{
		modifyProduct(item, price, quantity, count1);
	}
	if (choice == "3")
	{
		removeProduct(item, price, quantity, count1);
	}
	else if (choice == "4")
	{
		viewProducts(item, price, quantity, count1);
	}
	else
	{
		cout << "Wrong input";
		Sleep(2000);
		goto start;
	}
}
void products(string item[], float price[], int quantity[], int count1)
{
	printheader();
	string product;
	int quantity1;
	cout << "Enter the product name: ";
	cin >> product;
	cout << "Enter the quantity: ";
	cin >> quantity1;
	float result;
	result = brand(item, price, quantity, count1, product, quantity1);
	if (result >= 0.0f)
	{
		// Successful transaction
		cout << "Transaction successful. Total price: " << result << endl;
	}
	else if (result == -1.0f)
	{
		// Insufficient quantity
		cout << "Required quantity is not available." << endl;
	}
	else if (result == -2.0f)
	{
		// Product not found
		cout << "Product not found." << endl;
	}
	printheader();
	gotoxy(20, 9);
	cout << "Product name";
	gotoxy(20, 10);
	cout << product;
	gotoxy(60, 9);
	cout << "Quantity";
	gotoxy(60, 10);
	cout << quantity;
	gotoxy(15, 14);
	cout << "______________________________";
	gotoxy(15, 16);
	cout << "Total price: ";
	gotoxy(30, 16);
	cout << "Rs " << result;
}
void logout(string name[], string password[], string role[], int count)
{
	string name1;
	cout << "Enter your name: " << endl;
	cin >> name1;
	for (int i = 0; i < count; i++)
	{
		if (name[i] == name1)
		{
			for (int j = i; j < count - 1; j++)
			{
				name[j] = name[j + 1];
				password[j] = password[j + 1];
				role[j] = role[j + 1];
			}
			count--;
			break;
		}
	}
}
void logincustomer(string item[], float price[], int quantity[], int count1, string name[], string password[], string role[], int count)
{
	while (true)
	{
		system("cls");
		string press;
		cout << "Press 1 0r 2" << endl;
		cout << "1.Buy Product" << endl;
		cout << "2.View products" << endl;
		cout << "3.Search product" << endl;
		cout << "3.Give FeedBack" << endl;
		cout << "4.Go Back" << endl;

		cout << "5.Log out" << endl;

		cin >> press;
		if (press == "1")
		{
			products(item, price, quantity, count1);
		}
		else if (press == "2")
		{
			viewProducts(item, price, quantity, count1);
		}
		else if (press == "3")
		{

			search(item, price, quantity, count1);
		}
		else if (press == "3")
		{

			feedback();
		}
		else if (press == "4")
		{

			contactUs();
		}
		else if (press == "4")
		{
			getch();
		}
		else if (press == "5")
		{
			logout(name, password, role, count);
		}
		else
		{
			cout << "Invalid Input" << endl;
		}
	}
}
void search(string item[], float price[], int quantity[], int count1)
{
start:
	system("cls");
	cout << "Enter the name of product" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < count1; i++)
	{
		if (item[i] == name)
		{
			cout << name << " Exists" << endl;
			cout << "Quantity: " << quantity[i] << endl;
			cout << "Price: " << price[i] << endl;
		}
		else
		{
			cout << "Product not found" << endl;
			cout << "Press 1 or 2" << endl;
			string press;
			cout << "1.Search again." << endl;
			cout << "2.Go Back." << endl;
			cin >> press;
			if (press == "1")
			{
				goto start;
			}
			else if (press == "2")
			{
				getch();
			}
			else
			{
				cout << "Invalid Input." << endl;
			}
		}
	}
}
void feedback()
{
	system("cls");
	cout << "Your feedback." << endl;
	string feedback;
	cin >> feedback;
	cout << "Thanks for feedback." << endl;
	// start:
	string press;
	cout << "Press any key to go back." << endl;
	getch();
	// else
	// cout<<"Invalid input...."<<endl;
	// Sleep(2000);
	// goto start;
}
void welcome()
{
	SetConsoleTextAttribute(h, 10);
	cout << R"(
 ___       __   _______   ___       ________  ________  _____ ______   _______      
|\  \     |\  \|\  ___ \ |\  \     |\   ____\|\   __  \|\   _ \  _   \|\  ___ \     
\ \  \    \ \  \ \   __/|\ \  \    \ \  \___|\ \  \|\  \ \  \\\__\ \  \ \   __/|    
 \ \  \  __\ \  \ \  \_|/_\ \  \    \ \  \    \ \  \\\  \ \  \\|__| \  \ \  \_|/__  
  \ \  \|\__\_\  \ \  \_|\ \ \  \____\ \  \____\ \  \\\  \ \  \    \ \  \ \  \_|\ \ 
   \ \____________\ \_______\ \_______\ \_______\ \_______\ \__\    \ \__\ \_______\
    \|____________|\|_______|\|_______|\|_______|\|_______|\|__|     \|__|\|_______|
                                                                                    
)"
		 << "\n\nWelcome to CLICKNSHOP HUB!\n";
	SetConsoleTextAttribute(h, 12);
	cout << "Press any key to start" << endl;
	getch();
	SetConsoleTextAttribute(h, 7);
}

void loginHeader()
{
	cout << R"( ___       ________  ________          ___  ________      
|\  \     |\   __  \|\   ____\        |\  \|\   ___  \    
\ \  \    \ \  \|\  \ \  \___|        \ \  \ \  \\ \  \   
 \ \  \    \ \  \\\  \ \  \  ___       \ \  \ \  \\ \  \  
  \ \  \____\ \  \\\  \ \  \|\  \       \ \  \ \  \\ \  \ 
   \ \_______\ \_______\ \_______\       \ \__\ \__\\ \__\
    \|_______|\|_______|\|_______|        \|__|\|__| \|__|
                                                          
)";
}
void signupHeader()
{
	cout << R"( ________  ___  ________  ________           ___  ___  ________   
|\   ____\|\  \|\   ____\|\   ___  \        |\  \|\  \|\   __  \  
\ \  \___|\ \  \ \  \___|\ \  \\ \  \       \ \  \\\  \ \  \|\  \ 
 \ \_____  \ \  \ \  \  __\ \  \\ \  \       \ \  \\\  \ \   ____\
  \|____|\  \ \  \ \  \|\  \ \  \\ \  \       \ \  \\\  \ \  \___|
    ____\_\  \ \__\ \_______\ \__\\ \__\       \ \_______\ \__\   
   |\_________\|__|\|_______|\|__| \|__|        \|_______|\|__|   
   \|_________|                                                   
                                                                  )";
}
void gotoxy(int x, int y)
{
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void contactUs()
{
	system("cls");
	cout << "CONTACT US" << endl;
	cout << "------------" << endl;
	cout << "At ClickNShop Hub, we value your feedback and are here to assist you. If you have any questions, concerns, or suggestions, please feel free to contact us through the following channels:" << endl
		 << endl;

	cout << "Customer Support Email: support@clicknshophub.com" << endl;
	cout << "Phone Number: +1 (XXX) XXX-XXXX" << endl;
	cout << "Live Chat: Visit our website and click on the 'Chat with Us' option" << endl
		 << endl;

	cout << "Our dedicated customer support team is available to help you from Monday to Friday, 9:00 AM to 6:00 PM. We strive to respond to your inquiries as quickly as possible." << endl
		 << endl;

	cout << "Thank you for choosing ClickNShop Hub for your online shopping needs. We look forward to serving you!" << endl
		 << endl;

	cout << "Press any key to go back." << endl;
	getch();
}
