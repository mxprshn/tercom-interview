#include "House.h"

#include <stdexcept>

House::House(int roomNumber)
{
	if (roomNumber <= 0)
	{
		throw std::invalid_argument("Room number should be a positive integer.");
	}

	const auto firstRoom = new Room();
	
	current = firstRoom;
	start = firstRoom;

	auto lastRoom = firstRoom;
	
	for(auto i = 0; i < roomNumber - 1; ++i)
	{
		lastRoom->next = new Room();
		lastRoom = lastRoom->next;
	}

	lastRoom->next = firstRoom;
	House::roomNumber = roomNumber;
}

int House::getRoomNumber() const
{
	return roomNumber;
}

bool House::isBulbTurnedOn() const
{
	return current->bulb;
}

bool House::isBulbTurnedOnStart() const
{
	return start->bulb;
}

void House::turnOnBulb()
{
	current->bulb = true;
}

void House::turnOffBulb()
{
	current->bulb = false;
}

void House::moveForward()
{
	current = current->next;	
}

House::~House()
{
	while (getRoomNumber() != 0)
	{
		const auto temp = current;
		current = current->next;
		delete temp;
		--roomNumber;
	}

	current = nullptr;
}