#pragma once
#ifndef ORGANISATION_H
#define ORGANISATION_H
#include <vector>
#include <string>
#include "Schedule.h"
#include "Review.h"
#include "Restaurant.h"

using namespace std;

class Organisation
{
    public:
        string _name;
        Schedule _schedule;
        vector <Review> _reviews;
        vector <Restaurant> _restaurants;
        double _delivery_price;
        double _delivery_coefficient;
        Organisation(string name, Schedule schedule, vector <Restaurant> restaurants, double delivery_coefficient);
        double calculate_average_rating();
};

Organisation find_the_best_organisation(vector <Organisation> orgs);
bool operator == (const Organisation& org1, const Organisation& org2);

#endif