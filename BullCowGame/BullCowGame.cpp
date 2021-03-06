// BullCowGame.cpp : Defines the entry point for the console application.
//
/********TODO FIX CURRENT TRYS AND MAX TRIES=========REdefined both that was the failure 1/4/18*****/
#include "stdafx.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();

void PlayGame();
FText GetGuess();
bool replay();
void PrintGameSummary();
FBullCowGame BCGame;//instantiate a new game


int main()
{  	
	do 
	{
		PrintIntro();
		PlayGame();

	} 

	while (replay() == true);


	return 0;
}

void PrintIntro()
{
	//constexpr int32 WORLD_LENGTH = 5;
	BCGame.Reset();

	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << std::endl;
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << "" << " letter isogram I'm Thinking of?\n";
	return;
}



void PlayGame()
{
	

		std::cout << "MAX:"<<BCGame.GetMaxTries()<<" current:"<< BCGame.GetCurrentTrys()<< std::endl;
		while (!BCGame.IsGameWon()&& BCGame.GetCurrentTrys()<=BCGame.GetMaxTries())
		{
			FText Guess = GetGuess();
			//show it back to the user
			FBullCowCount BullCowcount = BCGame.SubmitGuess(Guess);

			std::cout << "Bulls =" << BullCowcount.Bulls;
			std::cout << ". Cows=" << BullCowcount.Cows << "\n\n";
		}
		PrintGameSummary();
		return;
	
}

FText GetGuess()
{
	/***get guess from the user**/
	FText Guess = " ";
	int32 trialnum=BCGame.GetCurrentTrys();

	
		std::cout <<"Try:# "<<trialnum<<" of"<<BCGame.GetMaxTries()<<"\n"<< " Enter your Guess\n";
		//cin >> Guess;
		std::getline(std::cin, Guess);

		//if the guess isn't all lowercase=> make lowercase
		for (int i = 0; i < Guess.length(); i++)
		{
			Guess[i] = tolower(Guess[i]);
		}
	/*****PASS ON LOWERCASE GUESS TO CHECK****/

		//check input return feed back
		EWordStatus Status = EWordStatus::invalid_input;
		do {
			EWordStatus Status = BCGame.CheckGuessValidity(Guess);

			switch (Status)
			{
			case EWordStatus::NOT_Isogram:
				std::cout << "Please enter a word without repeating letters" << "\n";
				break;
			case EWordStatus::Wrong_Length:
				std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word\n";
				break;
			
			default:
				break;
			}
		} while (Status != EWordStatus::invalid_input);
		

	return Guess;
}

bool replay()
{
	FText ans = "";
	std::cout << "Do you wanna play again?";
	 std::getline(std::cin, ans);
	 if (ans[0] == 'y' || ans[0] == 'Y') //check first char in FText ans
		 return true;

	return false;
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "WELL DONE - YOU WIN!\n";
	}
	else
	{
		std::cout << "Better luck next time!\n";
	}
}
																																		


