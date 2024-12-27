#pragma once
#ifndef MAP_H
#define MAP_H
#include <vector>
#include "Coordinates.h"
#include <cmath>

using namespace std;

class Map
{
    public:
        vector <Coordinates> _restaurant_coords;
        Coordinates _client_coords;
        Map(vector <Coordinates> restaurant_coords, Coordinates client_coords);
        double calculate_distance(Coordinates coords1, Coordinates coords2);
        int find_the_nearest_restaurant(Coordinates coords);
};

bool operator == (const Map& map1, const Map& map2);

#endif