#pragma once

// Class representing a house with circle-wise rooms.
class House
{	
private:

	// Inner class representing a room with a light bulb inside.
	class Room
	{
	public:
		Room();
		bool bulb;
		Room *next = nullptr;
	};

	Room *current = nullptr;
	Room *start = nullptr;
	int roomNumber = 0;
	
public:

	// Constructor of a house with specific room number.
	House(int roomNumber);

	// Destructor.
	~House();

	// Checks if the bulb in the current room is turned on.
	bool isBulbTurnedOn() const;

	// Checks if the bulb in the start room is turned on.
	bool isBulbTurnedOnStart() const;

	// Turns on the bulb in the current room.
	void turnOnBulb();

	// Turns off the bulb in the current room.
	void turnOffBulb();

	// Moves the current room position to the next room.
	void moveForward();

	// Gets the number of rooms in the house.
	int getRoomNumber() const;
};