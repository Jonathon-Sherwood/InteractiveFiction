/*
	Jonathon Sherwood
	10/30/2020
	Interactive Fiction: Practice with Functions
*/

#include <iostream> //Used to display messages to the console

using namespace std; //Global declaration to shorten many common commands throughout the code

int Health(int currentHealth, int damage); //Used to hold the players health and accept damage taken
char Story(string story); //Adjustable function for different story elements
void Scenario1(int currentHealth); //Holds all functions for the first scenario in the story
void Scenario2(int currentHealth); //Holds all functions for the second scenario in the story


int main() //Starting function containing our code found in every C++ file 
{
	int currentHealth = 100; //Starts the players health at 100
	Scenario1(currentHealth); //Begins the first scenario and sets the players health to sthe starting amount
	return 0;
}

void Scenario1(int currentHealth) //Tells the first part of the story
{
	cout << "You are a brave adventurer who has just entered a forest with " << currentHealth << " health.\n";
	char response = Story("All of a sudden, you are surrounded by bees. They are about to catch you! What do you do??\nA: Swat at them.\nB: Outrun them.\n");

	if (response == 'a') //Deals damage to the player if they choose A
	{
		currentHealth = Health(currentHealth, 50);
		cout << "You cannot fight bees. You have taken 50 health and are now down to " << currentHealth << " health left.";
	}
	if (response == 'b') //Deals damage to the player if they choose B
	{
		currentHealth = Health(currentHealth, 30);
		cout << "You cannot outrun bees. You have taken 30 health and are now down to " << currentHealth << " health left.";
	}

	//Passes the final amount of health from scenario 1 into scenario 2 and starts it
	Scenario2(currentHealth);
}

void Scenario2(int currentHealth) //Tells the second part of the story
{
	cout << "\n\nBarely surviving the bees, you see a raging volcano.\n";
	char response = Story("What do you do?\nA: Investigate the Volcano.\nB: Go home, the bees already hurt.\n");

	if (response == 'a') //Kills the player if they choose option A
	{
		currentHealth = Health(currentHealth, 100);
		cout << "\nThe volcano is a volcano. You melt, taking 100 damage.";
	}
	if (response == 'b') //Ends the game successfully if the player chooses option B
	{
		cout << "\nYou go home and enjoy a peaceful life. Adventuring wasn't fun anyway.\n\n\n";
	}

	if (currentHealth < 0) //Displays to the player they died at 0 health
	{
		cout << "\n\nYou are dead. The end.\n\n\n";
	}
}

/// <summary>
/// Returns player's current health after applying damage taken.
/// </summary>
/// <param name="damage"></param>
/// <returns></returns>
int Health(int currentHealth, int damage) 
{
	return currentHealth - damage; //Subtracts health taken in from damage taken in
}


/// <summary>
/// Type in story requiring choice A or B here. Awaits user input.
/// </summary>
/// <param name="story"></param>
/// <returns></returns>
char Story(string story) 
{
	char response; //Creates a variable for the player's response
	do 
	{
		cout << story; //Displays the story that the function is given
		cin >> response; //Awaits player response for only a or b
	} while (response != 'a' && response != 'b'); //Loops until proper input
	return response; //Returns the response the player gives from the function
}
