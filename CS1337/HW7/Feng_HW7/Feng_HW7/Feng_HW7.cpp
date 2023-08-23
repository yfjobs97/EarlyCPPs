//HW #7
//Drink Machine Simulator
//By default, 10 kinds of drinks with 20 in stock are available to choose. The maximum monetary input allowance is the double of the most expensive drink.
//Change will not be returned until the user exits the programme.

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int TYPES = 10; //Types of drinks

struct Machine
{
    string name;
    double cost;
    int amount;

};

//Structure for money management
struct MoneyMGN
{
	double input;
	double change = 0;
	double paid;
	double due;
	double greatest;
};

double initialise (Machine[]);
void show_Drink (Machine[]);
bool home (int &, Machine[], MoneyMGN*);
void pay(Machine[], MoneyMGN*, int);


int main ()
{
    bool cont = true; // Flag for the continuation of the menu
    Machine Drink [TYPES];
	MoneyMGN payment;
	int runtime = 0;
	cout << fixed << showpoint << setprecision(2);
	cout << "ICE COLD Drinks Vending Machine" << endl;
	payment.greatest = initialise(Drink);

	do
	{

		cont = home(runtime, Drink, &payment);


	} while (cont);

	system("pause");
    return 0;
}

//Function that scans through the available drinks, price, and availability
double initialise(Machine Drink[TYPES])
{
	Drink[0] = { "Cola", 0.75, 20 };
	Drink[1] = { "Root Beer", 0.75, 20 };
	Drink[2] = { "Lemon Lime", 0.75, 20 };
	Drink[3] = { "Grape Soda", 0.80, 20 };
	Drink[4] = { "Cream Soda", 0.80, 20 };
	Drink[5] = { "Sprite", 1.80, 20 };
	Drink[6] = { "Fanta", 1.50, 20 };
	Drink[7] = { "Sweet Tea", 2.55, 20 };
	Drink[8] = { "Powerade", 1.85, 20 };
	Drink[9] = { "Gatorade", 2.80, 20 };

	// Finding the highest price by selection sort, and double the result for the greatest price allowed to input
	double prices [TYPES];
	for (int i = 0; i < TYPES; i++)
	{
		prices[i] = Drink[i].cost;
	}
	int minPos = 0;
	for (int i = 0; i < TYPES -1; i++)
	{
		for (int j = i + 1; j < TYPES; j++)
		{
			if (prices[j] < prices[minPos])
				minPos = j;
		}
		double temp;
		temp = prices[minPos];
		prices[minPos] = prices[i];
		prices[i] = temp;
	}
	double greatest_price;
	greatest_price = prices[TYPES - 1] * 2;
	cout << "NOTICE: The greatest money input allowed is $" << greatest_price << endl;
	return greatest_price;
}

//Function that display the drinks on the screen
void show_Drink(Machine drink[TYPES])
{
	cout << "Drink Name \t" << "Price" << endl;
	for (int i = 0; i < TYPES; i++)
	{
		cout << i+1 << ". " << drink[i].name;
		cout.width(4);
		cout  << "\t$" << drink[i].cost << endl;
	}
	return;
}


//Function interacting with the user during the buying process
bool home(int& runtime, Machine Drink[TYPES], MoneyMGN* payment )
{
	int drink_num;
	double change = payment->change;

	show_Drink(Drink);
	//Welcome Screen
	if (runtime == 0)
		cout << "Select a drink or input 0 to quit." << endl; // Selection prompt for the first purchase
	else
		cout << "Select another drink or input 0 to quit and get the change."<< endl; // Selection prompt for the later purchase

	cin >> drink_num;

	//Input Validation for drink selection
	while (drink_num > TYPES || drink_num < 0)
	{
		cout << "Error. Invalid Input." << endl << endl;
		show_Drink(Drink);
		cout << "Select a drink or input 0 to quit." << endl;
		cin >> drink_num;
	}


	if (drink_num == 0)
	{
		//Exit Prompt
		cout << "Thank you for using. Have a nice day." << endl;
		if (change > 0)
			cout << "Please collect your change of $" << change << endl;
		return drink_num;
	}
	else
	{
		//Input Validation for availability of the drink
		while (Drink[drink_num - 1].amount <= 0)
		{
			cout << endl << "Sorry!" << Drink[drink_num - 1].name << " has sold out." << endl;
			show_Drink(Drink);
			cout << "Select a drink or input 0 to quit.";
			cin >> drink_num;
			runtime++;
		}

		//Payment process
		pay(Drink,payment,drink_num);
		runtime++;
		Drink[drink_num - 1].amount--;
	}
	return 1;
}

//Function that directs the payment process
void pay(Machine Drink[TYPES], MoneyMGN* payment, int drink_num)
{
	//Show the money due and money in change
	cout << "Please pay $" << Drink[drink_num - 1].cost << " for the drink." << endl;
	if (payment -> change > 0)
		cout << endl << "You have $" << payment->change << " in change." << endl;

	cin >> payment->input;

	//Input validation for the money input
	while (payment->input < 0 || payment->input > payment->greatest)
	{
		if (payment -> input < 0)
			cout << "Error. Money amount cannot be negative." << endl;
		if (payment -> input > payment->greatest)
			cout << "Error. Money amount cannot be greater than $" << payment->greatest << endl;
		cout << "Please pay $" << Drink[drink_num - 1].cost << " for the drink." << endl;
		cin >> payment->input;
	}

	payment->due = Drink[drink_num - 1].cost;
	bool nonstop; //Flag for sufficient payment
	payment->paid = payment -> input + payment ->change;
	do
	{
		nonstop = 0;

		cout << "You paid $" << payment->paid << endl;

		if (payment->paid == payment->due)
		{
			cout << "You have paid for the drink. Thank you!" << endl;
			payment->change = payment->paid - payment->due;
		}
		if (payment->paid < payment->due)
		{
			payment->due -= payment->paid;
			cout << "You still owe $" << payment->due << endl;
			cout << "Please pay $" << payment->due << endl;
			cin >> payment->paid;
			nonstop = 1;
		}
		else if (payment->paid > payment->due)
		{
			payment->change = payment->paid - payment->due;
			cout << "You have paid for the drink. Thank you!" << endl;
			cout << "You still have $" << payment->change << endl;
		}

	} while (nonstop);

	cout << endl;
	return;
}


