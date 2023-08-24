#include <string>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "Elevator.hpp"
#include <iostream>

// pulled from web
template<typename T>
T abs_diff(T a, T b) {
  return a > b ? a - b : b - a;
}

Elevator::Elevator(unsigned start, std::unique_ptr<std::vector<unsigned>> visits)
{	
	std::cout<<"Starting: "<<start<<" with "<<visits->size()<<" visits\n";
	// Here the hueristic is to sort the vector then find the floor closest to the start
	// pick a direction then hit all the floors in that direction before reversing direction
	// should feel similar to how an actually elevator works 
	std::sort(visits->begin(),visits->end());
	std::vector<unsigned> ordered_visits(visits->size());	
	// bool to track if the elevator will move up or down;
	bool moveUp = false;
	// marker for which floor we go to first
	size_t count =0;
	// previous floor is recorded to devide the direction we start going in
	unsigned last_floor=0;
	// iterate over the sorted floors to find the two closest to the start
	for(auto floor : *visits)
	{
		// once we pass the start we need to check which is closer
		if(floor>=start)
		{
			// if moveUp is true then the floor is either the start or above
			moveUp = abs_diff(start,floor) < abs_diff(start,last_floor);		
			std::cout<<"Moving up?"<<moveUp<<'\n';
			break;
		}
		last_floor = floor;
		count++;
	}
	std::cout<<"count: "<<count<<'\n';
	// now that we have picked a starting place and a direction make an ordered collection of the floors we will visit
	if(moveUp)
	{
		std::copy(visits->begin()+count,visits->end(),ordered_visits.begin());
		std::copy(visits->rbegin()+(visits->size()-count),visits->rend(),ordered_visits.begin()+(visits->size()-count));
	}
	else
	{
		std::copy(visits->rbegin()+(visits->size()-count),visits->rend(),ordered_visits.begin());
		std::copy(visits->begin()+count,visits->end(),ordered_visits.begin()+count);
	}
	// buffer to print the order the floors were visited
	std::stringstream ss;
	ss<<start<<',';
	// record the previous floor 
	unsigned last = start;
	// sum how many floors the elevator moved 
	size_t total_floors(0);
	// now visit the floors
	for(auto floor : ordered_visits)
	{
		ss<<floor<<',';
		total_floors+=abs_diff(last,floor);
		last = floor;
	}
	_path = ss.str();
	_time = total_floors*10;
}


std::string Elevator::getVisitedFloors() const
{
	return _path;
}

size_t Elevator::getPathTime() const
{
	return _time;
}
