#include "Map.h"

Map::Map(vector <Coordinates> restaurant_coords, Coordinates client_coords) : _restaurant_coords(restaurant_coords), _client_coords(client_coords) {}

double Map::calculate_distance(Coordinates coords1, Coordinates coords2)//
{
    double pi = acos(-1);
    double lat1 = coords1._latitude_degrees * pi / 180; 
    double lat2 = coords2._latitude_degrees * pi / 180; 
    double lng1 = coords1._longitude_degrees * pi / 180; 
    double lng2 = coords2._longitude_degrees * pi / 180; 
    return round(6371 * acos(cos(lat1) * cos(lat2) * cos(lng1 - lng2) + sin(lat1) * sin(lat2))*100)/100; //в км
}

int Map::find_the_nearest_restaurant(Coordinates coords)//
{
    double the_nearest_rest = calculate_distance(_restaurant_coords[0], coords);
    int index = 0;
    for (int i = 1; i < _restaurant_coords.size(); i++)
        if (calculate_distance(_restaurant_coords[i], coords) < the_nearest_rest) {
            the_nearest_rest = calculate_distance(_restaurant_coords[i], coords);
            index = i;
        }
    return index;
}

bool operator == (const Map& map1, const Map& map2)
{
    return map1._restaurant_coords == map2._restaurant_coords and map1._client_coords == map2._client_coords;
}