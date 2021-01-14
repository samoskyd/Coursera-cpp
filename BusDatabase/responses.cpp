#include "responses.h"
#include <vector>
#include <string>

std::ostream& operator<< (std::ostream& out, const BusesForStopResponse& obj) 
{
	if (obj.buses.empty()) 
	{
		out << "No stop" << std::endl;
	}
	else {
		for (const auto& i : obj.buses) 
		{
			out << i << " ";
		}
		out << std::endl;
	}
	return out;
}

std::ostream& operator<< (std::ostream& out, const StopsForBusResponse& obj) 
{
	if (obj.sfb.empty()) 
	{
		out << "No bus" << std::endl;
	}
	else 
  {
		for (const auto& item : obj.sfb) 
		{
			out << "Stop " << item.first << ":";
			if (item.second.size() == 1) 
			{
				out << " no interchange" << std::endl;
			}
			else 
			{
				for (const auto& i : item.second) 
				{
					if (i != obj.bus) 
					{
						out << " " << i;
					}
				}
				out << std::endl;
			}
		}
	}
	return out;
}

std::ostream& operator<< (std::ostream& out, const AllBusesResponse& obj) 
{
	if (obj.bfs.empty()) 
	{
		out << "No buses" << std::endl;
	}
	else 
	{
		for (const auto& item : obj.bfs) 
		{
			out << "Bus " << item.first << ":";
			for (const auto& i : item.second) 
			{
				out << " " << i;
			}
			out << std::endl;
		}
	}
	return out;
}