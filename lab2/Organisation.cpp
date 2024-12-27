#include "Organisation.h"
#include <cmath>

Organisation::Organisation(string name, Schedule schedule, vector <Restaurant> restaurants, double delivery_coefficient): _name(name), _schedule(schedule),_restaurants(restaurants), _delivery_coefficient(delivery_coefficient) 
{
    _reviews = {};
}
        
double Organisation::calculate_average_rating()
{
    double sum_rating = 0;
    for (int i = 0; i < _reviews.size(); i++)
        sum_rating += _reviews[i]._rating;
    return round(100*sum_rating/_reviews.size())/100;
}

Organisation find_the_best_organisation(vector <Organisation> orgs)
{
    Organisation the_best_org = orgs[0];
    for (int i = 1; i < orgs.size(); i++)
        if (orgs[i].calculate_average_rating() > the_best_org.calculate_average_rating())
            the_best_org = orgs[i];
    return the_best_org;
}

bool operator == (const Organisation& org1, const Organisation& org2) 
{
    return org1._name == org2._name and org1._schedule == org2._schedule and org1._reviews == org2._reviews and org1._restaurants == org2._restaurants and org1._delivery_price == org2._delivery_price and org1._delivery_coefficient == org2._delivery_coefficient;
}