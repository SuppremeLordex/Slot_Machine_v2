#pragma once

class Credit {
private:
	unsigned int _credits;
public:
	Credit(unsigned int credit);
	void setCredit(unsigned int credit);
	unsigned int getCredit();
	~Credit();
};