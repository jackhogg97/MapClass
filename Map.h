#pragma once

#include <iostream>

#define SPACE "    ";

template<typename K, typename V>
class map
{
private:
	V* data_value = NULL; //Array of values in map
	K* data_key = NULL; //Array of keys in map
	int map_length = 0; //Size of the array

	int find(K key); //Finds where position of key and returns corrosponding integer

	

public:
	void insert(K key, V value); //Inserts key and value at the end of map if key already excists value will override
	void remove(); //Removes last element in map
	void print(); //Prints full table
	void print(K key); //Prints key and value pair
	int length(); //Returns size of map
	bool is_empty(); //Returns boolean value whether map is empty or not
	void clear();

	map(); //Constructor
};