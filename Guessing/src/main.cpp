

#include <iostream>
#include <random>

int GenNumber()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distribution(1, 100);

	return distribution(gen);
}

enum class Modes
{
	None		= 0,
	Easy		= 10,
	Medium		= 5,
	Hard		= 3
};

int main()
{
	int modeSelect;
	int guessedNumber;
	int random_num = GenNumber();
	bool success = false;

	std::string currentMode;

	Modes mode = Modes::None;

	std::cout << "I'm thinking of a number between 1 and 100" << "\n\n";

	std::cout << "Select difficulty level:" << "\n";
	std::cout << " 1. Easy \t(10 Chances)" << "\n";
	std::cout << " 2. Medium \t(5 Chances)" << "\n";
	std::cout << " 3. Hard \t(3 Chances)" << "\n";

	std::cout << "\n: ";
	std::cin >> modeSelect;

	switch (modeSelect)
	{
	case 1:
		mode = Modes::Easy;
		currentMode = "Easy";

		break;
		
	case 2:
		mode = Modes::Medium;
		currentMode = "Medium";

		break; 

	case 3:
		mode = Modes::Hard;
		currentMode = "Hard";

		break;

	default:
		std::cout << "Invalid mode selected!" << "\n";
		break;
	}

	int currentAttempts = static_cast<int>(mode);

	std::cout << "\nMODE: " << currentMode << " - Attempts(" << currentAttempts << ")" << "\n";

	for (int i = 0; i < currentAttempts; i++)
	{
		std::cout << "\nEnter your Guess: ";
		std::cin >> guessedNumber;

		if (guessedNumber > 100)
		{
			std::cout << "\nCannot be over 100!" << "\n";
			std::cout << "Attempts Left: " << ((currentAttempts - i) - 1) << "\n";

			continue;
		}

		if (guessedNumber == random_num)
		{
			std::cout << "Congratulations! You guessed the correct number in " << (i + 1) << " attempts" << "\n";
			success = true;

			break;
		}
		else
		{
			std::string operation;

			if (random_num < guessedNumber)
			{
				operation = "less";
			}
			else
			{
				operation = "greater";
			}

			std::cout << "Incorrect! The number is " << operation << " than " << guessedNumber << "\n";
			std::cout << "Attempts Left: " << ((currentAttempts - i) - 1) << "\n";

			success = false;
		}
	}

	if (!success)
	{
		std::cout << "\nIt was " << random_num << "\n";
	}

	std::cin.get();
}
