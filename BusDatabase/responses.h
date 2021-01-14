#pragma once

#include <iostream>
#include <vector>
#include <map>

struct BusesForStopResponse
{
	std::vector<std::string> buses;
};

std::ostream& operator<< (std::ostream& out, const BusesForStopResponse& obj);

struct StopsForBusResponse 
{
	std::string bus;
	std::vector<std::pair<std::string, std::vector<std::string>>> sfb;
};

std::ostream& operator<< (std::ostream& out, const StopsForBusResponse& obj);

struct AllBusesResponse 
{
	std::map<std::string, std::vector<std::string>> bfs;
};

std::ostream& operator<< (std::ostream& out, const AllBusesResponse& obj);