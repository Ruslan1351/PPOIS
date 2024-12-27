#include "Coordinates.h"

Coordinates::Coordinates(double latitude_degrees, double longitude_degrees) : _latitude_degrees(latitude_degrees), _longitude_degrees(longitude_degrees) {}

bool operator == (const Coordinates& coords1, const Coordinates& coords2) 
{
    return coords1._latitude_degrees == coords2._latitude_degrees and coords1._longitude_degrees == coords2._longitude_degrees;
}