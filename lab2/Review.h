#pragma once
#ifndef REVIEW_H
#define REVIEW_H
#include <string>
#include "Date.h"

using namespace std;

class Review
{
    public:
        string _text;
        int _rating;
        Date _date;
        Review(string text, int rating, Date date);
};

bool operator == (const Review& review1, const Review& review2);

#endif