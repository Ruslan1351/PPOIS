#include "Review.h"

Review::Review(string text, int rating, Date date) : _text(text), _rating(rating), _date(date) {}

bool operator == (const Review& review1, const Review& review2) 
{
    return review1._text == review2._text and review1._rating == review2._rating and review1._date == review2._date;
}