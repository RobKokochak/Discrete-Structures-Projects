#include <iostream>
using namespace std;
#include <string>
#include <stdio.h>

int returnValue(string);

int main()
{
	srand(time(NULL));

	int card1Val = 0, card2Val = 0, card3Val = 0, aceVal1 = 1, aceVal2 = 11;
	int hand;
	float needVal, odds;

	string cards[13] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

	int card1 = rand() % 13;
	int card2 = rand() % 13;

	while (card2 == card1)
	{
		card2 = rand() % 13; //to avoid repetition
	}

	if (cards[card1] == "A")
	{
		card2Val = returnValue(cards[card2]);

		if (card2Val <= 10)
			card1Val = aceVal2;
		else
			card1Val = aceVal1;
	}
	else if (cards[card2] == "A")
	{
		card1Val = returnValue(cards[card1]);

		if (card1Val <= 10)
			card2Val = aceVal2;
		else
			card2Val = aceVal1;
	}
	else
	{
		card1Val = returnValue(cards[card1]);
		card2Val = returnValue(cards[card2]);
	}

	cout << "Card 1: " << cards[card1] << endl;
	cout << "Card 2: " << cards[card2] << endl;
	hand = card1Val + card2Val;
	cout << "Value of your hand: " << hand << endl;

	if (hand == 21)
		cout << "You have 21!";
	else
	{
		needVal = 21 - hand;
		cout << "You need to draw a card with a value of " << needVal << " or less to avoid a bust.\n";

		if (needVal < 10)
		{
			odds = needVal/13;
			cout << "The odds of drawing a card with a beneficial value of " << needVal << " or less are " 
				<< needVal << "/13 or " << odds * 100 << "%\n";
			cout << "The odds of drawing a card with a detrimental value of " << needVal + 1 << " or more are " 
				<< 13 - needVal << "/13 or " << (1-odds) * 100 << "%\n";

			if ((odds * 100) < 40)
				cout << "Drawing another card would be risky.\n";
			else if ((odds * 100) > 40 && (odds * 100) < 60)
				cout << "It's about a 50/50 chance of drawing another benefical card.\n";
			else 
				cout << "There's a good chance drawing another card would be beneficial.\n";


		}
		else
		{
			odds = 100;
			cout << "The odds of drawing a card with a value of " << needVal << " or less are " << odds << "%\n";
			cout << "The odds of drawing a card with a detrimental value are 0/13 or 0%\n";
			cout << "You should definitely draw another card.\n";
		}

		char choice;
		cout << "Do you want to draw another card (y/n): ";
		cin >> choice;
		
		while (choice != 'y' && choice != 'n')
		{
			cout << "Please enter a valid choice: ";
			cin >> choice;
		}
		if (choice == 'y')
		{
			int card3 = rand() % 13;
			while (card3 == card2 || card3 == card1)
				card3 = rand() % 13;

			if (cards[card3] == "A")
			{
				if ((hand + aceVal2) > 21)
					card3Val = aceVal1;
				else
					card3Val = aceVal2;
			}
			else
			{
				card3Val = returnValue(cards[card3]);
			}
			cout << "Card 3: " << cards[card3] << endl;
			hand += card3Val;
			cout << "Value of your hand: " << hand << endl;
			if (hand == 21)
				cout << "You have 21!";
			else if (hand > 21)
				cout << "That's a bust!";
			else if (hand < 21 && hand > 14)
				cout << "That's not bad!";
			else
				cout << "Unlucky!";
		}
	}
}

int returnValue(string card)
{
	int value;
	if (card == "2")
		value = 2;
	if (card == "3")
		value = 3;
	if (card == "4")
		value = 4;
	if (card == "5")
		value = 5;
	if (card == "6")
		value = 6;
	if (card == "7")
		value = 7;
	if (card == "8")
		value = 8;
	if (card == "9")
		value = 9;
	if (card == "10")
		value = 10;
	if (card == "J")
		value = 10;
	if (card == "Q")
		value = 10;
	if (card == "K")
		value = 10;
	return value;
};
