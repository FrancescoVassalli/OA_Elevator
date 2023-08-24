#ifndef ELEVATOR_H_
#define ELEVATOR_H_
#include <string>

class Elevator{

private: 
	std::string _path;
	size_t _time;

public:
	// Construct an Elevator object with the floors it needs to visit
	Elevator(unsigned start, std::unique_ptr<std::vector<unsigned>> visits);

	// Get output set of visited floors
	std::string getVisitedFloors() const;

	// Get path time
	size_t getPathTime() const ;
	
};

#endif
