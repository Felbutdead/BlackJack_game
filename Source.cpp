#include <iostream>
#include <array>
#include <random>
#include <ctime>

//Игры Blackjack (21 очко)

enum CardSuit {
	CARDSUIT_TREFU,
	CARDSUIT_BUBNU,
	CARDSUIT_CHERVU,
	CARDSUIT_PIKI,
	MAX_CARDSUIT,
};

enum CardRank
{
	RANK_2,
	RANK_3,
	RANK_4,
	RANK_5,
	RANK_6,
	RANK_7,
	RANK_8,
	RANK_9,
	RANK_10,
	RANK_VALET,
	RANK_DAMA,
	RANK_KOROL,
	RANK_TYZ,
	MAX_RANKS
};

struct Card {
	CardRank rank;
	CardSuit suit;
};

void printCard(const Card& card) {
	using namespace std;
	switch (card.rank) {
	case RANK_2: cout << "2";break;
	case RANK_3: cout << "3";break;
	case RANK_4: cout << "4";break;
	case RANK_5: cout << "5";break;
	case RANK_6: cout << "6";break;
	case RANK_7: cout << "7";break;
	case RANK_8: cout << "8";break;
	case RANK_9:cout << "9";break;
	case RANK_10: cout << "10";break;
	case RANK_VALET: cout << "v";break;
	case RANK_DAMA: cout << "d";break;
	case RANK_KOROL: cout << "k";break;
	case RANK_TYZ: cout << "t";break;
	}
	switch (card.suit) {
	case CARDSUIT_BUBNU: cout << "b";break;
	case CARDSUIT_TREFU: cout << "t";break;
	case CARDSUIT_CHERVU: cout << "ch";break;
	case CARDSUIT_PIKI: cout << "p";break;
	}
}

void printDesk(const std::array<Card, 52>& desk) {
	for (auto element : desk) {
		printCard(element);
		std::cout << " ";
	}
}

void swapCard(Card& card1, Card& card2) {
	std::swap(card1, card2);
}

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// Равномерно распределяем рандомное число в нашем диапазоне
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void shuffleDesk(std::array<Card,52> &desk) {
	for (int i = 0;i < 52;i++) {
		swapCard(desk[i], desk[getRandomNumber(0, 51)]);
	}
}

int getCardValue(const Card& card) {
	switch (card.rank) {
	case RANK_2: return 2;
	case RANK_3: return 3;
	case RANK_4: return 4;
	case RANK_5: return 5;
	case RANK_6: return 6;
	case RANK_7: return 7;
	case RANK_8: return 8;
	case RANK_9: return 9;
	case RANK_10: return 10;
	case RANK_VALET: return 10;
	case RANK_DAMA: return 10;
	case RANK_KOROL: return 10;
	case RANK_TYZ: return 11;
	}
	return 0;
}

bool playBlackjack(const std::array<Card,52> &desk) {
	const Card *cardPtr = &desk[0];
	int dillerResult, playerResult;

}

int main() {
	srand(static_cast<unsigned int>(time(0)));
	rand();

	std::array<Card, 52> arrCard;
	int card = 0;
	for (int i=0;i<MAX_CARDSUIT;i++)
		for (int j = 0;j < MAX_RANKS;j++) {
			arrCard[card].suit = static_cast<CardSuit>(i);
			arrCard[card].rank = static_cast<CardRank>(j);
			card++;
		}



	return 0;
}