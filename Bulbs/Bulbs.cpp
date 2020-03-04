#include "House.h"

#include <iostream>

// Counts rooms in a house using light bulbs in them. 
int countRooms(House &house)
{	
	if (!house.isBulbTurnedOn())
	{
		house.turnOnBulb();
	}

	auto roomCounter = 0;

	while (true)
	{
		house.moveForward();
		++roomCounter;

		if (house.isBulbTurnedOn())
		{
			house.turnOffBulb();
			
			if (!house.isBulbTurnedOnStart())
			{
				return roomCounter;
			}
		}
	}
}

int main()
{
	std::cout << "Enter the number of rooms to create: ";
	auto roomNumber = 0;
	std::cin >> roomNumber;
	auto house = House(roomNumber);
	std::cout << "Algorithm result: " << countRooms(house);
	return 0;
}