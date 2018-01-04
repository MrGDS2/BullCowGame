#pragma once
#include <string>
#define TMap std::map	

	using FString = std::string;
	using int32 = int;

// all variables intialized to zero
struct FBullCowCount
	{
		int32 Bulls = 0;
		int32 Cows = 0;
	};


enum class EWordStatus
{
	invalid_input,
	OK,
	NOT_Isogram,
	Wrong_Length,
	Not_Lowercase
};
class FBullCowGame {

public:
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTrys() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	bool IsIsogram(FString) const;

	void Reset();
  EWordStatus CheckGuessValidity(FString);

	//sumbit a guess
	FBullCowCount SubmitGuess(FString);
	bool LengthCheck(FString);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	int32 RandomWordNum;
	FString MyHiddenWord;
	bool bGameIsWon;


};