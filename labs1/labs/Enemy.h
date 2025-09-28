#pragma once
#include "Human.h"



class Enemy : public Human {
public:
	void moving();
	void attack();
};