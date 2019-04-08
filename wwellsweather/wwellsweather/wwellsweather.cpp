// wwellsweather.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

struct monthStat {
	double rainFall;
	double highTemp;
	double lowTemp;
	double avgTemp;
};

int main()
{
	double Jan = 0, Feb = 0, Mar = 0, Apr = 0, May = 0, Jun = 0, Jul = 0,
		Aug = 0, Sept = 0, Oct = 0, Nov = 0, Dec = 0;

	const int SIZE = 12;
	int x, y;
	double totalRainfall = 0, averageRainfall = 0, totalAverageTemp = 0, averageTemp = 0;

	// Arrays for High Temp and Low Temp
	double lows[12], highs[12];
	double highest, lowest;

	monthStat months[SIZE] = { Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sept,
		Oct, Nov, Dec };

	for (x = 0; x < SIZE; ++x) {
		cout << "Enter the rainfall amount for month " << (x + 1) << ": ";
		cin >> months[x].rainFall;

		// In Validation
		while (months[x].rainFall < 0) {
			cout << "Cannot have a negative rainfall amount for a certain month.\n";
			cout << "Enter the rainfall amount for month " << (x + 1) << ": ";
			cin >> months[x].rainFall;
		}

		// Total for Rainfall
		totalRainfall += months[x].rainFall;

		cout << "\nEnter the highest temperature for month " << (x + 1) << ": ";
		cin >> months[x].highTemp;

		// In Validation
		while (months[x].highTemp < (-100) || months[x].highTemp > 140) {
			cout << "\nYou have entered an invalid temperature, (-100 & 140 F).";
			cout << "\nEnter the highest temperature for month " << (x + 1) << ": ";
			cin >> months[x].highTemp;
		}
		highs[x] = months[x].highTemp;

		cout << "\nEnter the lowest temperature for month " << (x + 1) << ": ";
		cin >> months[x].lowTemp;

		// In Validation
		while (months[x].lowTemp < (-100) || months[x].lowTemp > 140) {
			cout << "\nYou have entered an invalid temperature, (-100 & 140 f).";
			cout << "\nEnter the lowest temperature for month " << (x + 1) << ": ";
			cin >> months[x].lowTemp;
		}
		lows[x] = months[x].lowTemp;

		months[x].avgTemp = (months[x].highTemp + months[x].lowTemp) / 2;

		// Total for average temps
		totalAverageTemp += months[x].avgTemp;

		cout << endl;
	}

	// Total Rainfall for year
	cout << "\n---The total rainfall for the year was " << totalRainfall << " inches.";

	// Average Rainfall for year
	averageRainfall = totalRainfall / SIZE;
	cout << "\n---The avergage monthly rainfall for the year is " << averageRainfall << " inches.";

	// Average of all temperatures
	averageTemp = (totalAverageTemp / SIZE);
	cout << "\n---The average temperature for the year is " << averageTemp << " degrees.";


	// Highest temp for the year
	highest = highs[0];
	for (x = 1; x < SIZE; x++) {
		if (highs[x] > highest)
			highest = highs[x];
		y = x;
	}
	cout << "\n---Month " << x << " had the highest temperature which was " <<
		highest << " degrees." << endl;



	// Lowest temp of the year
	lowest = lows[0];
	for (x = 1; x < SIZE; x++) {
		if (lows[x] < lowest)
			lowest = lows[x];
		y = x;
	}
	cout << "---Month " << y << " had the lowest temperature which was " <<
		lowest << " degrees." << endl;

	system("pause");

	return 0;

}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
