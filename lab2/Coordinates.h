#pragma once
#ifndef COORDINATES_H
#define COORDINATES_H

class Coordinates
{
    public:
        double _latitude_degrees; 
        double _longitude_degrees; 
        Coordinates(double latitude_degrees, double longitude_degrees);
};

bool operator == (const Coordinates& coords1, const Coordinates& coords2);

#endif