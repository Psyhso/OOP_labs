#pragma once
#include "Human.h"


class Player : public Human {
private:
	double experience;
public:
	void moving();
	void attack();
};
