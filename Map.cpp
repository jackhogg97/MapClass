#include "Map.h"

//Map constructer 
template <class K, class V>
map<K, V>::map()
{
	data_value = new V[map_length];
	data_key = new K[map_length];
	/*for (int i = 0; i < map_length; i++)
	{
		data_key[i] = 0;
		data_value[i] = 0;
	}*/
}

template <class K, class V>
void map<K, V>::insert(K key, V value)
{
	if (find(key) == NULL)
	{
		map_length++;
		data_value[map_length - 1] = value;
		data_key[map_length - 1] = key;

	}
	else
	{
		data_value[find(key)] = value;
	}
}

template <class K, class V>
void map<K, V>::remove()
{
	//Creates two new arrays and points pointers at new arrays
	K* newKeyArray = new K[map_length - 1];
	V* newValArray = new V[map_length - 1];
	std::copy(data_key, data_key + map_length - 1, newKeyArray);
	std::copy(data_value, data_value + map_length - 1, newValArray);
	data_value = newValArray;
	data_key = newKeyArray;
	newValArray = NULL;
	newKeyArray = NULL;
	delete[]newValArray;
	delete[]newKeyArray;
	map_length--;
}

template <class K, class V>
void map<K, V>::print()
{
	for (int i = 0; i < map_length; i++)
	{
		std::cout << data_key[i] << SPACE;
		std::cout << data_value[i] << std::endl;
	}
}

template <class K, class V>
void map<K, V>::print(K key)
{
	int pos = find(key);
	if (pos != NULL)
	{
		std::cout << key << SPACE;
		std::cout << data_value[pos] << std::endl;
	}
}

template <class K, class V>
int map<K, V>::length()
{
	return map_length;
}

template <class K, class V>
bool map<K, V>::is_empty()
{
	if (map_length == 0) return true;
	else return false;
}

template <class K, class V>
int map<K, V>::find(K key)
{
	for (int i = 0; i < map_length; i++)
	{
		if (data_key[i] == key) return i;
	}
	return NULL;
}

template <class K, class V>
void map<K, V>::clear()
{
	data_key = NULL;
	data_value = NULL;
	delete []data_key;
	delete []data_value;
	map_length = 0;
}


