#pragma once
#include "stdafx.h"
#include "FBullCowGame.h"
#include <map>
#include <stdlib.h>     /* srand, rand */
using FString = std::string;
using int32 = int;


/**method is map to tries based on word length** length=6 maxtries = 5 etc;**/
int32 FBullCowGame::GetMaxTries() const{
	TMap<int32, int32> MaxTriesBasedOnWordLength{ {3,3},{4,4},{5,5},{6,6},{7,7} };
	return MaxTriesBasedOnWordLength[MyHiddenWord.length()];
}

int32 FBullCowGame::GetCurrentTrys() const{return MyCurrentTry;}

int32 FBullCowGame::GetHiddenWordLength() const{return MyHiddenWord.length();}


FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	
	const FString hiddenWord[8]{ "planets","earth","jupiter","saturn","mars","venus","sun","pluto" }; //array of size 8

/* generate secret number between 0 and 7: */
	RandomWordNum = rand() % 7;
	
	MyHiddenWord = hiddenWord[RandomWordNum];//puts random number in hiddenword to select a new word
	bGameIsWon = false;
	MyCurrentTry = 1;

	return;
}




EWordStatus FBullCowGame::CheckGuessValidity(FString Guess)
{
	//if the guees is an isogram 
	if (!IsIsogram(Guess))
	{
		return EWordStatus::NOT_Isogram;
	}
		// if the guess length is wrong
	else if (LengthCheck(Guess)==false)
	{
		return EWordStatus::Wrong_Length;

	}
	else
		return EWordStatus::OK;

}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//increment the turn number
	MyCurrentTry++;

	FBullCowCount Bullcowcount;

	//loop through all letters in the guess
	for (int32 i = 0; i < MyHiddenWord.length(); i++)
	{

		for (int32 j = i; j < MyHiddenWord.length(); j++)
		{
			if (MyHiddenWord[i] == Guess[j]) //if match then
			{
				if (i == j)//and char is in the same spot
					Bullcowcount.Bulls++;  //TODO: counts wrong
				
				else
					Bullcowcount.Cows++; //must be a cow
			}
		}

	}
	/**CHECK FOR A WINNER**/
	if (Bullcowcount.Bulls == GetHiddenWordLength())
		bGameIsWon = true;
	else
		bGameIsWon = false;

	//compare letters against the hidden word


	return Bullcowcount;
}

bool FBullCowGame::LengthCheck(FString Guess)
{
	if (Guess.length() != GetHiddenWordLength())
		return false;
	else
		return true;
}

bool FBullCowGame::IsGameWon() const
{
	return bGameIsWon;
}


bool FBullCowGame::IsIsogram(FString Guess) const
{
	TMap<char, bool> map;

	if (Guess.length() <= 1) { return true; }

	for(auto Letter : Guess) //auto ; complier makes the type of letter for us
	{
		if (map[Letter])
			return false;
		else
			map[Letter] = true;
	}



	return true;
}
