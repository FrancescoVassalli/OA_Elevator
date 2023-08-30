Compile with 
clang++ -std=c++17 test.cpp Elevator.cpp -o francesco

Then run with 
./francesco 

Inputs are prompted by the program like 
elevator start=
5
floor=
5,10

Start should be a single positive int
Floor is a comma deliminated list of postive ints


Improvement: To make a more efficient elevator I should implement the floors as a std::list which is doubly linked. This will allow me to always move in the direction of the closest floor and reverse direction easily. I can remove floors from the list as I visit and track the total time. 
