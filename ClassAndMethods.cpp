#include <iostream>
#include <iomanip>

using namespace std;

string getPayment()
{
	char answer;
	cout << "How would you like to pay? " << "\n1. To pay with money press \"M\""
	     << "\n2. To pay with a credit card press \"C\""
	     << "\n3. To pay with gold press \"G\"" << endl;
	cin >> answer;

	switch (answer)
	{
	  case 'm':
	  case 'M': return "You are paying using money";

	  case 'c':
	  case 'C': return "You are paying by Credit Card";

	  case 'g':
	  case 'G': return "You are paying with Gold";

	  default: return "Invalid payment type, no lemonade for you!";
	}
}

double calcTotal(double subTotalCopy, const double TAX)
{
	return subTotalCopy + subTotalCopy * TAX;
}

int main()
{
	string welcome = "Welcome to Stephen's lemonade stand!";
	string customerName;
	string lemonadeName = "Traditional homemade lemonade";
	string rosemaryName = "Rosemary infused lemonade";
	string raspberryName = "Freshly squeezed raspberries and lemon";

	double lemonadePrice = 1.15;
	double rosemaryPrice = 2.35;
	double raspberryPrice = 3.10;
	double subTotal = 0;
	const double TAX = 0.08;
	double total = 0;

	int choice;
	int numberOfGlasses;
	int count = 0;

	cout << welcome << "\n\nWhat's your name? " << flush;
	getline(cin, customerName);

	bool validChoice;

	do
	{
		if (count == 3)
		{
			return 1;
		}

		count++;

		cout << "Hi there " << customerName << "!\nHere's our menu:\n1. " << lemonadeName << " ~ $" << lemonadePrice
	             << "\n2. " << rosemaryName << " ~ $" << rosemaryPrice
		     << "\n3. " << raspberryName << " ~ $" << fixed << setprecision(2) << raspberryPrice << endl;

		cout << "Which type of lemonade would you like? (1-3): " << flush;
		cin >> choice;

		switch (choice)
		{
		  case 1: cout << "Excellent choice! How many glasses of " << lemonadeName << " would you like? " << flush;
		    	  cin >> numberOfGlasses;
		    	  validChoice = true;
		    	  break;

		  case 2: cout << "One of my favorites! How many glasses of " << rosemaryName << " would you like? " << flush;
		    	  cin >> numberOfGlasses;
		    	  validChoice = true;
		    	  break;

		  case 3: cout << "A classic! How many glasses of " << raspberryName << " would you like? " << flush;
		    	  cin >> numberOfGlasses;
		    	  validChoice = true;
		    	  break;

		  default: cout << "I'm sorry, I don't recognize that choice. Please choose an option between \"1\" and \"3\"." << endl;
		    	   validChoice = false;
		    	   break;
		}
	} while (!validChoice || numberOfGlasses <= 0 || numberOfGlasses >= 20);

	if (choice == 1)
	{
		subTotal = numberOfGlasses * lemonadePrice;
		cout << numberOfGlasses << " glasses of " << lemonadeName << " costs: $" << subTotal << endl;
		total = calcTotal(subTotal, TAX);
		cout << "With tax the total comes to: " << total << endl;

	} else if (choice == 2)
	{
		subTotal = numberOfGlasses * rosemaryPrice;
		cout << numberOfGlasses << " glasses of " << rosemaryName << " costs: $" << subTotal << endl;
		total = calcTotal(subTotal, TAX);
		cout << "With tax the total comes to: " << total << endl;

	} else if (choice == 3)
	{
		subTotal = numberOfGlasses * raspberryPrice;
		cout << numberOfGlasses << " glasses of " << raspberryName << " costs: $" << subTotal << endl;
		total = calcTotal(subTotal, TAX);
		cout << "With tax the total comes to: " << total << endl;
	}

	cout << getPayment() << endl;

	cout << "Thanks for shopping at Stephen's lemonade stand " << customerName << ", please come back soon!" << endl;

	return 0;
}
