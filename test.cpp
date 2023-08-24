#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <utility>
#include <memory>
#include <sstream>
#include "Elevator.hpp"
/* 
Assumptions
Assume there are postive integer valued floors starting at 1 and goint to INT_MAX
The floors are arranged in a sequence. 

User will enter integer data in response to start program commands
User will enter comma delimeted integers for the floor input, there will be at least one floor
*/ 

bool check_constraints(unsigned input)
{
	if(input<1)
	{
		std::cerr<<"User input: "<<input<< "which is not an allowed value\n";
		return false;
	}
	return true;
}

/*
	Takes a comma delimated string representing floors to visit and converts to a vector
	If constraints are violated returns null.
*/
std::unique_ptr<std::vector<unsigned>> create_visits_vector(std::string& visits_str)
{
	bool passedConstraints = true;
 	unsigned floor; // temp value to hold the floor
	std::string visit; // temp value to hold the floor before int conversion 
	std::stringstream ss(visits_str); //stream to parse
	// initialize a vector half the length of the input str
	std::unique_ptr<std::vector<unsigned>> visits(new std::vector<unsigned>());
	while(getline(ss,visit,',')&&passedConstraints)
	{
		std::cout<<"got visit: "<<visit<<'\n';
		floor = atoi(visit.c_str());
		if(!check_constraints(floor))
		{
			visits = nullptr;
			passedConstraints = false;
		}
		else
		{
			visits->push_back(floor);
		}
	}
	return visits;
}


int main(){
	// Get the starting position from the user
	unsigned start;
	std::string visits_str;
	std::cout<<"elevator start="<<std::endl;
	std::cin>>start;
	if(!check_constraints(start))
	{
		return 0;
	}
	std::cout<<"floor="<<std::endl;
	std::cin>>visits_str;
	Elevator elevator(start,create_visits_vector(visits_str));
	std::cout<<"output: "<<elevator.getPathTime()<<' '<<elevator.getVisitedFloors();
	return 0;
}
