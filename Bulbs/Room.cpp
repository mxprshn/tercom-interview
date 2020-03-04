#include "House.h"

#include <functional>
#include <random>

House::Room::Room()
{
	static auto gen = std::bind(std::uniform_int_distribution<>(0, 1), std::default_random_engine());
	bulb = gen();
}