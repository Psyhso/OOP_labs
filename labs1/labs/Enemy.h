#include "Human.h"

#pragma once

class Enemy : public Human {
public:
	void moving() override;
	void attack() override;
};