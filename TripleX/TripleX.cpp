#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

void PrintIntroduction(int LevelDifficulty) {

	cout << "You are a secret agent. Your mission, if you choose to accept it, is to break into a Level " << LevelDifficulty << " secure server room.\n" << endl;
	cout << "You need to enter the correct code to continue..." << endl;

}

bool PlayGame(int LevelDifficulty) {
	
	PrintIntroduction (LevelDifficulty);

	// Start of the game of a secret agent entering 3 digit codes to enter a new level
	bool bLevelComplete = false;
	const int CodeA {(rand() % LevelDifficulty) + LevelDifficulty};
	const int CodeB {(rand() % LevelDifficulty) + LevelDifficulty};
	const int CodeC {(rand() % LevelDifficulty) + LevelDifficulty};

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;
	
	cout << "\nThere are 3 numbers in the code:" << endl;
	cout << "\nSum: " << CodeSum << endl;
	cout << "\nProduct: " << CodeProduct << endl;

	int GuessA {}, GuessB {}, GuessC {};

	cout << "\nPlease enter your 3 number code:\n";
	
	// Stores Player Guess
	cin >> GuessA >> GuessB >> GuessC;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	cout << "\nYou have entered: " << GuessA << " " << GuessB << " " << GuessC << endl;
	cout << "\nSum: " << GuessSum << endl;;
	cout << "\nProduct: " << GuessProduct << endl;

	// Check to see if player guess is correct
	if (CodeSum == GuessSum && CodeProduct == GuessProduct) 
	{
		cout << "\nAwesome Work! You have completed level " << LevelDifficulty << "\n" << endl;
		bLevelComplete = true;
	}
	else 
	{
		cout << "\nSorry, that was the incorrect code. You will need to retry level " << LevelDifficulty << " again.\n" << endl;
	}

	return bLevelComplete;
}

int main() {
	
	srand (time (NULL));

	cout << "WELCOME TO TRIPLEX\n" << endl;

	int LevelDifficulty = 1;
	const int MaxDifficulty = 10;

	while (LevelDifficulty <= MaxDifficulty) 
	{
		bool bLevelComplete = PlayGame (LevelDifficulty);
		cin.clear();
		cin.ignore();

		if (bLevelComplete) 
		{
			++LevelDifficulty;
		}
		

	}

	cout << "Congratulations! You win!" << endl;

	return 0;
}