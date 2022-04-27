#pragma once
#include <exception>
class BowlingException : public std::exception
{
	const char * what () const throw ()
    {
    	return "Bowling Exception";
    }
};

const int MAX_ROUNDS = 10;
class BowlingGame
{
	public:
	void roll(int p) {
		if (p > pins) {
			throw new BowlingException();
		}
		if (round > MAX_ROUNDS) {
			if (!(firstBonus||secondBonus)) {
				throw new BowlingException();
			}
			int k=0;
			if(firstBonus) k++;
			if(secondBonus) k++;
			score += k*p;
			addBonus(0);
			pins -= p;
			if(p==10) {
				pins = 10;
			}
		} else {
			addPoints(p);
			pins -= p;
			num++;
			if (p == 10) {
				addBonus(2);
			} else if (pins == 0) {
				addBonus(1);
			} else {
				addBonus(0);
			}
			if(!(num%2)||p==10) {
				num = 0;
				round++;
				pins = 10;
			}
		}
	}
	int getScore() {
		return score;
	}
	private:
	void addPoints(int p) {
		int k=1;
		if (firstBonus) k++;
		if (secondBonus) k++;
		score += p*k;
	}
	void addBonus(int b) {
		secondBonus = firstBonus - 1;
		if (secondBonus < 0) secondBonus = 0;
		firstBonus = b;
	}
	int num = 0;
	int firstBonus = 0;
	int secondBonus = 0;
	int score = 0;
	int pins = 10;
	int round = 1;
};

