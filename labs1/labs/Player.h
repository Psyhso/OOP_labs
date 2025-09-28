#include "Human.h"
#pragma once

class Player : public Human {
private:
	double experience;
public:
	void moving() override;
	void attack() override;
};
