//HW #10
//Car FuelGauge and Odometer
//MAX HOLD of fuel tank is 15 gallons. The lagest value for the odometer is 999,999 miles. Only interger mileage and interger gallons is accepted.
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_FUEL = 15; // MAX TANK HOLD



class FuelGauge
{
private:
	int fuel;
public:
	FuelGauge();
	FuelGauge(int);
	int getFuel() const 
	{ 
		cout << "There are currently " << fuel << " gallons of fuel in the tank." << endl;

		return fuel; 
	}
	int getTotal() const { return fuel; }
	void setFuel (int);
	void addFuel(int);
	void burnFuel();
	friend class Odometer;
};

//Default Constructor if no value is passed
FuelGauge::FuelGauge()
{
	fuel = MAX_FUEL;
}

//Constructor for passed in value
FuelGauge::FuelGauge(int gas)
{
	setFuel(gas);
}

//Function settor that regulates the allowed input
void FuelGauge::setFuel(int gas)
{
	while (gas > MAX_FUEL || gas < 0)
	{
		if (gas > MAX_FUEL) 
		{
			cout << "The Fuel input has exceeded the " << MAX_FUEL <<" Gallon maximum capacity of the tank." << endl;
		}
		else if (gas < 0)
		{
			cout << "Fuel level must not be negative." << endl;
		}

		cout << "The maximum allowance, " << MAX_FUEL << " gallons of fuel, is filled instead." << endl;
		gas = MAX_FUEL;
		
	};

	fuel = gas;

}

//Function for Putting more gas in the tank
void FuelGauge::addFuel(int fill) 
{
	int added = this->fuel + fill;
	setFuel(added);
}

//Function for fuel decrement
void FuelGauge::burnFuel()
{
	this->fuel--;
}



class Odometer
{
private:
	int mileage;
	const int MAX_MILE = 999999;
public:
	Odometer();
	
	int getMeter () const
	{
		cout << "The current mileage is " << mileage << " miles." << endl;
		return mileage;
	}
	void setMile(int);
	void addMile(FuelGauge*);
};

//Default Constructor, sets mileage = 0
Odometer::Odometer()
{
	mileage = 0;
}

//Put miles input to mileage
void Odometer::setMile(int mile)
{
	while (mile < 0)
	{
		cout << "The mileage has to be positive" << endl;
		cout << "Enter new mileage" << endl;
		cin >> mile;
	};
	mileage = mile;

}

//Increment of miileage and deduct 1 gallon for every 24 miles
void Odometer::addMile(FuelGauge* fuel)
{
	mileage++;
	if (mileage > MAX_MILE)
	{
		cout << "Current mileage has excedded the max count of " << MAX_MILE << endl;
		cout << "Thus the odometer will be reset to 0." << endl;
		mileage = 0;
	}
	else if ((mileage % 24) == 0) 
	{
		fuel->fuel--;
	}
}


class Car
{
private:
	FuelGauge gas;
	Odometer distance;
public:
	Car(int,int);

};


Car::Car(int fuel, int dist)
{
	//Check to ensure positive distance entered
	while (dist < 0)
	{
		cout << "The expected distance must not be negative." << endl;
		cout << "Enter the new expected distance: ";
		cin >> dist;
	}

	int distance_covered = 0;
	int remain_fuel = 0;
	bool cont = false; // Flag for continuation of driving
	gas.setFuel(fuel);
	
	do
	{
		//Driving simulation
		for (int i = 0; (i < dist) && (gas.getFuel() >0); i++)
		{
			distance.addMile(&gas);
			remain_fuel = gas.getTotal();
			distance_covered = distance.getMeter();
			cout << endl;
		}
		cout << "The total distance covered was " << distance_covered << " miles." << endl;
		cout << "The remaining fuel is " << remain_fuel << " gallons." << endl;

		//Ask for continuation
		cout << endl << "Do you want to keep going?" << endl;
		cout << "Yes: 1; No: 0" << endl;
		cin >> cont;
		if (cont)
		{
			//ADD FUEL
			int fill = 0;
			cout << "Input more fuel to the tank." << endl;
			cout << "Input 0 if no fuel needs to fill." << endl;
			cin >> fill;
			while (fill < 0)
			{
				cout << "Invalid value." << endl;
				cout << "Input more fuel to the tank." << endl;
				cout << "Input 0 if no fuel needs to fill." << endl;
				cin >> fill;
			}
			gas.addFuel(fill);
			//NeW EXPECTED distance
			cout << "Input the distance expected to travel." << endl;
			cin >> dist;
		}
	} while (cont);
	
	
}

int main()
{
	int fuel_level = 0;
	int distance_expected = 0;
	cout << "Welcome to driving simulator!" << endl;
	cout << "The maximum tank capacity is " << MAX_FUEL << " gallons." << endl;
	cout << "Please enter the fuel level and the distance expected to drive." << endl;


	cout << "Fuel level: ";
	cin >> fuel_level;
	cout << "Distance: ";
	cin >> distance_expected;
	Car(fuel_level, distance_expected);

	system("pause");
	return 0;
}