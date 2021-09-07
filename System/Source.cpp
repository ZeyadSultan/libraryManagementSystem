#include <iostream>
#include <string>

using namespace std;

//structure holds all the dates of the system
struct Date
{
	int day, year, month;
}dateOfToday;

//structure holds all the user informations
struct userInf
{
	long long IDNumber;
	string name;
	string email;
	string password;
	char type;
	Date date;
	int noOfContacts;
	long long contacts[3];
}user[100];

//struct holds the nook informations
struct bookInf
{
	string title;
	string year;
	int noOfCopies;
	string category;
	string eddition;
}book[100];

int noOfBooks;

int userIndex;

void newUser(int j);

void menu();

void search();

void buy();

void generate(int noOfUsers);

void stringValid(string string);

void integerValid(int integer);

void charValid(char character);

void longValid(long long number);

int main()
{
	struct libInf
	{
		string libUser;
		string libPass;
	}librarian[4];

	cout << "************WELCOME TO OUR LIBRARY SYSTEM************\n\n";

	//setting the librarians usernames and password
	string libUser, libPass;
	librarian[0] = { "zeyad1","zeyad_1" };
	librarian[1] = { "seif2","seif_2" };
	librarian[2] = { "salma3","salma_3" };
	librarian[3] = {"rana4","rana_4"};

	//letting the librarian input his username and passwod and then validating them
	bool libValid = false;
	int count1 = 0,i;
	while (libValid == false)
	{
		if (count1 > 0)
		{
			cout << "Your Username or passward is'nt correct, try again\n";
		}
		cout << "Please Enter your Username & Password: \n";
		cout << "username: ";
		cin >> libUser;
		cout << "Password: ";
		cin >> libPass;
		for (i = 0; i < 4; i++)
		{
			if (libUser == librarian[i].libUser && libPass == librarian[i].libPass)
			{
				libValid = true;
				break;
			}
			else
			{
				libValid = false;
			}
		}
		count1++;
	}
	cout << "\n***WELCOME " << librarian[i].libUser << "***\n\n";

	//letting the librarian inputs the books that was in the library
	cout << "How many books in the library (1 -> 100) ? ";
	cin >> noOfBooks;
	integerValid(noOfBooks);
	while (noOfBooks == 0 || noOfBooks > 100)
	{
		cout << "No. of books must be less than 101 and greater than 0 \nEnter a valid ans: ";
		cin >> noOfBooks;
	}
	for (int i = 0; i < noOfBooks; i++)
	{
		cout << "Enter book " << i + 1 << " Information:-\n";
		cout << "Enter book's title: "; cin.ignore(); getline(cin, book[i].title);
		bool yearValid = false;
		while (yearValid == false)
		{
			cout << "Enter year of production: "; cin >> book[i].year;
			int z = stoi(book[i].year);
			if (z < 1000 || z>2020)
			{
				cout << "Enter a valid year (1000 - 2020) \n";
				yearValid = false;
			}
			else
			{
				yearValid = true;
			}
		}
		cout << "Enter book's category: "; cin.ignore(); getline(cin, book[i].category);
		stringValid(book[i].category);
		cout << "Enter book's edition(first,second,....) : ";  getline(cin, book[i].eddition);
		stringValid(book[i].eddition);
		cout << "Enter no. of copies: "; cin >> book[i].noOfCopies;
		integerValid(book[i].noOfCopies);
		cout << "\n";
		cout << "Book " << i + 1 << " information inserted successfully.\n\n";
	}

	//creating the first user
	int noOfUser = 0;
	newUser(noOfUser);
	noOfUser++;

	//asking the librarian what he wants to do
	bool cont = true;
	while (cont == true)
	{
		cout << "Choose what do you want to do?\n";
		int answer;
		cout << "1.create a new user\n2.generate a report\n";
		cin >> answer;
		integerValid(answer);
		while (answer != 1 && answer != 2)
		{
			cout << "Please choose a valid choise (1 or 2)!\n";
			cin >> answer;
		}
		if (answer == 1)
		{
			bool createNewUser = false;
			string x;
			do
			{
				newUser(noOfUser);
				cout << "Do you want to create another user?(y/n)  "; cin >> x;
				while (x != "y" && x != "n")
				{
					cout << "Enter a valid answer: "; cin >> x;
				}
				if (x == "y")
				{
					createNewUser = true;
					noOfUser++;
				}
				else if (x == "n")
				{
					createNewUser = false;
				}
			} while (createNewUser == true);
		}
		else if (answer == 2)
		{
			generate(noOfUser);
		}
		cout << "\nDo you want to make something else? (y/n) ";
		char a;
		cin >> a;
		charValid(a);
		while (a != 'y' && a != 'n')
		{
			cout << "Enter a valid answer: "; cin >> a;
		}
		cout << "\n";
		if (a == 'y')
		{
			cont = true;
		}
		else if (a == 'n')
		{
			cont = false;
		}
	}

	//the user starts to sign in to access his account and choose what he want to do
	string userE, userP;
	bool userValid = false;
	int count2 = 0;
	while (userValid == false)
	{
		if (count2 > 0)
		{
			cout << "Your Email or passward is'nt correct, try again\n";
		}
		cout << "Hello user Enter your email & password to access your user account: \n";
		cout << "Email: ";
		cin >> userE;
		cout << "Password: ";
		cin >> userP;
		cout << "\n";
		for (int k = 0; k <= noOfUser; k++)
		{
			if (userE == user[k].email && userP == user[k].password)
			{
				userValid = true;
				userIndex = k;
				break;
			}
			else
			{
				userValid = false;
			}
		}
		count2++;
	}

	cout << "***WELCOME " << user[userIndex].name << "***\n\n";

	//openning the menu for the user
	menu();
	return 0;
}

void newUser(int i)
{
	cout << "Enter user " << i + 1 << " information: \n";
	cout << "ID: "; cin >> user[i].IDNumber;
	longValid(user[i].IDNumber);
	cout << "Name: "; cin.ignore(); getline(cin, user[i].name);
	stringValid(user[i].name);
	cout << "Email: "; cin >> user[i].email;
	cout << "Password: "; cin >> user[i].password;
	while (user[i].password.size() < 5)
	{
		cout << "Your password must contain more than 4 elements!\n Password: "; cin >> user[i].password;
	}
	cout << "Enter your Account type (s -> staff, g -> guest, t -> student): ";  cin >> user[i].type;
	charValid(user[i].type);
	while (user[i].type != 's' && user[i].type != 'g' && user[i].type != 't')
	{
		cout << "Enter a valid type! : ";
		cin >> user[i].type;
	}
	cout << "Enter the date of creation(day/month/year): ";
	bool dateValid = false;
	while (dateValid == false) {
		cin >> user[i].date.day; integerValid(user[i].date.day);
		cin >> user[i].date.month; integerValid(user[i].date.month);
		cin>> user[i].date.year; integerValid(user[i].date.year);
		if (user[i].date.day < 1 || user[i].date.day>31 || user[i].date.month < 1 || user[i].date.month>12 || user[i].date.year > 2020 || user[i].date.year < 1000)
		{
			cout << "This date is not valid please enter a valid one: ";
			dateValid = false;
		}
		else
		{
			dateValid = true;
		}
	}
	cout << "How many contacts do you have(must be less than or equal 3): "; cin >> user[i].noOfContacts;
	integerValid(user[i].noOfContacts);
	while (user[i].noOfContacts > 3 || user[i].noOfContacts <= 0)
	{
		cout << "you must have contacts and must be less than 4: "; cin >> user[i].noOfContacts;
	}
	//validating contact input
	for (int j = 0; j < user[i].noOfContacts; j++)
	{
		cout << "Enter contact " << j + 1 << ": ";
		cin >> user[i].contacts[j];
		longValid(user[i].contacts[j]);
	}
	cout << "\nThe user account have been done successfully\n";
	cout << "\n";
};

void search()
{
	string inpBook;
	bool bookValid = false;
	int i = 0;
	cin.ignore();
	while (bookValid == false)
	{
		if (i > 0)
		{
			cout << "the book title or production year arent found, please try again: \n";
		}
		cout << "Enter the book title or production year: \n";
		getline(cin, inpBook);
		for (int k = 0; k < noOfBooks; k++)
		{
			if (inpBook == book[k].title)
			{
				bookValid = true;
			}
			else if (inpBook == book[k].year)
			{
				bookValid = true;
			}
			if (bookValid == true)
			{
				cout << "The book that you are looking for information are: \n";
				cout << "Name: " << book[k].title << "\n";
				cout << "year of production: " << book[k].year << "\n";
				cout << "NO. of copies: " << book[k].noOfCopies << "\n";
				cout << "Edition: " << book[k].eddition << "\n";
				cout << "Category: " << book[k].category << "\n";
				cout << "\n";
			}
		}
		i++;
	}

};

void menu()
{
	int ans;
	bool again = true;
	while (again == true)
	{
		cout << "Choose what do you want to do (1/2) :\n";
		cout << "1 -> search for a book?\n";
		cout << "2 -> buy a book?\n";
		cin >> ans;
		integerValid(ans);
		while (ans != 1 && ans != 2)
		{
			cout << "Please choose a valid choise (1 or 2)!\n";
			cin >> ans;
		}
		if (ans == 1)
		{
			search();
		}
		else if (ans == 2)
		{
			if (user[userIndex].type != 's') {
				cout << "your user type isnt able to buy a book\n";
			}
			else 
			{
				buy();
			}
		}
		cout << "\nDo you want to make something else? (y/n)\n";
		char answer;
		cin >> answer;
		charValid;
		while (answer != 'y' && answer != 'n')
		{
			cout << "Enter a valid answer: "; cin >> answer;
		}
		if (answer == 'y')
		{
			again = true;
		}
		else if (answer == 'n')
		{
			again = false;
		}
	}
}

void buy()
{
	string inpBook;
	bool bookValid = false;
	int i = 0, bookIndex;
	cin.ignore();
	if (user[userIndex].type != 's') 
	{
		cout << "Sorry! Your account type isnt valid to buy a book.\n";
	}
	else
	{
		while (bookValid == false)
		{
			if (i > 0)
			{
				cout << "the book title is'nt found, please try again: \n";
			}
			cout << "Enter the title of the book you want to buy : \n";
			getline(cin, inpBook);
			for (int k = 0; k < noOfBooks; k++)
			{
				if (inpBook == book[k].title)
				{
					bookValid = true;
					bookIndex = k;
					break;
				}
			}
			i++;
		}
		if (bookValid == true)
		{
			if (book[bookIndex].noOfCopies > 0)
			{
				book[bookIndex].noOfCopies--;
				cout << "The buying operation for " << book[bookIndex].title << " was successfull.\n";
			}
			else
			{
				cout << "No. of copies of this book has been finished.\n";
			}
		}
	}
};

void generate(int noOfUsers)
{
	cout << "Enter the date of today(day-month-year): ";
	bool dateValid = false;
	while (dateValid == false) {
		cin >> dateOfToday.day; integerValid(dateOfToday.day);
		cin >> dateOfToday.month; integerValid(dateOfToday.month);
		cin >> dateOfToday.year; integerValid(dateOfToday.year);
		if (dateOfToday.day < 1 || dateOfToday.day>31 || dateOfToday.month < 1 || dateOfToday.month>12 || dateOfToday.year != 2020)
		{
			cout << "This date is not valid please enter a valid one: ";
			dateValid = false;
		}
		else
		{
			dateValid = true;
		}
	}
	cout << "\n";

	int counter = -1;
	for (int i = 0; i <= noOfUsers; i++)
	{
		bool userReport = false;
		if (dateOfToday.year - user[i].date.year == 1 && dateOfToday.month == 1 && user[i].date.month == 12)
		{
			if ((dateOfToday.day + user[i].date.day) % 31 <= 7)
			{
				userReport = true;
			}
		}
		else if (dateOfToday.month == user[i].date.month) 
		{
			if (dateOfToday.day - user[i].date.day >= 0 && dateOfToday.day - user[i].date.day <= 7)
			{
				userReport = true;
			}
		}
		else if (dateOfToday.month - user[i].date.month == 1) 
		{
			if ((dateOfToday.day + user[i].date.day) % 31 <= 7)
			{
				userReport = true;
			}
		}
		if (userReport == true)
		{
			cout << "The information of the users that was done in the last 7 days \n\n";
			cout << "Information of user " << i + 1 << " :\n";
			cout << "ID: " << user[i].IDNumber << "\n";
			cout << "Name: " << user[i].name << "\n";
			cout << "Email: " << user[i].email << "\n";
			cout << "Password: " << user[i].password << "\n";
			cout << "Type: ";
			if (user[i].type == 's')
			{
				cout << "Staff\n";
			}
			else if (user[i].type == 'g')
			{
				cout << "Guest\n";
			}
			else
			{
				cout << "Student\n";
			}
			cout << "Creation date: " << user[i].date.day << "/" << user[i].date.month << "/" << user[i].date.year << "\n";
			for (int j = 0; j < user[i].noOfContacts; j++)
			{
				cout << "contact " << j + 1 << " :" << user[i].contacts[j] << "\n";
			}
		}
		else if (userReport == false)
		{
			counter++;
		}
	}
	if (counter == noOfUsers)
	{
		cout << "There is no users created in the last 7 days.\n";
	}
}

void stringValid(string string)
{
	bool valid=false;
	while (valid == false)
	{
		for (int i = 0; i < string.size(); i++)
		{
			if (isdigit(string[i]) || string[i] == '.' || string[i] == '-' || string[i] == '!' || string[i] == '_' || string[i] == ',' || string[i] == '?')
			{
				valid = false;
				break;
			}
			else
				valid = true;
		}
		if (valid == false)
		{
			cout << "Enter a valid name: "; cin >> string;
		}
	}
}

void integerValid(int integer)
{
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You have entered wrong input: "; cin >> integer;
		}
		if (!cin.fail())
		{
			break;
		}
	}
}

void longValid(long long number)
{
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You have entered wrong input: "; cin >> number;
		}
		if (!cin.fail())
		{
			break;
		}
	}
}

void charValid(char character)
{
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You have entered wrong input: "; cin >> character;
		}
		if (!cin.fail())
		{
			break;
		}
	}
}