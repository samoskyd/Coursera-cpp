#include "query.h"

std::istream& operator>> (std::istream& in, Query& q) 
{
  std::string text;
	in >> text;
	if (text == "NEW_BUS") 
  {
		q.type = QueryType::NewBus;
		in >> q.bus;
		int stop_count = 0;
		in >> stop_count;
    q.stops.resize(stop_count);
		for (int i = 0; i < stop_count; i++)
    {
      std::string stop;
      in >> stop;
      q.stops[i] = stop;
    }
	}
	else if (text == "BUSES_FOR_STOP") 
  {
		q.type = QueryType::BusesForStop;
		in >> q.stop;
	}
	else if (text == "STOPS_FOR_BUS") 
  {
		q.type = QueryType::StopsForBus;
		in >> q.bus;
	}
	else if (text == "ALL_BUSES") 
  {
		q.type = QueryType::AllBuses;
	}
	return in;
}