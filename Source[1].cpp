// Project Three: Corner Grocer
// Maeve Winter 8/20/2023

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

// menu for user to pick from
void displayMenu() {
	cout << "Produce Sales Optimization" << endl;
	cout << "1. Search an item & display purchase frequency" << endl;
	cout << "2. Display purchase frequency of all items" << endl;
	cout << "3. Display a histogram for all items" << endl;
	cout << "4. End program" << endl;
}

void searchItem(map<string, int>& items) {
	string searchItem;
	cout << "Enter item name: ";
	cin >> searchItem;

	if (items.find(searchItem) != items.end()) {
		cout << searchItem << " " << items[searchItem] << endl;
	}
	else {
		cout << "None purchased today." << endl;
	}
}

void displayFrequency(map<string, int>& items) {
	for (const auto& item : items) {
		cout << item.first << " " << item.second << endl;
	}
}

void displayHistogram(map<string, int>& items) {
	for (const auto& item : items) {
		cout << item.first << " ";
		for (int i = 0; i < item.second; ++i) {
			cout << "^";
		}
		cout << endl;
	}
}

int main() {
	// open input file to read
	ifstream inputFile("CS210_Project_Three_Input_File.txt");
	if (!inputFile.is_open()) {
		cerr << "Unable to open input file." << endl;
		return 1;
	}

	map<string, int> items;
	string itemName;

	// add up number of each food purchased
	while (getline(inputFile, itemName)) {
		items[itemName]++;
	}

	inputFile.close();

	// open frequency.dat to back up accumulated data
	ofstream outputFile("frequency.dat");
	if (!outputFile.is_open()) {
		cerr << "Unable to open output file." << endl;
		return 1;
	}

	// writes to new file
	for (const auto& item : items) {
		outputFile << item.first << " " << item.second << endl;
	}

	outputFile.close();

	int choice;
	do {
		displayMenu();
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			searchItem(items);
			break;
		case 2:
			displayFrequency(items);
			break;
		case 3:
			displayHistogram(items);
			break;
		case 4:
			cout << "Exiting program." << endl;
			break;
		default:
			cout << "Invalid choice. Please select a valid option." << endl;
		}
	} while (choice != 4);
	return 0;
}