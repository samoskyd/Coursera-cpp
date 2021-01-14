#include "bus_manager.h"

void BusManager::AddBus(const std::string& bus, const std::vector<std::string>& stops)
{
	buses_for_stops[bus] = stops;
	for (const auto& i : stops)
	{
		stops_for_buses[i].push_back(bus);
	}
}

BusesForStopResponse BusManager::GetBusesForStop(const std::string& stop) const
{
	if (stops_for_buses.count(stop) == 0)
	{
		return BusesForStopResponse{std::vector<std::string>()};
	}
	else
	{
		return BusesForStopResponse{stops_for_buses.at(stop)};
	}
}

StopsForBusResponse BusManager::GetStopsForBus(const std::string& bus) const
{
	std::vector<std::pair<std::string, std::vector<std::string>>> result;
	if (buses_for_stops.count(bus) > 0)
	{
		for (const auto& i : buses_for_stops.at(bus))
		{
			result.push_back(std::make_pair(i, stops_for_buses.at(i)));
		}
	}
	return StopsForBusResponse{bus, result};
}

AllBusesResponse BusManager::GetAllBuses() const
{
	return AllBusesResponse{buses_for_stops};
}
